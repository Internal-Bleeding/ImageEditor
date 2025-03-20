#pragma once

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION


#include "Pixel.hpp"
#include <iostream>

class Image
{
protected:
	int sizeX;
	int sizeY;
	int channels;
public:
	Pixel** pixels;

	Image(int sizeX = 0, int sizeY = 0, int channels = 3);
	Image(const Image& img);
	Image(const char* FileName);

	int GetX() const { return sizeX; }
	int GetY() const { return sizeY; }
	int GetChannels() const { return channels; }

	Image& operator=(const Image& img);

	void Normalize();
	void Export(const char* FileName) const;
	~Image();
};

std::ostream& operator<<(std::ostream& os, const Image& img);


