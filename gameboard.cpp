#include "gameboard.h"
template <typename T>
void piš(T t)
{
    std::cout << t;
}

template <typename T, typename... Args>
void piš(T t, Args... args)
{
    std::cout << t;

    piš(args...);
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
    piš("dal jsi prisere: ", dmg, " damage, bestii zbyva: ", beast.getHealth(), " zivotu\n");
}
 */
void gameboard::gamerDecision(unsigned int _dec)
{
    switch (_dec)
    {
    case 1:
        int dmg = gamer.entity_attack() + diceRoll(3);
        beast.health_changer(dmg);
        piš("dal jsi prisere: ", dmg, " damage, bestii zbyva: ", beast.getHealth(), " zivotu\n");
        break;
    case 2:
        int itemId;
        std::cin>>itemId;
        gamer.use_item(itemId);
    default:
        // vymyslet jestli je nutne tu pouzivat rekurzi1
        piš("Neudelal jsi nic lmao... zkus to znovu chca cha\n");
        unsigned int _newdec;
        std::cin >> _newdec;
        gamerDecision(_newdec);
        break;
    }
}

void gameboard::beastAttack()
{
    int dmg = beast.entity_attack()+diceRoll(3);
    gamer.health_changer(dmg);
    piš("prisera dala: ", dmg, " damage, hraci zbyva: ", gamer.getHealth(), " zivotu\n");
}

void gameboard::game2()
{
    int round = 1;
    while (true)
    {
        piš(round, " # kolo, zivoty hrace: ", gamer.getHealth(), ", zivoty bestie: ", beast.getHealth(), "\n");
        piš("kolo hrace:, napis 1, pokud chces boj, napis 2, pokud pouzit item \n");
        int dec;
        std::cin >> dec;
        gamerDecision(dec);
        if (!beast.isAlive())
        {
            break;
        }
        piš("kolo bestie, koukni bumbumbaac \n");
        beastAttack();
        if (!gamer.isAlive())
        {
            break;
        }
        round++;
    }
    if (gamer.isAlive())
    {
        piš("zabil jsi priseru yippe\n");
    }
    else
    {
        piš("prisera te zabila lol");
    }
}

void gameboard::game3()
{
    int round = 1;
    while (true)
    {
        piš(round, " # kolo, zivoty hrace: ", gamer.getHealth(), ", zivoty bestie: ", beast.getHealth(), "\n");
        piš("kolo hrace:, napis 1, pokud chces boj, napis 2, pokud pouzit item \n");
        int dec;
        std::cin >> dec;
        gamerDecision(dec);
        if (!beast.isAlive())
        {
            break;
        }
        piš("kolo bestie, koukni bumbumbaac \n");
        beast.entity_attack();
        if (!gamer.isAlive())
        {
            break;
        }
        round++;
    }
    if (gamer.isAlive())
    {
        piš("zabil jsi priseru yippe\n");
    }
    else
    {
        piš("prisera te zabila lol");
    }
}

void gameboard::decision(unsigned int _d)
{
}
