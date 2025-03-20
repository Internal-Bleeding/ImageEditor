#pragma once

#include "Image.hpp"
#include "Pixel.hpp"

class BlendMode
{
protected:
	float treshold;
	bool inUse;
	const char* name;
public:
	BlendMode(float treshold = 0, bool inUse = false, const char* name = "blendmode") :treshold(treshold), inUse(inUse), name(name) {}
	virtual ~BlendMode() {};
	void SetUse(bool Use) { inUse = Use; }
	const char* GetName() const { return name; }
	virtual void Mix(Image& top, const Image& bottom) const = 0;

	BlendMode& operator=(const BlendMode& mode);
};

std::ostream& operator<<(std::ostream& os, const BlendMode& blendMode);


class Normal : public BlendMode
{
public:
	Normal(float treshold, bool inUse) :BlendMode(treshold, inUse, "Normal") {}
	Normal(const Normal& mode) :BlendMode(mode) {}
	~Normal() {}
	void Mix(Image& top, const Image& bottom) const override;
};

class Multiply : public BlendMode
{
public:
	Multiply(float treshold, bool inUse) :BlendMode(treshold, inUse, "Multiply") {}
	Multiply(const Normal& mode) :BlendMode(mode) {}
	~Multiply() {}
	void Mix(Image& top, const Image& bottom) const override;
};

