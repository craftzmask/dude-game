#include "Goal.h"
#include <random>

Goal::Goal(Vec2 pos_in)
{
	Respawn(pos_in);
}

void Goal::Draw(Graphics& gfx) const
{
	gfx.DrawRectDim(int(pos.x), int(pos.y), int(width), int(height), c);
}

void Goal::Respawn(const Vec2 pos_in)
{
	pos = pos_in;
}

bool Goal::TestCollision(const Dude& dude) const
{
	const float goalRight = pos.x + width;
	const float goalBottom = pos.y + height;
	const float dudeRight = dude.GetPos().x + dude.GetWidth();
	const float dudeBottom = dude.GetPos().y + dude.GetHeight();

	return
		dude.GetPos().x <= goalRight &&
		dudeRight >= pos.x &&
		dudeBottom >= pos.y &&
		dude.GetPos().y <= goalBottom;
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
