//
// Created by royb9 on 11/01/2023.
//

#ifndef _NINJA_H
#define _NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
    explicit Ninja(const char* name);

    void addCoins(int money) override;
    void playerInfo(std::ostream& os) const override;
};


#endif //_NINJA_H
