#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <QList>

class Player
{
public:
    Player(QPoint startPoint = QPoint(0,0)) {
        position.append(startPoint);
        position.append(startPoint + QPoint(playerSize, 0));
        position.append(startPoint + QPoint(playerSize, playerSize));
        position.append(startPoint + QPoint(0, playerSize));
    }


    const QList<QPoint> getPoints();
    void movePlayer(QPoint difference);

private:
    QList<QPoint> position;
    int playerSize = 20;
};

#endif // PLAYER_H
