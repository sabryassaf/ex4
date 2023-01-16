//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H

#include "Card.h"

class Mana : PeacefulCards
{
public:
    Mana(string &type) : PeacefulCards(type, 0, 10)
    {}

    void applyPeacefulCard(Player &player) override;
};

#endif //EX4_MANA_H
