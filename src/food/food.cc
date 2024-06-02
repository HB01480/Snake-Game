#include "../global.hh"

#include "food.hh"


Food::Food(f32 x, f32 y, Color color)
: position({x, y}), size({TILE_SIZE, TILE_SIZE}), color(color)
{}

void Food::reset() {
    f32 x = GetRandomValue(0, TILE_COUNT_X - 1);
    f32 y = GetRandomValue(0, TILE_COUNT_Y - 1);
    
    position = Vector2{x, y};
}

void Food::draw() {
    Vector2 scaled = Vector2Scale(position, TILE_SIZE);
    DrawRectangleV(scaled, size, color);
}
