//
// Created by royb9 on 11/01/2023.
//

#include "Ninja.h"
#include "utilities.h"

Ninja::Ninja(std::string name) : Player(name)
{}

void Ninja::addCoins(int money)
{
    Player::addCoins(money * 2);
}

void Ninja::playerInfo(std::ostream& os) const
{
    printPlayerDetails(os,
                       this->m_name,
                       "Ninja",
                       this->m_level,
                       this->m_force,
                       this->m_hp.get_current(),
                       this->m_coins);
}

std::string Ninja::getPlayerType() const
{
    return "Ninja";
}
