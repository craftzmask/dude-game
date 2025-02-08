#pragma once

#include "Colors.h"
#include "RectI.h"
#include <string>

class Surface
{
public:
	Surface(const std::string& filename);
	Surface(int width, int height);
	Surface(const Surface& resource);
	~Surface();
	Surface& operator=(const Surface& rhs);
	void PutPixel(int x, int y, Color c);
	int GetWidth() const;
	int GetHeight() const;
	Color GetPixel(int x, int y) const;
	RectI GetRect() const;
private:
	int width;
	int height;
	Color* pPixels = nullptr;
};