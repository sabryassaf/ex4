//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include <Card.h>

class Dragon : public Card
{
private:
    int m_force;
    int m_damage;
    int m_loot;

public:
    Dragon(string type, int force, int damage, int loot) : Card("Dragon"), m_force(25), m_damage(0), m_loot(2)
    {}

    void applyCard(Player &player) override;
};
#endif //EX4_DRAGON_H
