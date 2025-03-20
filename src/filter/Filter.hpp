#pragma once

#include "../Image.hpp"

class Filter
{
protected:
	bool isActive;
	const char* name;
public:
	Filter(bool isActive = true, const char* name = "filter") :isActive(isActive), name(name) {}
	Filter(const Filter& filter) :Filter(filter.isActive) {}
	virtual ~Filter();

	const char* GetName() const { return name; }

	Filter& operator=(const Filter& filter);
	virtual void Apply(Image& img, const Image& original) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Filter& filter);

class GrayScale : public Filter
{
public:
	GrayScale(bool isActive = true) :Filter(isActive, "grayscale") {}
	~GrayScale() { }
	void Apply(Image& img, const Image& original) const;
};

class Brightness : public Filter
{
	float value;
	
public:
	Brightness(float value, bool isActive = true) :Filter(isActive, "brightness"), value(value) {}
	~Brightness() { }
	void Apply(Image& img, const Image& original) const;
};

class Color : public Filter
{
public:
	~Color() { }
	void Apply(Image& img, const Image& original, const Pixel p) const;
};


class Invert : public Filter
{
public:
	~Invert() { }
	void Apply(Image& img, const Image& original) const;
};

class Saturate : public Filter
{
	float value;
public:
	Saturate(float value, bool isActive = true) :Filter(isActive, "saturate"), value(value) {}
	~Saturate() { }
	void Apply(Image& img, const Image& original) const;
};

class BetterGrayScale : public Filter
{
public:
	~BetterGrayScale() { }
	void Apply(Image& img, const Image& original) const;
};

