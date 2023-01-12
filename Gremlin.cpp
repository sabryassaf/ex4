//
// Created by soso_ on 1/12/2023.
//

#include "Gremlin.h"
void Gremlin::applyCard(Player &player)
{
    bool win = player.getAttackStrength() >= m_force;
    if (win)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), getType());
    } else
    {
        player.damage(m_damage);
        printLossBattle(player.getName(), getType());
    }
}