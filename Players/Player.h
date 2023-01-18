
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "HitPoints.h"

class Player
{
private:
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_FORCE = 5;

    virtual void playerInfo(std::ostream &os) const = 0;

protected:
    std::string m_name;
    int m_level;
    int m_force;
    HitPoints m_hp;
    int m_coins;

public:
    explicit Player(std::string name);

    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;

    virtual std::string getPlayerType() const = 0;

    std::string getName() const;
    int getLevel() const;
    bool isMaxLevel() const;
    int getHP() const;
    int maxHp() const;
    int getCoins() const;

    void levelUp();
    void buff(int buffLevel);
    virtual int getAttackStrength() const;
    virtual void heal(int healLevel);
    void damage(int hpLost);
    bool isKnockedOut() const;
    virtual void addCoins(int money);
    bool pay(int payment);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};


#endif //EX2_PLAYER_H
