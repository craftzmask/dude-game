#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Vec2.h"

class Dude
{
public:
	void Update(const Keyboard& kbd, float dt);
	void Update(const Mouse& mouse, float dt);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	Vec2 GetPos() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	Vec2 pos = { 400.0f, 300.0f };
	static constexpr float speed = 120.0f; // 120 pixels per second
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};