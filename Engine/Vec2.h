#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
	Vec2 operator*(float factor) const;
	Vec2& operator*=(float factor);
	float GetLength() const;
	float GetLengthSq() const;
	Vec2 GetNormalize() const;
	Vec2& Normalize();
public:
	float x;
	float y;
};