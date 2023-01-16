//
// Created by soso_ on 1/11/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include <Player.h>
#include "utilities.h"
using namespace std;

class Card
{
protected:
    string m_type;

public:
    Card(string type) : m_type(type)
    {}

    string getType() const;

    virtual void applyCard(Player &player) = 0;
};

class BattleCards : public Card
{
protected:
    int m_force;
    int m_damage;
    int m_loot;

public:
    BattleCards(string type, int force, int damage, int loot) : Card(type), m_force(force),
                                                                 m_damage(damage), m_loot(loot)
    {}

    void applyCard(Player &player) override;


protected:
    virtual void applyCardDamage(Player &player);

    void applyCardWins(Player &player);

    bool cardWins(Player &player);

};

class PeacefulCards : public Card
{
protected:
    int m_fall_fight_damage;
    int m_heal;

public:
    PeacefulCards(string type, int fall_fight_damage, int heal) : Card(type),
                                                                   m_fall_fight_damage(fall_fight_damage),
                                                                   m_heal(heal)
    {}

    void applyCard(Player &player) override;

    virtual void applyPeacefulCard(Player &player) = 0;
};

class FinanceCards : public Card
{
protected:
    int m_Treasure;

public:
    FinanceCards(string  type, int treasure) : Card(type), m_Treasure(treasure)
    {}

    void applyCard(Player &player) override;
    virtual void applyFinanceCard(Player &player) = 0;
};

#endif //EX4_CARD_H
