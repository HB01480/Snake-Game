#pragma once
#include "../global.hh"


class Snake {
public:
    Snake(std::deque<Vector2> body, Color color, Vector2 direction);
    bool isInBody(Vector2 object);
    void addBodySegment();
    void fixedUpdate();
    void update();
    void draw();

private:
    std::deque<Vector2> body;
    Color color;
    Vector2 direction;
    bool addSegment;

};
