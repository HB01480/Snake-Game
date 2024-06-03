#include "../global.hh"

#include "snake.hh"


Snake::Snake(std::deque<Vector2> body, Color color, Vector2 direction)
: body(body), color(color), direction(direction), addSegment(false)
{}

bool Snake::isInBody(Vector2 object, u16 startingIndex) {
    for (u16 i = startingIndex; i < body.size(); i++) {
        Vector2& part = body[i];
        if (Vector2Equals(part, object))
            return true;
    }
    return false;
}

bool Snake::checkCollisionWalls() {
    if (body[0].x > settings.tileCountX - 1)
        return true;
    if (body[0].x < 0)
        return true;

    if (body[0].y > settings.tileCountY - 1)
        return true;
    if (body[0].y < 0)
        return true;

    return false;
}

void Snake::addBodySegment() {
    addSegment = true;
}

void Snake::fixedMove() {
    if (!addSegment)
        body.pop_back();

    Vector2 newPart = Vector2Add(body[0], direction);
    body.push_front(newPart);
    addSegment = false;

}

void Snake::input() {
    direction = (IsKeyDown(KEY_A) && !Vector2Equals(direction, settings.directionRIGHT)) ? settings.directionLEFT : direction;
    direction = (IsKeyDown(KEY_D) && !Vector2Equals(direction, settings.directionLEFT)) ? settings.directionRIGHT : direction;
    direction = (IsKeyDown(KEY_W) && !Vector2Equals(direction, settings.directionDOWN)) ? settings.directionUP : direction;
    direction = (IsKeyDown(KEY_S) && !Vector2Equals(direction, settings.directionUP)) ? settings.directionDOWN : direction;

}

void Snake::draw() {
    for (Vector2& part : body) {
        Vector2 scaled = Vector2Scale(part, settings.tileSize);
        DrawRectangleV(scaled, Vector2{(f32)settings.tileSize, (f32)settings.tileSize}, color);
    }

}