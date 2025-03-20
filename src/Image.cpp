#include <fstream>
#include <iostream>

#include "Image.hpp"

#include "stb_image.h"
#include "stb_image_write.h"

/// @brief konstruktor chanelek szamatol es merettol fuggoen
/// @param sizeX 
/// @param sizeY 
/// @param channels 
Image::Image(int sizeX, int sizeY, int channels) : sizeX(sizeX), sizeY(sizeY), channels(channels)
{
	if (channels == 4)
	{
		pixels = new Pixel * [sizeX]; //Problem??
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new PixelA[sizeY];
		}
	}
	else
	{
		pixels = new Pixel * [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new Pixel[sizeY];
		}
	}
}
/// @brief copy konstruktor chanelek szamatol fuggoen
/// @param img kep
Image::Image(const Image& img)
{
	channels = img.channels;
	sizeX = img.sizeX;
	sizeY = img.sizeY;

	if (channels == 4)
	{
		pixels = new Pixel * [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new PixelA[sizeY];
		}
	}
	else if (channels == 3)
	{
		pixels = new Pixel * [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new Pixel[sizeY];
		}
	}

	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			pixels[x][y] = img.pixels[x][y];
		}
	}
}
/// @brief imports image by filename
/// @param FileName: name of the file
Image::Image(const char* FileName)
{
	unsigned char* img = stbi_load(FileName, &sizeY, &sizeX, &channels, 0);
	
	if (img == NULL)
	{
		sizeX = 0;
		sizeY = 0;
		channels = 0;
		throw "ERROR No such file found";
	}
	if (channels == 4)
	{
		pixels = new Pixel* [sizeX]; //Problem??
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new PixelA[sizeY];
		}
	}
	else if (channels == 3) 
	{
		pixels = new Pixel * [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			pixels[i] = new Pixel[sizeY];
		}
	}
	int n = 0;
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			pixels[x][y].SetR(img[n]);
			pixels[x][y].SetG(img[n+1]);
			pixels[x][y].SetB(img[n+2]);
			n += 3;
		}
	}
}

/// @brief x, y merete �s channelek szamanak kiirasa ostreamre 
/// @param os 
/// @param img 
/// @return 
std::ostream& operator<<(std::ostream& os, const Image& img)
{
	os << "x: " << img.GetY() << " y: " << img.GetX() << " channels: " << img.GetChannels();
	return os;
}

/// @brief pixelek, x, y meret torlese
Image::~Image()
{
	for (int n = 0; n < sizeX; n++) {
		delete[] pixels[n];
	}
	delete[] pixels;
	channels = 0;
	sizeX = 0;
	sizeY = 0;

}

/// @brief copy chanelek szamatol fuggoen
/// @param img 
/// @return 
Image& Image::operator=(const Image& img)
{
	if (&img != this) 
	{
		if (pixels != NULL)
		{
			for (int n = 0; n < sizeX; n++) {
				delete[] pixels[n];
			}
			delete[] pixels;
		}
		channels = img.channels;
		sizeX = img.sizeX;
		sizeY = img.sizeY;

		if (channels == 4)
		{
			pixels = new Pixel * [sizeX]; //Problem??
			for (int i = 0; i < sizeX; i++)
			{
				pixels[i] = new PixelA[sizeY];
			}
		}
		if (channels == 3)
		{
			pixels = new Pixel * [sizeX];
			for (int i = 0; i < sizeX; i++)
			{
				pixels[i] = new Pixel[sizeY];
			}
		}
		else
		{
			return *this;
		}

		for (int x = 0; x < sizeX; x++)
		{
			for (int y = 0; y < sizeY; y++)
			{
				pixels[x][y] = img.pixels[x][y];
			}
		}
	}
	return *this;
}

/// @brief normalizal minden pixelt
void Image::Normalize()
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			pixels[x][y].normal();
		}
	}
}

/// @brief Kep exportalasa
/// @param FileName fajl neve
void Image::Export(const char* FileName) const
{
	unsigned char* img = new unsigned char[sizeX * sizeY * channels];
	int n = 0;
	std::cout << "Exported";
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			img[n] = pixels[x][y].GetR();
			img[n + 1] = pixels[x][y].GetG();
			img[n + 2] = pixels[x][y].GetB();
			n += 3;
		}
	}
	stbi_write_jpg(FileName, sizeY, sizeX, channels, img, 100);
	delete[] img;
}