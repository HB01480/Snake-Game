#pragma once
#include "../global.hh"


class Food {
public:
    Food(f32 x, f32 y, Color color);
    Vector2 getPosition() { return position; }
    void reset();
    void draw();

private:
    Vector2 position;
    Vector2 size;
    Color color;

};
