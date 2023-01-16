//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public FinanceCards
{
public:
    Treasure() : FinanceCards("Treasure", 10)
    {};

    void applyFinanceCard(Player &player) override;

};

#endif //EX4_TREASURE_H
