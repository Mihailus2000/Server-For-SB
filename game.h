#ifndef GAME_H
#define GAME_H

#include <QVector>

class game
{
    const int X,Y = 10;
    QVector<QVector<int>> FirstPlayersField;
    QVector<QVector<int>> SecondPlayersField;
    QVector<QVector<int>> FirstPlayersMapShots;
    QVector<QVector<int>> SecondPlayersMapShots;

    void initialization();


};

#endif // GAME_H
