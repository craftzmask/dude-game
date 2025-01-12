#include "Goal.h"
#include <random>

Goal::Goal(float in_x, float in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(int(x), int(y), int(width), int(height), c);
}

void Goal::Respawn(float in_x, float in_y)
{
	x = in_x;
	y = in_y;
}

bool Goal::TestCollision(const Dude& dude) const
{
	const float goalRight = x + width;
	const float goalBottom = y + height;
	const float dudeRight = dude.GetX() + dude.GetWidth();
	const float dudeBottom = dude.GetY() + dude.GetHeight();

	return
		dude.GetX() <= goalRight &&
		dudeRight >= x &&
		dudeBottom >= y &&
		dude.GetY() <= goalBottom;
}

void Goal::UpdateColor()
{
	if (colorIncreasing)
	{
		if (c.GetR() >= 253)
		{
			colorIncreasing = false;
		}
		else
		{
			c = Color(c.GetR() + 2, c.GetG() + 4, c.GetB() + 4);
		}
	}
	else
	{
		if (c.GetR() <= 127)
		{
			colorIncreasing = true;
		}
		else
		{
			c = Color(c.GetR() - 2, c.GetG() - 4, c.GetB() - 4);
		}
	}
}
