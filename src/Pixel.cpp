#include "Pixel.hpp"


Pixel Pixel::operator+(const Pixel& p1) 
{
	 Pixel res = Pixel(this->R + p1.R, this->G + p1.G, this->B + p1.B);
	 return res;
}

Pixel Pixel::operator*(const Pixel& p1)
{
	Pixel res = Pixel(this->R * p1.R / 255, this->G * p1.G / 255, this->B * p1.B / 255);
	return res;
}

Pixel& Pixel::operator=(const Pixel& p1)
{
	if (this != &p1)
	{
		R = p1.R;
		G = p1.G;
		B = p1.B;
	}
	return *this;
}

void Pixel::normal()
{
	if (R - '0' > 255) R = 255;
	if (G - '0' > 255) G = 255;
	if (B - '0' > 255) B = 255;
	if (R - '0' < 0) R = 0 + '0';
	if (G - '0' < 0) G = 0 + '0';
	if (B - '0' < 0) B = 0 + '0';
}

