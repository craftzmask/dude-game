#pragma once

#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal(const Vec2 pos_in);
	void Draw(Graphics& gfx) const;
	void Respawn(const Vec2 pos_in);
	bool TestCollision(const Dude& dude) const;
	void UpdateColor();
private:
	Vec2 pos;
	Color c = { 127, 0, 0 };
	bool colorIncreasing = true;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};