#include "player.h"


QVector2D Player::getCurrent_position() const
{
    return current_position;
}

float Player::getMovement_speed() const
{
    return move_speed;
}

float Player::getСollider_size() const
{
    return collider_size;
}

void Player::movePlayer(Direction dir)
{
    aim_direction = dir;

    switch (dir)
    {
    case Direction::Up:
    {
        current_position += QVector2D(0, -move_speed);
    }break;

    case Direction::Down:
    {
        current_position += QVector2D(0, move_speed);
    }break;

    case Direction::Left:
    {
        current_position += QVector2D(-move_speed, 0);
    }break;

    case Direction::Right:
    {
        current_position += QVector2D(move_speed, 0);
    }break;
    default:{}
    }//END SWITCH dir

}

Bullet Player::takeShot()
{
    return Bullet(current_position, aim_direction, 1);
}




