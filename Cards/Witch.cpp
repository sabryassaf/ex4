//
// Created by soso_ on 1/12/2023.
//
#include "Witch.h"

void Witch::applyCard(Player& player)
{
    if (playerWins(player))
    {
        applyPlayerWins(player);
    } else
    {
        applyCardDamage(player);
        printLossBattle(player.getName(), getType());
        player.buff(-1);
    }
}
