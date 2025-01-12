#pragma once

#include "Dude.h"

class Goal
{
public:
	Goal(float in_x, float in_y);
	void Draw(Graphics& gfx);
	void Respawn(float in_x, float in_y);
	bool TestCollision(const Dude& dude) const;
	void UpdateColor();
private:
	float x;
	float y;
	Color c = { 127, 0, 0 };
	bool colorIncreasing = true;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};