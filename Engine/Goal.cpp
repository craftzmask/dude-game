#include "Goal.h"
#include <random>

Goal::Goal(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, width, height, c);
}

void Goal::Respawn(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

bool Goal::TestCollision(const Dude& dude) const
{
	const int goalRight = x + width;
	const int goalBottom = y + height;
	const int dudeRight = dude.GetX() + dude.GetWidth();
	const int dudeBottom = dude.GetY() + dude.GetHeight();

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
