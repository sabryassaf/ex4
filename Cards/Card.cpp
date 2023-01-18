//
// Created by soso_ on 1/11/2023.
//
#include "Card.h"

std::string Card::getType() const
{
    return m_type;
};

void BattleCards::applyCard(Player &player)
{
    if (cardWins(player))
    {
        applyCardWins(player);
    } else
    {
        applyCardDamage(player);
//        printLossBattle(player.getName(), getType());
    }


}

void BattleCards::applyCardDamage(Player &player)
{
    player.damage(m_damage);
}

void BattleCards::applyCardWins(Player &player)
{
    player.levelUp();
    player.addCoins(m_loot);
//    printWinBattle(player.getName(), getType());
}

bool BattleCards::cardWins(Player &player)
{
    return player.getAttackStrength() >= m_force;
}


void SpecialCards::applyCard(Player &player)
{
    applyPeacefulCard(player);
}


void FinanceCards::applyCard(Player &player)
{
    applyFinanceCard(player);
}

