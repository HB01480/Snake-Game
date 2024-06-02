#pragma once
#include "../global.hh"


class Snake {
public:
    Snake(std::deque<Vector2> body, Color color, Vector2 direction);

    bool isInBody(Vector2 object, u16 startingIndex = 0);
    bool checkCollisionWalls();
    void fixedMove();
    void input();

    Vector2 getHeadPosition() { return body[0]; }
    i32 getSize() { return body.size(); }
    void addBodySegment();

    void draw();

private:
    std::deque<Vector2> body;
    Color color;
    Vector2 direction;
    bool addSegment;

};
