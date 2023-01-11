
#include "Player.h"
#include "utilities.h"

Player::Player(std::string name) :
    m_name(name), m_level(1), m_force(DEFAULT_FORCE), m_HP(), m_coins(0)
{}

int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

void Player::buff(int buffLevel)
{
    if (buffLevel > 0)
    {
        m_force += buffLevel;
    }
}

void Player::heal(int healLevel)
{
    /* Can't heal by a negative amount. */
    if (healLevel >= 0)
    {
        this->m_HP += healLevel;
    }
}

void Player::damage(int hpLost)
{
    /* Can't take negative damage. */
    if (hpLost > 0)
    {
        m_HP -= hpLost;
    }
}

bool Player::isKnockedOut() const
{
    return m_HP == 0;
}

void Player::addCoins(int money)
{
    /* Can't gain negative money. */
    if (money > 0)
    {
        m_coins += money;
    }
}

bool Player::pay(int payment)
{
    /* Can't pay a negative price. */
    if (payment < 0)
    {
        return true;
    }

    if (m_coins < payment)
    {
        return false;
    }

    m_coins -= payment;
    return true;
}

int Player::getAttackStrength() const
{
    return m_level + m_force;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.playerInfo(os);
    return os;
}
