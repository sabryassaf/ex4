
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "HitPoints.h"

class Player
{
private:
    static const int MAX_LEVEL = 10;

    virtual void playerInfo(std::ostream &os) const = 0;

protected:
    const char* m_name;
    int m_level;
    int m_force;
    HitPoints m_HP;
    int m_coins;

public:
    Player(const char* name);

    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    void levelUp();
    int getLevel() const;
    virtual void buff(int buffLevel);
    virtual int getAttackStrength() const;
    virtual void heal(int healLevel);
    void damage(int hpLost);
    bool isKnockedOut() const;
    virtual void addCoins(int money);
    bool pay(int payment);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};


#endif //EX2_PLAYER_H
