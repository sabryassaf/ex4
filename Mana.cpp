//
// Created by soso_ on 1/12/2023.
//

#include "Mana.h"

void Mana::applyPeacefulCard(Player &player)
{
    if (player.getName() == "Healer")
    {
        player.heal(2 * m_heal);
        return;
    } else
    {
        player.heal(10);
    }
}
