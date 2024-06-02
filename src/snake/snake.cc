#include "../global.hh"

#include "snake.hh"


Snake::Snake(std::deque<Vector2> body, Color color, Vector2 direction)
: body(body), color(color), direction(direction)
{}
bool Snake::isInBody(Vector2 object) {}
void Snake::fixedUpdate() {}
void Snake::update() {}
void Snake::draw() {
    for (Vector2& part : body) {
        Vector2 scaled = Vector2Scale(part, TILE_SIZE);
        DrawRectangleV(scaled, Vector2{TILE_SIZE, TILE_SIZE}, color);
    }
}
