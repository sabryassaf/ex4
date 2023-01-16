//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "Card.h"

class Dragon : public BattleCards
{
public:
    Dragon(): BattleCards("Dragon",25,0,1000)
    {
    }

    void applyCardDamage(Player &player) override;

};
#endif //EX4_DRAGON_H
