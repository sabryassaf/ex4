//
// Created by royb9 on 11/01/2023.
//

#include "Healer.h"
#include "utilities.h"

Healer::Healer(std::string name) : Player(name)
{}

void Healer::heal(int healLevel)
{
    Player::heal(healLevel * 2);
}

void Healer::playerInfo(std::ostream& os) const
{
    printPlayerDetails(os,
                       this->m_name,
                       "Healer",
                       this->m_level,
                       this->m_force,
                       this->m_hp.get_current(),
                       this->m_coins);
}
