#include "Dude.h"

Dude::Dude(const Surface& s)
	:
	s(s)
{
}

void Dude::Update(const Keyboard& kbd, float dt)
{
	Vec2 vel = { 0.0f, 0.0f };

	if (kbd.KeyIsPressed(VK_UP))
	{
		vel.y += -1.0f;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		vel.y += 1.0f;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x += -1.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x += 1.0f;
	}

	pos += vel.GetNormalize() * speed * dt;

	ClampToScreen();
}

void Dude::Update(const Mouse& mouse, float dt)
{
	Vec2 vel = { 0.0f, 0.0f };
	if (mouse.LeftIsPressed())
	{
		Vec2 center = pos + Vec2(width / 2.0f, height / 2.0f);
		Vec2 mousePos = Vec2(float(mouse.GetPosX()), float(mouse.GetPosY()));
		Vec2 toPointer = mousePos - center;

		// dude will teleport to the exact cursor
		// position when the length is too small
		// Otherwise, dude will be vibrating
		if (toPointer.GetLength() < speed * dt)
		{
			pos = mousePos - Vec2(width / 2.0f, height / 2.0f);
		}
		else
		{
			pos += toPointer.GetNormalize() * speed * dt;
		}
	}
}

void Dude::ClampToScreen()
{
	const float right = pos.x + width;
	if (pos.x < 0)
	{
		pos.x = 0;
	}
	else if (right >= float(Graphics::ScreenWidth))
	{
		pos.x = float(Graphics::ScreenWidth - 1) - width;
	}

	const float bottom = pos.y + height;
	if (pos.y < 0)
	{
		pos.y = 0;
	}
	else if (bottom >= float(Graphics::ScreenHeight))
	{
		pos.y = float(Graphics::ScreenHeight - 1) - height;
	}
}

void Dude::Draw(Graphics& gfx) const
{
	gfx.DrawSprite(int(pos.x), int(pos.y), s);
}

Vec2 Dude::GetPos() const
{
	return pos;
}

float Dude::GetWidth() const
{
	return width;
}

float Dude::GetHeight() const
{
	return height;
}


