//
// Created by soso_ on 1/12/2023.
//

#include "Treasure.h"

void Treasure::applyFinanceCard(Player &player)
{
    player.addCoins(m_Treasure);
    printTreasureMessage();
}
