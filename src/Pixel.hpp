#pragma once

#define uchar unsigned char

class Pixel
{
protected:
	uchar R;
	uchar G;
	uchar B;
public:

	Pixel(uchar R = 255, uchar G = 255, uchar B = 255) :R(R), G(G), B(B) {}
	Pixel(const Pixel& p1) :R(p1.R), G(p1.G), B(p1.B) {}

	uchar GetR() const { return R; }
	uchar GetG() const { return G; }
	uchar GetB() const { return B; }

	void SetR(const uchar r) { R = r; }
	void SetG(const uchar g) { G = g; }
	void SetB(const uchar b) { B = b; }

	Pixel operator+(const Pixel& p1);
	Pixel& operator=(const Pixel& p1);
	Pixel operator*(const Pixel& p1);

	void normal();
};

class PixelA : public Pixel
{
	uchar A;
public:
	PixelA(uchar R = 255, uchar G = 255, uchar B = 255, uchar A = 255) :Pixel(R, G, B), A(A) {}
	PixelA(const Pixel& p1, uchar A = 255) :Pixel(p1), A(A) {}
};

