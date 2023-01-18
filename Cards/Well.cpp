//
// Created by soso_ on 1/12/2023.
//

#include "Well.h"
void Well::applySpecialCard(Player &player)
{
    if(player.getPlayerType() != "Ninja"){
        player.damage(m_fall_fight_damage);
        printWellMessage(false);
    }
    else
    {
        printWellMessage(true);
    }
}
