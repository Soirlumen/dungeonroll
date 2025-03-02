#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "hlavickovysoubor.h"
#include "entity.h"

class gameboard
{
private:
    entity gamer;
    entity beast;

    unsigned int diceRoll(unsigned int _dice);
    void gamerDecision(unsigned int _dec);
    void attack(entity& _who, entity& _whom);

public:
    gameboard(entity _g, entity _b);
    void fight();
};

#endif