#include "Laser.h"

Laser::Laser(Vector2 position, int speed){
    m_position=position;
    m_speed=speed;
    active=true;
}

Laser::~Laser()
{
}

void Laser::draw(){
    if (active){
        DrawRectangle(m_position.x, m_position.y, 4, 15, {243,216,53,255});
    }
}

void Laser::update(){
    m_position.y+=m_speed;
    if (active){
        if (m_position.y>GetScreenHeight() || m_position.y<0){
            active=false;
            // std::cout << "Laser inactive!" << "\n";
        }
    }
}

Rectangle Laser::getRect()
{
    Rectangle rect;
    rect.x=m_position.x;
    rect.y=m_position.y;
    rect.width=4;
    rect.height=15;
    return rect;
}
