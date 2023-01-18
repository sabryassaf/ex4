//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"

class Well : public SpecialCards
{
public:
    Well() : SpecialCards("Well", 10, 0)
    {};

    void applySpecialCard(Player &player) override;
};

#endif //EX4_WELL_H
