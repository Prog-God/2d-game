#include "player.h"



const QList<QPoint> Player::getPoints()
{
    return position;
}

void Player::movePlayer(QPoint difference)
{
    for (int i = 0; i < 4; ++i)
        position[i] += difference;
}
