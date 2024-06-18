#include "bullet.h"


QVector2D Bullet::getPosition() const
{
    return position;
}

void Bullet::moveBullet()
{
    switch (direction)
    {
    case Direction::Up:
    {
        position += QVector2D(0, -move_speed);
    }break;

    case Direction::Down:
    {
        position += QVector2D(0, move_speed);
    }break;

    case Direction::Left:
    {
        position += QVector2D(-move_speed, 0);
    }break;

    case Direction::Right:
    {
        position += QVector2D(move_speed, 0);
    }break;
    default:{}
    }
}

Direction Bullet::getDirection() const
{
    return direction;
}

float Bullet::getCollider_size() const
{
    return collider_size;
}

uint32_t Bullet::getDamage() const
{
    return damage;
}
