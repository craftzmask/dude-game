#pragma once

#include "Graphics.h"

class Meter
{
public:
	Meter(int in_x, int in_y);
	void Draw(Graphics& gfx) const;
	void IncreaseLevel();
private:
	int x;
	int y;
	int level = 0;
	static constexpr int scale = 5;
	static constexpr int grith = 12;
};