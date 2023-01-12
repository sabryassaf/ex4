//
// Created by soso_ on 1/12/2023.
//

#include "Well.h"
void Well::applyPeacefulCard(Player &player)
{
    if(player.getName() != "Ninja"){
        player.damage(m_fall_fight_damage);
    }
}