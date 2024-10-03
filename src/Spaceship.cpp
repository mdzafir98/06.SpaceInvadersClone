#include "Spaceship.h"

Spaceship::Spaceship()
{
    image = LoadTexture("Resources/Graphics/spaceship.png");
    position.x=(GetScreenWidth() - image.width)/2;
    position.y=GetScreenHeight() - image.height;
    lastFireTime=0;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::draw()
{
    DrawTextureV(image,position,WHITE);
}

void Spaceship::moveLeft()
{
    position.x -= 7;
    if (position.x<0){
        position.x=0;
    }
}

void Spaceship::moveRight()
{
    position.x += 7;
    if (position.x+image.width>GetScreenWidth()){
        position.x=GetScreenWidth()-image.width;
    }
}

void Spaceship::fireLaser()
{
    if (GetTime()-lastFireTime >=0.35){
        lasers.push_back(Laser({position.x+image.width/2 -2, position.y},-6));
        lastFireTime=GetTime();
    }
}

Rectangle Spaceship::getRect()
{
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Spaceship::reset()
{
    position.x=(GetScreenWidth() - image.width)/2;
    position.y=GetScreenHeight() - image.height;
    lasers.clear();
}
