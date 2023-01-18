//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public FinanceCards
{
public:
    Merchant() : FinanceCards("Merchant", 0)
    {

    }
    void applyFinanceCard(Player &player) override;
    void applyPayment(std::ostream &os,Player& player, int x);
};

#endif //EX4_MERCHANT_H
