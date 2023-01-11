//
// Created by royb9 on 11/01/2023.
//

#ifndef _WARRIOR_H
#define _WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    explicit Warrior(const char* name);

    int getAttackStrength() const override;
    void playerInfo(std::ostream &os) const override;
};

#endif //_WARRIOR_H
