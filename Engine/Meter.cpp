#include "Meter.h"

Meter::Meter(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
	level = 0;
}

void Meter::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(x, y, level * scale, grith, Colors::Blue);
}

void Meter::IncreaseLevel()
{
	++level;
}
