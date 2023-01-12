//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include <Card.h>

class Gremlin : public Card
{
private:
    int m_force;
    int m_damage;
    int m_loot;

public:
    Gremlin(string type, int force, int damage, int loot) : Card("Gremlin"), m_force(5), m_damage(10), m_loot(2)
    {}

    void applyCard(Player &player) override;
};
#endif //EX4_GREMLIN_H
