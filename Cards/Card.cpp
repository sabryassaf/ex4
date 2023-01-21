//
// Created by soso_ on 1/11/2023.
//
#include "Card.h"

std::string Card::getType() const
{
    return m_type;
}

void Card::printCard(std::ostream& os)
{
    printCardDetails(os, this->getType());
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, Card& card)
{
    card.printCard(os);
    return os;
}

void BattleCards::applyCard(Player &player)
{
    if (playerWins(player))
    {
        applyPlayerWins(player);
    } else
    {
        applyCardDamage(player);
        printLossBattle(player.getName(), getType());
    }
}

void BattleCards::applyCardDamage(Player &player)
{
    player.damage(m_damage);
}

void BattleCards::applyPlayerWins(Player &player)
{
    player.levelUp();
    player.addCoins(m_loot);
    printWinBattle(player.getName(), getType());
}

bool BattleCards::playerWins(Player &player)
{
    return player.getAttackStrength() >= m_force;
}

void BattleCards::printCard(std::ostream& os)
{
    printCardDetails(os, this->getType());
    printMonsterDetails(os,
                        this->m_force,
                        this->m_damage,
                        this->m_loot,
                        false);
    printEndOfCardDetails(os);
}

void SpecialCards::applyCard(Player &player)
{
    applySpecialCard(player);
}

void FinanceCards::applyCard(Player &player)
{
    applyFinanceCard(player);
}
