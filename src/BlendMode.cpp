#include "BlendMode.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const BlendMode& blendMode) 
{
	os << char(195) << "BlendMode:" << blendMode.GetName() << std::endl;
	return os;
}

BlendMode& BlendMode::operator= (const BlendMode& mode) 
{
	if (&mode != this)
	{
		inUse = mode.inUse;
	}
	return *this;
}

/// @brief 
/// @param top 
/// @param bottom 
/// @return 
void Normal::Mix(Image& top, const Image& bottom) const
{
	int sizeX = top.GetX();
	int sizeY = top.GetY();

	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (x < bottom.GetX() && y < bottom.GetY())
			{
				int r = bottom.pixels[x][y].GetR();
				int g = bottom.pixels[x][y].GetG();
				int b = bottom.pixels[x][y].GetB();

				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
				if (r < 0) r = 0;
				if (g < 0) g = 0;
				if (b < 0) b = 0;
				top.pixels[x][y] = Pixel(r, g, b);
			}
		}
	}
}

void Multiply::Mix(Image& top, const Image& bottom) const
{
	int sizeX = top.GetX();
	int sizeY = top.GetY();

	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (x < bottom.GetX() && y < bottom.GetY())
			{
				int r = bottom.pixels[x][y].GetR() * top.pixels[x][y].GetR() / 255;
				int g = bottom.pixels[x][y].GetG() * top.pixels[x][y].GetG() / 255;
				int b = bottom.pixels[x][y].GetB() * top.pixels[x][y].GetB() / 255;

				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
				if (r < 0) r = 0;
				if (g < 0) g = 0;
				if (b < 0) b = 0;
				top.pixels[x][y] = Pixel(r, g, b);
			}
		}
	}
}