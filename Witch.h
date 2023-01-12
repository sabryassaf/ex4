//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include <Card.h>

class Witch : public Card
{
private:
    int m_force;
    int m_damage;
    int m_loot;

public:
    Witch(string type, int force, int damage, int loot) : Card("Witch"), m_force(11), m_damage(10), m_loot(2)
    {}

    void applyCard(Player &player) override;
};

#endif //EX4_WITCH_H
