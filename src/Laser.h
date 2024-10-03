#pragma once
#include "raylib.h"
#include <iostream>

class Laser{
public:
    Laser(Vector2 position, int speed);
    ~Laser();
    void draw();
    void update();
    bool active;
    Rectangle getRect();
private:
    Vector2 m_position;
    int m_speed;
};