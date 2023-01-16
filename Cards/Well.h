//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"

class Well : public PeacefulCards
{
public:
    Well() : PeacefulCards("Well", 10, 0)
    {};

    void applyPeacefulCard(Player &player) override;
};

#endif //EX4_WELL_H
