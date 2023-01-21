//
// Created by royb9 on 11/01/2023.
//

#include "Warrior.h"
#include "../utilities.h"

Warrior::Warrior(std::string name) : Player(name)
{}

int Warrior::getAttackStrength() const
{
    return m_level + (m_force * 2);
}

void Warrior::playerInfo(std::ostream& os) const
{
    printPlayerDetails(os,
                       this->m_name,
                       "Warrior",
                       this->m_level,
                       this->m_force,
                       this->m_hp.get_current(),
                       this->m_coins);
}

std::string Warrior::getPlayerType() const
{
    return "Warrior";
}
