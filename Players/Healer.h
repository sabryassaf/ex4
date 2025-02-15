//
// Created by royb9 on 11/01/2023.
//

#ifndef _HEALER_H
#define _HEALER_H

#include "Player.h"

class Healer : public Player
{
public:
    explicit Healer(std::string name);

    std::string getPlayerType() const override;
    void heal(int healLevel) override;
    void playerInfo(std::ostream &os) const override;
};


#endif //_HEALER_H
