#pragma once

#include "Layer.hpp"
#include "BlendMode.hpp"

class Project
{
	const char* name;
	Layer* first;
	Layer* current;
public:
	Project(const char* name, Layer* first = NULL) :name(name), first(first), current(first) {}
	~Project();
	void NewLayer(Layer* layer);
	Layer* FindLayer(const char* name);
	
	void Render(const char* FileName = NULL);
};

