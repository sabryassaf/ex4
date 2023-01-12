//
// Created by soso_ on 1/11/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include <Player.h>
#include <utilities.h>

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
private:
    int m_force;
    int m_damage;
    int m_loot;

public:
    BattleCards(string type, string name, int force, int damage, int loot) : Card(type, name), m_force(force),
                                                                             m_damage(damage), m_loot(loot)
    {}

    void applyCard(Player &player) override;

};

class PeacefulCards : public Card
{
private:
    int m_fall_fight_damage;
    int m_heal;

public:
    PeacefulCards(string type, string name, int fall_damage, int heal) : Card(type, name),
                                                                         m_fall_fight_damage(fall_damage),
                                                                         m_heal(heal)
    {}

    void applyCard(Player &player) override;
};

class FinanceCards : public Card
{
private:
    int m_Treasure;

public:
    FinanceCards(string type, string name, int treasure) : Card(type, name), m_Treasure(treasure)
    {}

    void applyCard(Player &player) override;
};

#endif //EX4_CARD_H
