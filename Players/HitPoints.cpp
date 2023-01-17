
#include "HitPoints.h"

HitPoints::HitPoints(int maxHp)
{
    if (maxHp <= 0)
    {
        throw HitPoints::InvalidArgument();
    }

    this->m_maxHP = maxHp;
    this->m_currentHP = maxHp;
}

HitPoints::HitPoints(int maxHp, int currentHP)
{
    if (maxHp <= 0)
    {
        throw HitPoints::InvalidArgument();
    }

    this->m_maxHP = maxHp;
    this->m_currentHP = 0;
    this->setHP(currentHP);
}

void HitPoints::setHP(int value)
{
    if (value > this->m_maxHP)
    {
        value = this->m_maxHP;
    }
    if (value < 0)
    {
        value = 0;
    }

    this->m_currentHP = value;
}

int HitPoints::get_current() const
{
    return this->m_currentHP;
}

int HitPoints::getMaxHP() const
{
    return this->m_maxHP;
}

/* Arithmetic operators */

HitPoints HitPoints::operator+(int value) const
{
    return HitPoints(this->m_maxHP,
                     this->m_currentHP + value);
}

HitPoints HitPoints::operator-(int value) const
{
    return HitPoints(this->m_maxHP,
                     this->m_currentHP - value);
}

HitPoints operator+(int value, const HitPoints& hp)
{
    return hp + value;
}

HitPoints operator-(int value, const HitPoints& hp)
{
    return HitPoints(hp.m_maxHP,
                     value - hp.m_currentHP);
}

void HitPoints::operator+=(int value)
{
    this->setHP(this->m_currentHP + value);
}

void HitPoints::operator-=(int value)
{
    this->setHP(this->m_currentHP - value);
}

/* Boolean operators */

bool HitPoints::operator==(HitPoints other) const
{
    return this->m_currentHP == other.m_currentHP;
}

bool HitPoints::operator!=(HitPoints other) const
{
    return this->m_currentHP != other.m_currentHP;
}

bool HitPoints::operator>(HitPoints other) const
{
    return this->m_currentHP > other.m_currentHP;
}

bool HitPoints::operator<(HitPoints other) const
{
    return this->m_currentHP < other.m_currentHP;
}

bool HitPoints::operator>=(HitPoints other) const
{
    return this->m_currentHP >= other.m_currentHP;
}

bool HitPoints::operator<=(HitPoints other) const
{
    return this->m_currentHP <= other.m_currentHP;
}

bool HitPoints::operator==(int value) const
{
    return this->m_currentHP == value;
}

bool HitPoints::operator!=(int value) const
{
    return this->m_currentHP != value;
}

bool HitPoints::operator>(int value) const
{
    return this->m_currentHP > value;
}

bool HitPoints::operator<(int value) const
{
    return this->m_currentHP < value;
}

bool HitPoints::operator>=(int value) const
{
    return this->m_currentHP >= value;
}

bool HitPoints::operator<=(int value) const
{
    return this->m_currentHP <= value;
}

bool operator==(int value, const HitPoints& hp)
{
    return hp == value;
}

bool operator!=(int value, const HitPoints& hp)
{
    return hp != value;
}

bool operator>(int value, const HitPoints& hp)
{
    return hp < value;
}

bool operator<(int value, const HitPoints& hp)
{
    return hp > value;
}

bool operator>=(int value, const HitPoints& hp)
{
    return hp <= value;
}

bool operator<=(int value, const HitPoints& hp)
{
    return hp >= value;
}

/* IO operators */

std::ostream& operator<<(std::ostream& os, const HitPoints& hp)
{
    return os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
}
