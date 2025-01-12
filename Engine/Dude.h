#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Update(const Keyboard& kbd, float dt);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	float x = 400.0f;
	float y = 300.0f;
	float speed = 2.0f * 60.0f;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};