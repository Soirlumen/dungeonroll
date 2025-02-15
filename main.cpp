#include "hlavickovysoubor.h"
#include "gameboard.h"

std::vector<int> kuk;

int main()
{
  item potionsilly(2, 10);
  item potionZdravim(1, 20);
  std::vector<item> kapsa={potionsilly,potionZdravim};
  entity zaba(100, 10,3);
  entity myrka(100, 10,3,kapsa);
  gameboard clovecenezlobse(myrka, zaba);
  clovecenezlobse.game2();
  return 0;
}
