#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"

class Player
{
public:
    /*
    Player(QVector2D start_position = QVector2D(0,0)) {
        current_position = start_position;
    }*/
    Player(QVector2D start_position = QVector2D(0,0))
        : current_position(start_position)
    {
    }

    QVector2D getCurrent_position() const;
    float getMovement_speed() const;
    float getСollider_size() const;

    void movePlayer(Direction dir);

    Bullet takeShot();

private:
    QVector2D current_position;
    Direction aim_direction = Direction::Up; // Изменяется только при передвижении
    const float move_speed = 50;

    uint32_t current_hit_points = 5;
    const uint32_t max_hit_points = 5;


    const float collider_size = 50;
};

#endif // PLAYER_H
