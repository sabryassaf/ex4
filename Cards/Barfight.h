//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : PeacefulCards
{
public:
    Barfight(string &type) : PeacefulCards(type, 10, 0)
    {

    }

    void applyPeacefulCard(Player &player) override;
};

#endif //EX4_BARFIGHT_H
