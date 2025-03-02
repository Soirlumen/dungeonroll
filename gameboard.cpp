#include "gameboard.h"
template <typename T>
void easywrite(T t)
{
    std::cout << t;
}

template <typename T, typename... Args>
void easywrite(T t, Args... args)
{
    std::cout << t;

    easywrite(args...);
}

gameboard::gameboard(entity _g, entity _b) : gamer(_g), beast(_b) {}

unsigned int gameboard::diceRoll(unsigned int _dice)
{
    if (_dice == 0)
    {
        return 0;
    }
    std::random_device rd;
    std::vector<std::uint32_t> seed_data(8);
    for (auto &s : seed_data)
        s = rd();

    std::seed_seq seed(seed_data.begin(), seed_data.end());
    std::knuth_b a(seed);

    std::uniform_int_distribution<int> b(-_dice, _dice);
    return b(a);
}

/* void gameboard::gamerAttack()
{
    int dmg = (gamer.getPower() + diceRoll(3));
    beast.setHealth(beast.getHealth() - dmg);
    easywrite("dal jsi prisere: ", dmg, " damage, bestii zbyva: ", beast.getHealth(), " zivotu\n");
}
 */
void gameboard::gamerDecision(unsigned int _dec)
{
    int itemId;
    switch (_dec)
    {
    case 1:
        attack(gamer, beast);
        break;
    case 2:
        gamer.getInventory().inventory_cout();
        easywrite("napis cislo, ktery item chces pouzit?");
        std::cin >> itemId;
        gamer.use_item(itemId);
        break;
    case 3:
        exit(0);
        break;
    default:
        // vymyslet jestli je nutne tu pouzivat rekurzi1
        easywrite("Neudelal jsi nic lmao... zkus to znovu chca cha\n");
        break;
    }
}

void gameboard::attack(entity& _who, entity& _whom)
{
    int dmg = _who.entity_attack() + diceRoll(3);
    _whom.health_changer(-dmg);
    easywrite(_who.getName() + " dala: ", dmg, " damage, " + _whom.getName() + " zbyva: ", _whom.getHealth(), " zivotu\n");
}

void gameboard::fight()
{
    int round = 1;
    while (true)
    {
        easywrite(round, " # kolo, zivoty hrace: ", gamer.getHealth(), ", zivoty bestie: ", beast.getHealth(), "\n");
        easywrite("kolo hrace:, napis 1, pokud chces boj, napis 2, pokud pouzit item, 3 pokud chces skoncit hru \n");
        int dec;
        std::cin >> dec;
        gamerDecision(dec);
        if (!beast.isAlive())
        {
            break;
        }
        easywrite("kolo bestie, koukni bumbumbaac \n");
        attack(beast, gamer);
        if (!gamer.isAlive())
        {
            break;
        }
        round++;
    }
    if (gamer.isAlive())
    {
        easywrite("zabil jsi priseru yippe\n");
    }
    else
    {
        easywrite("prisera te zabila lol");
    }
}
