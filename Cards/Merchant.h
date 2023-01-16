//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : FinanceCards
{
public:
    Merchant(string &type) : FinanceCards(type, 0)
    {

    }
    void applyFinanceCard(Player &player) override;
};

#endif //EX4_MERCHANT_H
