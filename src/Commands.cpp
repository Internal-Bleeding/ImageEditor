#include "Commands.hpp"
#include "Layer.hpp"
#include "BlendMode.hpp"

std::ostream& operator<<(std::ostream& os, const Command& command)
{
	os << "command";
	return os;
}

std::ostream& operator<<(std::ostream& os, const NewLayer& command)
{
	os << "new layer";
	return os;
}

Commands::~Commands() {
	delete[] commands;
}

void Commands::AddCommand(const Command& command, size_t pos)
{
	if (pos >= size)
	{
		Command* temp = new Command [size];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = commands[i];
		}
		commands = new Command [size + 1];
		for (size_t i = 0; i < size + 1; i++)
		{
			commands[i] = temp[i];
		}
		delete[] temp;
		size++;
	}
}

const Command& Commands::operator[](size_t i) const
{
	if (i < size) {
		return commands[i];
	}
	else
	{
		return commands[0];
	}
}

std::ostream& operator<<(std::ostream& os, const Commands& commands)
{
	for (size_t n = 0; n < commands.getSize(); n++)
	{
		if (&commands[n] != NULL)
		{
			os << n << " " << commands[n] << std::endl;
		}
	}
	return os;
}

NewLayer::NewLayer(Project* project, const char* LayerName, const char* FileName)
{
	Layer* test = project->FindLayer(LayerName);
	if (test != NULL) {
		throw "ERROR Layername already initialized";
	}
	Layer *layer = new Layer(LayerName);
	if (FileName != NULL)
		layer->AddImage(FileName);
	project->NewLayer(layer);
}

NewFilter::NewFilter(Project* project, const char* LayerName, const std::string FilterName, int place, float value)
{
	Layer* layer = project->FindLayer(LayerName);
	if (layer == NULL)
	{
		throw "ERROR There is no such layer";
	}
	Filter* filter;

	if (FilterName == "GrayScale")
	{
		filter = new GrayScale(true);
		layer->AddFilter(filter, place);
	}
	else if (FilterName == "Brightness")
	{
		filter = new Brightness(value);
		layer->AddFilter(filter, place);
	}
	else if (FilterName == "Saturate")
	{
		filter = new Saturate(value);
		layer->AddFilter(filter, place);
	}
	else
	{
		throw "ERROR No such filter exists";
	}
}

NewBlendMode::NewBlendMode(Project* project, const char* LayerName, const std::string ModeName, float treshold) 
{
	Layer* layer = project->FindLayer(LayerName);
	BlendMode* mode;
	if (ModeName == "Multiply")
	{
		mode = new Multiply(treshold, true);
		layer->AddBlendMode(mode);
	}
	else if (ModeName == "Normal")
	{
		mode = new Normal(treshold, true);
		layer->AddBlendMode(mode);
	}
	else
	{
		throw "ERROR No such blending mode exists";
	}
}