#ifndef BULLET_H
#define BULLET_H

#include <QVector2D>

enum class Direction { Up, Down, Left, Right };

class Bullet
{
public:
    Bullet(QVector2D pos, Direction dir, uint32_t dmg)
        : position(pos), direction(dir), damage(dmg), move_speed(10.0f)
    {
        //assert(flight_speed < 0); //сломанная штука!
    }

    QVector2D getPosition() const;
    void moveBullet();

    Direction getDirection() const;

    float getCollider_size() const;

    uint32_t getDamage() const;

private:
    QVector2D position;
    const Direction direction;
    const float move_speed;

    const uint32_t damage;



    const float collider_size = 50;
};

#endif // BULLET_H
