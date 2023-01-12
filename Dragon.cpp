//
// Created by soso_ on 1/12/2023.
//

#include "Dragon.h"
void Dragon::applyCardDamage(Player &player)
{
    player.damage(player.maxHp());
}
