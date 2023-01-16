//
// Created by soso_ on 1/12/2023.
//

#include "Barfight.h"

void Barfight::applyPeacefulCard(Player &player)
{
    if(player.getName() != "Warrior"){
        player.damage(m_fall_fight_damage);
    }
}