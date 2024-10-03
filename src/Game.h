#pragma once
#include "Spaceship.h"
#include "Alien.h"
#include "Obstacle.h"

class Game{
public:
    Game();
    ~Game();
    void draw();
    void update();
    void handleInput();
private:
    void deleteInactiveLaser();
    std::vector<Obstacle> createObstacles();
    std::vector<Alien> createAliens();
    void moveAliens();
    void moveDownAliens(int distance);
    void alienShootLaser();
    void checkForCollisions();
    void checkWin();
    void reset();
    void initGame();

    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienLasers;
    int alienDirection;
    constexpr static float alienLaserShootInterval=0.35;
    float timeLastAlienFired;
    bool alive;
    int health;
};