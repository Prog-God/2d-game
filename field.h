#ifndef FIELD_H
#define FIELD_H

#include <list>

#include <random>

#include "player.h"

class Field
{
public:
    Field();

    Player player;
    std::list<Bullet> bullets_on_field;
    std::list<Player> enemies_on_field;

    void setFieldSize(float width, float height);

    Player generateEnemy(QVector2D start_position = QVector2D(0,0));

    //границы в будущем видимо тоже хранить буду где-то здесь

    float getField_width() const;

    float getField_height() const;

private:
    float field_width;
    float field_height;
};

#endif // FIELD_H
