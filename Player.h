
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>

const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;
const int MAX_LEVEL = 10;
using namespace std;

class Player
{
    const char *m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:
    Player(const char *name, int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    Player(const Player &) = default;

    ~Player() = default;

    Player &operator=(const Player &other) = default;

    int getLevel() const;

    void levelUp();

    void buff(int buffLevel = 0);

    void heal(int healLevel = 0);

    void damage(int hpLost = 0);

    bool isKnockedOut() const;

    void addCoins(int money = 0);

    bool pay(int payment = 0);

    int getAttackStrength() const;

    void printInfo() const;

    string getName() const
    {
        return m_name;
    }

    int maxHp() const
    {
        return m_maxHP;
    }

    int getCoins() const
    {
        return m_coins;
    }
};


#endif //EX2_PLAYER_H
