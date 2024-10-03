#include "Game.h"

Game::Game()
{
    initGame();
}

Game::~Game()
{
    Alien::unloadImages();
}

void Game::draw()
{
    spaceship.draw();
    for (auto& laser:spaceship.lasers){
        laser.draw();
    }

    for (auto& obstacle:obstacles){
        obstacle.draw();
    }

    for (auto& alien:aliens){
        alien.draw();
    }

    for (auto& laser:alienLasers){
        laser.draw();
    }
}

void Game::update()
{
    if (alive){
        for (auto& laser:spaceship.lasers){
            laser.update();
        }
        deleteInactiveLaser();
        moveAliens();
        alienShootLaser();
        for (auto& laser:alienLasers){
            laser.update();
        }
        checkForCollisions();
    }
}

void Game::handleInput()
{
    checkWin();
    if (alive){
        if (IsKeyDown(KEY_LEFT)){
            spaceship.moveLeft();
        } else if (IsKeyDown(KEY_RIGHT)){
            spaceship.moveRight();
        } else if (IsKeyDown(KEY_SPACE)){
            spaceship.fireLaser();
        }
    } else if (IsKeyDown(KEY_ENTER)){
        reset();
        initGame();
        std::cout << "Restarted game!" 
            << std::endl;
    }
}

void Game::deleteInactiveLaser()
{
    for (auto it=spaceship.lasers.begin(); it !=spaceship.lasers.end();){
        if (!it->active){
            it=spaceship.lasers.erase(it);
        } else{
            ++it;
        }
    }

    for (auto it=alienLasers.begin(); it !=alienLasers.end();){
        if (!it->active){
            it=alienLasers.erase(it);
        } else{
            ++it;
        }
    }
}

std::vector<Obstacle> Game::createObstacles()
{
    int obstacleWidth=Obstacle::grid[0].size()*3;
    float gap = (GetScreenWidth()-4*obstacleWidth)/4;

    for (int i=0; i<3; i++){
        float offsetx=(i+1)*gap + i*obstacleWidth;
        obstacles.push_back(Obstacle({offsetx, (float)GetScreenHeight()-100}));
    }
    return obstacles;
}

std::vector<Alien> Game::createAliens()
{
    std::vector<Alien> aliens;
    for (int row=0; row<3; row++){
        for (int col=0; col<5; col++){
            int alienType;
            if (row==0){
                alienType=3;
            } else if (row==1){
                alienType=2;
            } else{
                alienType=1;
            }
            float x=30+col*55;
            float y=30+row*55;
            aliens.push_back(Alien(alienType,{x,y}));
        }
    }
    return aliens;
}

void Game::moveAliens()
{
    for (auto& alien:aliens){
        if (alien.m_position.x + alien.alienImages[alien.m_type-1].width > GetScreenWidth()){
            alienDirection=-1;
            moveDownAliens(4);
        } else if (alien.m_position.x<0){
            alienDirection=1;
            moveDownAliens(4);
        }
        alien.update(alienDirection);
    }
}

void Game::moveDownAliens(int distance)
{
    for (auto& alien:aliens){
        alien.m_position.y+=distance;
    }
}

void Game::alienShootLaser()
{
    double currentTime = GetTime();
    if (currentTime-timeLastAlienFired>=alienLaserShootInterval && !aliens.empty()){
        int randomIndex=GetRandomValue(0,aliens.size()-1);
        Alien& alien=aliens[randomIndex];
        alienLasers.push_back(Laser({alien.m_position.x+alien.alienImages[alien.m_type-1].width/2, 
                                    alien.m_position.y+alien.alienImages[alien.m_type-1].height},6));
        timeLastAlienFired=GetTime();
    }
}

void Game::checkForCollisions()
{
    //spaceship lasers collision
    for (auto& laser:spaceship.lasers){
        auto it=aliens.begin();
        while(it != aliens.end()){
            if (CheckCollisionRecs(it->getRect(), laser.getRect())){
                it=aliens.erase(it);
                laser.active=false;
            } else{
                ++it;
            }
        }

        for (auto& obstacle:obstacles){
            auto it=obstacle.blocks.begin();
            while(it!=obstacle.blocks.end()){
                if (CheckCollisionRecs(it->getRect(), laser.getRect())){
                    it=obstacle.blocks.erase(it);
                    laser.active=false;
                } else{
                    ++it;
                }
            }
        }
    }

    //alien laser collision
    for (auto& laser:alienLasers){
        if (CheckCollisionRecs(laser.getRect(), spaceship.getRect())){
            laser.active=false;
            health--;
            std::cout << "Spaceship hit! Health remaining: " << health << "\n";
            if (health==0){
                alive=false;
            }
        }
        
        for (auto& obstacle:obstacles){
            auto it=obstacle.blocks.begin();
            while(it!=obstacle.blocks.end()){
                if (CheckCollisionRecs(it->getRect(), laser.getRect())){
                    it=obstacle.blocks.erase(it);
                    laser.active=false;
                } else{
                    ++it;
                }
            }
        }
    }
}

void Game::checkWin()
{
    if (alive && aliens.size()==0){
        std::cout << "Victory!" << "\n";
    } else if (alive==false && aliens.size()>1){
        std::cout << "Game Over!" << "\n";
    }
}

void Game::reset()
{
    spaceship.reset();
    aliens.clear();
    alienLasers.clear();
    obstacles.clear();
}

void Game::initGame()
{
    obstacles=createObstacles();
    aliens=createAliens();
    alienDirection=1;
    timeLastAlienFired=0.0;
    alive=true;
    health=3;
}
