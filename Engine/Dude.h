#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Update(const Keyboard& kbd);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	int x = 400;
	int y = 300;
	int speed = 2;
	static constexpr int width = 20;
	static constexpr int height = 20;
};