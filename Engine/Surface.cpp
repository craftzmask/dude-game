#include "Surface.h"
#include "ChiliWin.h"
#include <assert.h>
#include <fstream>

Surface::Surface(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);

	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	file.seekg(bmFileHeader.bfOffBits);

	int yStart;
	int yEnd;
	int dy;
	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;
		yStart = 0;
		yEnd = height - 1;
		dy = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}

	width = bmInfoHeader.biWidth;
	pPixels = new Color[width * height];

	const bool is32b = bmInfoHeader.biBitCount == 32;
	const int cols = bmInfoHeader.biBitCount / 8;
	const int padding = (4 - (width * cols) % 4) % 4;

	for (int y = yStart; y != yEnd; y += dy)
	{
		for (int x = 0; x < width; x++)
		{
			const unsigned char b = file.get();
			const unsigned char g = file.get();
			const unsigned char r = file.get();
			PutPixel(x, y, { r, g, b });

			if (is32b)
			{
				file.get();
			}
		}

		file.seekg(padding, std::ios::cur);
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

Surface::Surface(const Surface& resource)
	:
	Surface(resource.width, resource.height)
{
	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = resource.pPixels[i];
	}
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

Surface& Surface::operator=(const Surface& rhs)
{
	const int width = rhs.width;
	const int height = rhs.height;

	delete[] pPixels;
	pPixels = new Color[width * height];
	
	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixels[y * width + x] = c;
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

RectI Surface::GetRect() const
{
	return { 0, width, 0, height };
}
