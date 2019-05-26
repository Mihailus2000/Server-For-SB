#pragma once

#include "game.h"

void firstFilling(int X,int Y, QVector<QVector<int>> vec) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                vec[i][j] = 0;
            }
        }
    }

void game::initialization()
{
    FirstPlayersField.resize(X);
    SecondPlayersField.resize(X);
    FirstPlayersMapShots.resize(X);
    SecondPlayersMapShots.resize(X);

    for (int i = 0; i < X; i++) {
                FirstPlayersField[i].resize(Y);
                SecondPlayersField[i].resize(Y);
                FirstPlayersMapShots[i].resize(Y);
                SecondPlayersMapShots[i].resize(Y);
    }

    firstFilling(X,Y,FirstPlayersField);
    firstFilling(X,Y,SecondPlayersField);
    firstFilling(X,Y,FirstPlayersMapShots);
    firstFilling(X,Y,SecondPlayersMapShots);

}

