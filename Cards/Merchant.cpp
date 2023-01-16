//
// Created by soso_ on 1/12/2023.
//
#include "Merchant.h"

void Merchant::applyFinanceCard(Player &player)
{
//    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());
    string input;
    int x;
    while (true)
    {
        getline(cin, input);
        if (input != "0" && input != "1" && input != "2")
        {
//            printInvalidInput();
            continue;
        }
        try
        {
            x = stoi(input);
            applyPayment(cout, player, x);
            break;
        }
        catch (std::invalid_argument &e)
        {
            //printInvalidInput();
        }
    }

}

void Merchant::applyPayment(ostream &os, Player &player, int x)
{
    switch (x)
    {
        case 0:
//            printMerchantSummary(os, player.getName(), 0, 0);
            return;
        case 1:
            if (player.getCoins() < 5)
            {
//                printMerchantInsufficientCoins(os);
                return;
            } else
            {
                player.pay(5);
                player.heal(1);
//                printMerchantSummary(os, player.getName(), 1, 5);
                return;
            }
        case 2:
            if (player.getCoins() < 10)
            {
//                printMerchantInsufficientCoins(os);
                return;
            } else
            {
                player.pay(10);
                player.buff(1);
//                printMerchantSummary(os, player.getName(), 2, 10);
                return;
            }
    }
}
