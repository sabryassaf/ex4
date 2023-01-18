//
// Created by soso_ on 1/12/2023.
//

#include "Mana.h"

void Mana::applySpecialCard(Player &player)
{
    if (player.getPlayerType() == "Healer")
    {
        player.heal(10);
        printManaMessage(true);
    }
    else
    {
        printManaMessage(false);
    }
}
