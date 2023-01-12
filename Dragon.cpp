//
// Created by soso_ on 1/12/2023.
//

#include "Dragon.h"
void Dragon::applyCard(Player &player)
{
    bool win = player.getAttackStrength() >= m_force;
    if (win)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), getType());
    } else
    {
        player.damage(player.maxHp());
        printLossBattle(player.getName(), getType());
    }
}