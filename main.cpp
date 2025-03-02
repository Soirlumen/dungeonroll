#include "hlavickovysoubor.h"
#include "gameboard.h"


std::map<int, itemtype> all_items{
  {SMALLHEAL, itemtype("Small healing potion", 10)},
  {SMALLPOWERBOOST, itemtype("Small attack blessing", 10)},
  {SMALLINVENTORYEXPANSION, itemtype("Small pocket", 1)},
  //{SMALLLUCKBOOST, itemtype("Small vial of Luck", 1)},
  //{SMALLWALLET, itemtype("A little bit of grosh", 10)}

};


int main()
{

  return 0;
}
