//
// Created by soso_ on 1/11/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <string>
#include "utilities.h"
#include "Players/Player.h"

class Card
{
protected:
    std::string m_type;
    virtual void printCard(std::ostream& os);

public:
    Card(std::string &type) : m_type(type) {}
    virtual ~Card() = default;
    Card(const Card&) = default;
    Card& operator=(const Card& other) = default;
    std::string getType() const;

    virtual void applyCard(Player &player) = 0;
    friend std::ostream& operator<<(std::ostream& os, Card& card);
};

class BattleCards : public Card
{
protected:
    int m_force;
    int m_damage;
    int m_loot;

public:
    BattleCards(std::string type, int force, int damage, int loot) : Card(type), m_force(force),
                                                                 m_damage(damage), m_loot(loot)
    {}

    void applyCard(Player &player) override;

protected:
    virtual void applyCardDamage(Player &player);

    void applyCardWins(Player &player);

    bool cardWins(Player &player);

    virtual void printCard(std::ostream& os) override;
};

class SpecialCards : public Card
{
protected:
    int m_fall_fight_damage;
    int m_heal;

public:
    SpecialCards(std::string type, int fall_fight_damage, int heal) : Card(type),
                                                                      m_fall_fight_damage(fall_fight_damage),
                                                                      m_heal(heal)
    {}

    void applyCard(Player &player) override;

    virtual void applyPeacefulCard(Player &player) = 0;
};

class FinanceCards : public Card
{
protected:
    int m_Treasure;

public:
    FinanceCards(std::string  type, int treasure) : Card(type), m_Treasure(treasure)
    {}

    void applyCard(Player &player) override;
    virtual void applyFinanceCard(Player &player) = 0;
};

#endif //EX4_CARD_H
