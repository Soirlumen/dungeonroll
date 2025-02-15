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

void gameboard::gamerAttack()
{
    int dmg = (gamer.getPower() + diceRoll(3));
    beast.setHealth(beast.getHealth() - dmg);
    piš("dal jsi prisere: ", dmg, " damage, bestii zbyva: ", beast.getHealth(), " zivotu\n");
}

void gameboard::gamerUseItem()
{
    std::cout<<"ktery item?"<<std::endl;
    gamer.showInventory();
    int kvak;
    std::cin>>kvak;
    gamer.useItem(kvak);
}

void gameboard::gamerDecision(unsigned int _dec)
{
    switch (_dec)
    {
    case 1:
        gamerAttack();
        break;
    case 2:
        gamerUseItem();
        break;
    default:
    //vymyslet jestli je nutne tu pouzivat rekurzi1
        piš("Neudelal jsi nic lmao... zkus to znovu chca cha\n");
        unsigned int _newdec;
        std::cin>>_newdec;
        gamerDecision(_newdec);
        break;
    }
}

void gameboard::beastAttack()
{
    int dmg = (beast.getPower() + diceRoll(3));
    gamer.setHealth(gamer.getHealth() - dmg);
    piš("prisera dala: ", dmg, " damage, hraci zbyva: ", gamer.getHealth(), " zivotu\n");
}

void gameboard::game()
{
    int live = 0;
    while (true)
    {
        piš("zivoty hrace: ", gamer.getHealth(), ", zivoty bestie: ", beast.getHealth(), "\n");
        piš("kolo hrace:, napis 1, pokud chces boj, napis 2, pokud pouzit item \n");
        int i;
        std::cin >> i;
        if (i == 1)
        {
            int dmg = (gamer.getPower() + diceRoll(3));
            beast.setHealth(beast.getHealth() - dmg);
            piš("dal jsi prisere: ", dmg, " damage, bestii zbyva: ", beast.getHealth(), " zivotu\n");
            if (beast.getHealth() < 1)
            {
                live = 1;
                break;
            }
        }
        piš("kolo bestie, koukni bumbumbaac ");
        int dmg = (beast.getPower() + diceRoll(3));
        gamer.setHealth(gamer.getHealth() - dmg);
        piš("prisera dala: ", dmg, " damage, hraci zbyva: ", gamer.getHealth(), " zivotu\n");
        if (gamer.getHealth() < 1)
        {
            break;
        }
    }
    if (live == 1)
    {
        piš("zabil jsi bestii koneeeeccc hryyy");
    }
    else
    {
        piš("ups bestie te zabila konec hryyyyy");
    }
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

void gameboard::decision(unsigned int _d)
{
}
