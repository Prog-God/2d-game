#include "field.h"

Field::Field()
{

}

void Field::setFieldSize(float width, float height)
{
    field_width = width;
    field_height = height;
}

Player Field::generateEnemy(QVector2D start_position)
{
    return Player(start_position);
}

float Field::getField_width() const
{
    return field_width;
}

float Field::getField_height() const
{
    return field_height;
}
