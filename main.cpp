#include "hlavickovysoubor.h"
#include "gameboard.h"


std::map<int, itemtype> all_items{
  {SMALLHEAL, itemtype("Small healing potion", 10)},
  {SMALLPOWERBOOST, itemtype("Small attack blessing", 10)},
  {SMALLINVENTORYEXPANSION, itemtype("Small pocket", 1)},
  {SPIDERLEG,itemtype("Spider leg",0)}
  //{SMALLLUCKBOOST, itemtype("Small vial of Luck", 1)},
  //{SMALLWALLET, itemtype("A little bit of grosh", 10)}

};


int main()
{
  inventory kapsicka(all_items, 10);
  kapsicka.add_item(SMALLHEAL);
  kapsicka.add_item(SMALLPOWERBOOST);
  kapsicka.add_item(SMALLINVENTORYEXPANSION);
  inventory pavouknemakapsu(all_items,1);
  pavouknemakapsu.add_item(SPIDERLEG);
  //kapsicka.inventory_cout();
  entity hrac(100,10,"Myrka",kapsicka);
  entity bestie(100,10,"pavouk",pavouknemakapsu);
  gameboard hra(hrac,bestie);
  hra.fight();
  return 0;
}
