#include "../global.hh"

#include "snake.hh"


Snake::Snake(std::deque<Vector2> body, Color color, Vector2 direction)
: body(body), color(color), direction(direction), addSegment(false)
{}
bool Snake::isInBody(Vector2 object) {
    for (Vector2& part : body) {
        if (Vector2Equals(part, object))
            return true;
    }
    return false;
}
void Snake::addBodySegment() {
    addSegment = true;
}
void Snake::fixedUpdate() {
    if (!addSegment)
        body.pop_back();

    Vector2 newPart = Vector2Add(body[0], direction);
    body.push_front(newPart);
    addSegment = false;

}
void Snake::update() {
    direction = (IsKeyDown(KEY_A) && !Vector2Equals(direction, DIR_RIGHT)) ? DIR_LEFT : direction;
    direction = (IsKeyDown(KEY_D) && !Vector2Equals(direction, DIR_LEFT)) ? DIR_RIGHT : direction;
    direction = (IsKeyDown(KEY_W) && !Vector2Equals(direction, DIR_DOWN)) ? DIR_UP : direction;
    direction = (IsKeyDown(KEY_S) && !Vector2Equals(direction, DIR_UP)) ? DIR_DOWN : direction;

}
void Snake::draw() {
    for (Vector2& part : body) {
        Vector2 scaled = Vector2Scale(part, TILE_SIZE);
        DrawRectangleV(scaled, Vector2{TILE_SIZE, TILE_SIZE}, color);
    }

}
