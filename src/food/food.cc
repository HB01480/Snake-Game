#include "../global.hh"

#include "food.hh"


Food::Food(f32 x, f32 y, Color color)
: position({x, y}), size({TILE_SIZE, TILE_SIZE}), color(color)
{}

void Food::draw() {
    Vector2 scaled = Vector2Scale(position, TILE_SIZE);
    DrawRectangleV(scaled, size, color);
}
