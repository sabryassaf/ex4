//
// Created by soso_ on 1/12/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include <Card.h>

class Witch : public BattleCards
{
private:
public:
    Witch(string& type) : BattleCards(type,11,10,2)
    {}

};

#endif //EX4_WITCH_H
