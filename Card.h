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
private:
    string m_type;
    string m_name;

public:
    Card(string type, string name) : m_type(type), m_name(name)
    {}
    string getName() const;
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

    void applyCard(Player &player);

};


#endif //EX4_CARD_H
