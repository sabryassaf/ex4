//
// Created by soso_ on 1/12/2023.
//

#include "Barfight.h"

void Barfight::applySpecialCard(Player &player)
{
    if(player.getPlayerType() != "Warrior")
    {
        player.damage(m_fall_fight_damage);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}
