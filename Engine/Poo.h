#pragma once
#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"
#include "Surface.h"

class Poo
{
public:
	Poo(const Vec2 pos, const Vec2 vel, const Surface& s);
	void Update(float dt);
	bool TestCollision(const Dude& dude) const;
	void Draw(Graphics& gfx) const;
private:
	const Surface& s;
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24.0f;
	static constexpr float height = 24.0f;
	bool isEaten = false;
};