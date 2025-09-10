# pragma once

/**
 * @struct Vector2
 * @brief A simple 2D vector class with basic operations
*/
struct Vector2 {
    const float x;
    const float y;

    Vector2(float x, float y);
    ~Vector2();

    Vector2(const Vector2& other);
};