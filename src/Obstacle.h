#pragma once
#include <vector>
#include "Block.h"

class Obstacle{
public:
    Obstacle(Vector2 position);
    void draw();
    Vector2 m_position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;
private:
};