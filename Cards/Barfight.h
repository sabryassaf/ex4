//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public SpecialCards
{
public:
    Barfight() : SpecialCards("Barfight", 10, 0)
    {

    }

    void applySpecialCard(Player &player) override;
};

#endif //EX4_BARFIGHT_H
