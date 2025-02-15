#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "hlavickovysoubor.h"
#include "entity.h"

class gameboard
{
    private:
    entity gamer;
    entity beast;
public:
    gameboard(entity _g, entity _b);
    unsigned int diceRoll(unsigned int _dice);
    void gamerAttack();
    void gamerUseItem();
    void gamerDecision(unsigned int _dec);
    void beastAttack();
    void game();
    void game2();
    void decision(unsigned int _d);
};

#endif