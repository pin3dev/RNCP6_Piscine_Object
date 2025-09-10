# include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::~Vector2() {}
Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y) {}
