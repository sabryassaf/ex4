//
// Created by Roy Bar-On on 21/12/2022.
//

#ifndef _HITPOINTS_H
#define _HITPOINTS_H

#include <iostream>

class HitPoints
{
private:
    const static int DEFAULT_MAX_HP = 100;

    int m_maxHP;
    int m_currentHP{};

    HitPoints(int maxHp, int currentHP);

    void setHP(int value);

public:
    HitPoints(int maxHp=DEFAULT_MAX_HP);

    int get_current() const;

    HitPoints operator+(int value) const;
    HitPoints operator-(int value) const;
    friend HitPoints operator+(int value, const HitPoints& hp);
    friend HitPoints operator-(int value, const HitPoints& hp);
    void operator+=(int value);
    void operator-=(int value);

    bool operator==(HitPoints other) const;
    bool operator!=(HitPoints other) const;
    bool operator>(HitPoints other) const;
    bool operator<(HitPoints other) const;
    bool operator>=(HitPoints other) const;
    bool operator<=(HitPoints other) const;

    bool operator==(int other) const;
    bool operator!=(int other) const;
    bool operator>(int other) const;
    bool operator<(int other) const;
    bool operator>=(int other) const;
    bool operator<=(int other) const;
    friend bool operator==(int value, const HitPoints& hp);
    friend bool operator!=(int value, const HitPoints& hp);
    friend bool operator>(int value, const HitPoints& hp);
    friend bool operator<(int value, const HitPoints& hp);
    friend bool operator>=(int value, const HitPoints& hp);
    friend bool operator<=(int value, const HitPoints& hp);

    friend std::ostream& operator<<(std::ostream& os, const HitPoints& hp);

    /* Exceptions */
    class InvalidArgument{};
};


#endif //_HITPOINTS_H
