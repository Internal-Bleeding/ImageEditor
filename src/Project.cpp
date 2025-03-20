#include "Project.hpp"

#include <iostream>

Project::~Project()
{
	//Nem kell semmi
}
void Project::Render(const char* FileName)
{
	if (first != NULL) 
	{
		std::cout << "Project: " << name << std::endl;
		Layer* temp = first;
		Layer* old = NULL;
		while (temp->next != NULL)
		{
			std::cout << " " << char(195) << *temp;
			if (old != NULL)
			temp->Render(*old);
			old = temp;
			temp = temp->next;
		}
		std::cout << " " << char(192) << *temp;
		if (old != NULL)
			temp->Render(*old);
		if (FileName != NULL)
			temp->Export(FileName);
	}
	std::cout << std::endl;
	//write all current commands:

}

Layer* Project::FindLayer(const char* name) 
{
	Layer* temp = first;
	std::string Name = name;
	while (temp != NULL)
	{
		std::string layerName = temp->GetName();
		if (layerName == Name)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void Project::NewLayer(Layer* layer)
{
	if (current != NULL)
	{
		current->next = layer;
		current = current->next;
	}
	else
	{
		first = layer;
		current = layer;
	}

}