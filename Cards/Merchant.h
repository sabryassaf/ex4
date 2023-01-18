//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public FinanceCards
{
public:
    Merchant() : FinanceCards("Merchant", 0) {}
    void applyFinanceCard(Player &player) override;

    /**
     * Apply the payment for the card.
     *
     * @param player Player to apply payment for.
     * @param choice Choice for payment method.
     *
     *  0 - No payment
     *  1 - Heal
     *  2 - Force
     * */
    void applyPayment(std::ostream &os,Player& player, int choice);
};

#endif //EX4_MERCHANT_H
