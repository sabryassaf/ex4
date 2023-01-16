//
// Created by soso_ on 1/12/2023.
//
#include "Merchant.h"

void Merchant::applyFinanceCard(Player &player)
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());
    bool temp = false;
    string input;
    int x;
    while (!temp)
    {
        getline(cin, input);
        try{
            x = stoi(input);
        }
        if (input == 0 || input == 1 || input == 2)
        {

        }
    }
}

