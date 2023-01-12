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

void PeacefulCards::applyCard(Player &player)
{
    if (m_type == "Well Card")
    {
        if (player.getName() == "Ninja")
        {
            return;
        } else
        {
            player.damage(m_fall_fight_damage);
            return;
        }
    } else if (m_type == "Barfight Card")
    {
        if (player.getName() == "Warrior")
        {
            return;
        } else
        {
            player.damage(m_fall_fight_damage);
        }
    } else if (m_type == "Mana Card")
    {
        if (player.getName() == "Healer")
        {
            int double_heal = 2 * m_heal;
            player.heal(double_heal);
            return;

        } else
        {
            player.heal(m_heal);
            return;
        }
    }
}


void FinanceCards::applyCard(Player &player)
{
    if(m_type == "Merchant Cards"){

    }
}
