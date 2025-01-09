#pragma once

#include "Dude.h"

class Goal
{
public:
	Goal(int in_x, int in_y);
	void Draw(Graphics& gfx);
	void Respawn(int in_x, int in_y);
	bool TestCollision(const Dude& dude) const;
	void UpdateColor();
private:
	int x;
	int y;
	Color c = { 127, 0, 0 };
	bool colorIncreasing = true;
	static constexpr int width = 20;
	static constexpr int height = 20;
};