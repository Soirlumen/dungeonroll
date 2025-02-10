#include "hlavickovysoubor.h"

int main()
{
    entity zaba(100,10);
    entity myrka(100,10);
    gameboard clovecenezlobse(myrka,zaba);
    clovecenezlobse.game2();
    return 0;
}
