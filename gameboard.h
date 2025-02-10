#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#pragma once
#include "hlavickovysoubor.h"

class gameboard
{
    private:
    entity gamer;
    entity beast;
public:
    gameboard(entity _g, entity _b);
    unsigned int diceRoll(unsigned int _dice);
    void gamerAttack();
    void gamerDecision(unsigned int _dec);
    void beastAttack();
    void game();
    void game2();
};

#endif