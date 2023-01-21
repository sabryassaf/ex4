//
// Created by soso_ on 1/12/2023.
//

#include "Dragon.h"
void Dragon::applyCardDamage(Player &player)
{
    player.damage(player.getHP());
}

void Dragon::printCard(std::ostream& os)
{
    printCardDetails(os, this->getType());
    printMonsterDetails(os,
                        this->m_force,
                        this->m_damage,
                        this->m_loot,
                        true);
    printEndOfCardDetails(os);
}
