#include "Layer.hpp"
#include <string.h>
#include <iostream>

Layer::Layer(std::string name, BlendMode* mode) :name(name), mode(mode)
{
	next = NULL;
	filters = new Filter*[FilterSize];
}

Layer::Layer(const Layer& layer) : mode(layer.mode), original(layer.original), current(layer.current), next(layer.next)
{
	name = layer.name;
	filters = new Filter * [layer.FilterSize];
	FilterSize = layer.FilterSize;
	for (size_t n = 0; n < FilterSize; n++)
	{
		filters[n] = new Brightness(1.0f);
		filters[n] = layer.filters[n];
		std::cout << filters[n] << std::endl;
	}
}

Layer::~Layer()
{
	name.clear();
	std::cout << FilterSize;
	for (size_t i = 0; i < FilterSize; i++)
	{
		delete filters[i];
	}
	delete[] filters;
	delete mode;
}

/// @brief Kepet importal a fajlnev alapjan 
/// @param FileName: name of the file to import
void Layer::AddImage(const char* FileName)
{
	original = Image(FileName);
	current = original;
}

void Layer::MoveFilter(size_t from, size_t to) 
{
	current = original;
}

void Layer::AddBlendMode(BlendMode* blendmode) 
{
	mode = blendmode;
}

void Layer::AddFilter(Filter* filter, int pos)
{
	if (pos < 0) {
		throw "pos smaller than 0";
	}
	else if (FilterSize <= (size_t)pos)
	{
		//Filter** temp = new Filter * [FilterSize];
		Filter** temp = new Filter * [FilterSize + 1];
		for (size_t n = 0; n < FilterSize; n++)
		{
			temp[n] = filters[n];
		}
		temp[FilterSize] = filter;
		//filters = new Filter* [FilterSize + 1];
		//for (size_t n = 0; n < FilterSize; n++)
		//{
		//	filters[n] = temp[n];
		//}
		delete[] filters;
		filters = temp;
		//filters[FilterSize] = filter;
		//delete[] temp;
	}
	else
	{
		filters[pos] = filter;
	}
	FilterSize++;
}

/// @brief Apply all filters and render layer
/// @param FileName: name of the exported file
void Layer::Render(const Layer& bottom)
{
	for (size_t n = 0; n < FilterSize; n++)
	{
		if (filters[n] != NULL)
			filters[n]->Apply(current, current);
		if (&bottom != NULL && mode != NULL)
			mode->Mix(current, bottom.current);
	}
}

void Layer::Export(const char* FileName) const
{
	current.Export(FileName);
}

std::ostream& operator<<(std::ostream& os, const Layer& layer)
{
	os <<"Layer: " << layer.GetName() << " " << layer.GetOriginal() << std::endl;
	
	
	if (layer.next != NULL)
	{
		if (layer.mode != NULL)
		{
			os << " " << char(179) << " " << *layer.mode;
			os << " " << char(179) << " " << char(179) << std::endl;
		}
		int n = 0;
		for (n = 0; n < int(layer.GetSize() - 1); n++) //size_t is an unsigned type, int is necessary
		{
			os << " " << char(179) << " " << char(195) << *layer.filters[n];
		}
		if (layer.GetSize() > 0)
			os << " " << char(179) << " " << char(192) << *layer.filters[n];
		os << " " << char(179) << std::endl;
	}
	else
	{
		if (layer.mode != NULL)
		{
			os << "   " << *layer.mode;
			os << "   " << char(179) << std::endl;
		}
		int n = 0;
		for (n = 0; n < int(layer.GetSize() - 1); n++) //size_t is an unsigned type, int is necessary
		{
			os << "   " << char(195) << *layer.filters[n];
		}
		if (layer.GetSize() > 0)
			os << "   " << char(192) << *layer.filters[n];
	}
	
	return os;
}

