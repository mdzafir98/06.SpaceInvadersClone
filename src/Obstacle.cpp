#include "Obstacle.h"

std::vector<std::vector<int>> Obstacle::grid=
    {
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    };

Obstacle::Obstacle(Vector2 position)
{
    m_position=position;

    for (unsigned int row=0; row<grid.size(); ++row){
        for (unsigned int col=0; col<grid[0].size(); ++col){
            if (grid[row][col]==1){
                float posx=m_position.x+col*3;
                float posy=m_position.y+row*3;
                Block block=Block({posx,posy});
                blocks.push_back(block);
            }
        }
    }
}

void Obstacle::draw()
{
    for (auto& block:blocks){
        block.draw();
    }
}
