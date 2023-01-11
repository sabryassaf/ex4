//
// Created by soso_ on 1/11/2023.
//
#include "Card.h"


void BattleCards::applyCard(Player &player)
{
    bool win = player.getAttackStrength() >= m_force;
    if (win)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), getName());
    } else
    {
        player.damage(m_damage);
        printLossBattle(player.getName(), getName());
    }
}

string Card::getName() const
{
    return m_name;
}
string Card::getType() const
{
    return m_type;
};