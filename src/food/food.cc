#include "../global.hh"

#include "food.hh"


Food::Food(f32 x, f32 y, Color color)
: position({x, y}), size({(f32)settings.tileSize, (f32)settings.tileSize}), color(color)
{}

void Food::reset() {
    f32 x = GetRandomValue(0, settings.tileCountX - 1);
    f32 y = GetRandomValue(0, settings.tileCountY - 1);
    
    position = Vector2{x, y};
}

void Food::draw() {
    Vector2 scaled = Vector2Scale(position, settings.tileSize);
    DrawRectangleV(scaled, size, color);
}
