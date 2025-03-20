#pragma once

#include <string>

#include "BlendMode.hpp"
#include "Image.hpp"
#include "filter/Filter.hpp"

class Layer
{
protected:
	std::string name;
	size_t FilterSize = 0;
	Filter** filters;
	BlendMode* mode;
	Image original;
	Image current;

public:

	Layer* next;

	Layer(const std::string name, BlendMode* mode = NULL);
	Layer(const Layer& layer);
	~Layer();

	std::string GetName() const { return name; }
	size_t GetSize() const { return FilterSize; }
	const Image& GetOriginal() const { return original; }

	void AddImage(const char* FileName);
	void AddBlendMode(BlendMode* mode);
	void AddFilter(Filter* filter, int pos);
	void MoveFilter(size_t from, size_t to);
	void Render(const Layer& bottom);
	void Export(const char* FileName) const;
	friend std::ostream& operator<<(std::ostream& os, const Layer& layer);
};


