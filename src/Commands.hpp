#pragma once

#include "Project.hpp"

class Command
{
public:
};

class Commands {
	size_t size;
	Command* commands;
public:
	Commands() :size(0), commands(NULL) {}
	~Commands();
	size_t getSize() const { return size; }
	void AddCommand(const Command& command, size_t pos);
	const Command& operator[](size_t i) const;
};

std::ostream& operator<<(std::ostream& os, const Commands& commands);

class NewLayer : public Command
{
public:
	NewLayer(Project* project, const char* LayerName, const char* FileName = NULL);
};

class NewFilter : public Command
{
public:
	NewFilter(Project* project, const char* LayerName, const std::string FilterName, int place, float value);
};

class NewBlendMode : public Command
{
public:
	NewBlendMode(Project* project, const char* LayerName, const std::string ModeName, float treshold);
};

