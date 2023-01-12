//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include <Card.h>

class Treasure : FinanceCards
{
public:
    Treasure(string &type) : FinanceCards(type, 10)
    {};

    void applyFinanceCard(Player &player) override;

};

#endif //EX4_TREASURE_H
