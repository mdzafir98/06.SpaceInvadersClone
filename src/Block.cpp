#include "Block.h"

Block::Block(Vector2 position)
{
    m_position=position;
}

void Block::draw()
{
    DrawRectangle(m_position.x, m_position.y, 3, 3, {243,216,63,255});
}

Rectangle Block::getRect()
{
    Rectangle rect;
    rect.x=m_position.x;
    rect.y=m_position.y;
    rect.width=3;
    rect.width=3;
    return rect;
}
