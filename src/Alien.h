#pragma once
#include <raylib.h>

class Alien{
public:
    Alien(int type, Vector2 position);
    void draw();
    void update(int direction);
    int getType();
    static void unloadImages();
    static Texture2D alienImages[3];
    int m_type;
    Vector2 m_position;
    Rectangle getRect();
};