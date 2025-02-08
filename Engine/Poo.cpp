#include "Poo.h"

Poo::Poo(const Vec2 pos, const Vec2 vel, const Surface& s)
	:
	pos(pos),
	vel(vel),
	s(s)
{
}

void Poo::Update(float dt)
{
	pos += vel * dt;

	const float right = pos.x + width;
	if (pos.x < 0)
	{
		pos.x = 0.0f;
		vel.x = -vel.x;
	}
	else if (right >= float(Graphics::ScreenWidth))
	{
		pos.x = float(Graphics::ScreenWidth - 1) - width;
		vel.x = -vel.x;
	}

	const float bottom = pos.y + height;
	if (pos.y < 0)
	{
		pos.y = 0.0f;
		vel.y = -vel.y;
	}
	else if (bottom >= float(Graphics::ScreenHeight))
	{
		pos.y = float(Graphics::ScreenHeight - 1) - height;
		vel.y = -vel.y;
	}
}

bool Poo::TestCollision(const Dude& dude) const
{
	const float pooRight = pos.x + width;
	const float pooBottom = pos.y + height;
	const float dudeRight = dude.GetPos().x + dude.GetWidth();
	const float dudeBottom = dude.GetPos().y + dude.GetHeight();

	return
		dude.GetPos().x <= pooRight &&
		dudeRight >= pos.x &&
		dudeBottom >= pos.y &&
		dude.GetPos().y <= pooBottom;
}

void Poo::Draw(Graphics& gfx) const
{
	gfx.DrawSprite(int(pos.x), int(pos.y), s, Colors::White);
}