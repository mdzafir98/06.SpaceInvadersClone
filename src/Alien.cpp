#include "Alien.h"

Texture2D Alien::alienImages[3]={};

Alien::Alien(int type, Vector2 position)
{
    m_type=type;
    m_position=position;

    if (alienImages[m_type-1].id==0){
        switch(m_type){
        case 1:
            alienImages[0]=LoadTexture("Resources/Graphics/alien_1.png");
            break;
        case 2:
            alienImages[1]=LoadTexture("Resources/Graphics/alien_2.png");
            break;
        case 3:
            alienImages[2]=LoadTexture("Resources/Graphics/alien_3.png");
            break;
        default:
            alienImages[0]=LoadTexture("Resources/Graphics/alien_1.png");
            break;
        }
    }
}

void Alien::draw()
{
    DrawTextureV(alienImages[m_type-1],m_position,WHITE);
}

void Alien::update(int direction)
{
    m_position.x+=direction;
}

int Alien::getType()
{
    return m_type;
}

void Alien::unloadImages()
{
    for (int i=0; i<4; i++){
        UnloadTexture(alienImages[i]);
    }
}

Rectangle Alien::getRect()
{
    return {m_position.x, m_position.y, float(alienImages[m_type-1].width), float(alienImages[m_type-1].height)};
}
