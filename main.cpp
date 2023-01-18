
#include <iostream>
#include <vector>
#include "Mtmchkin.h"

using namespace std;

int main()
{
    try
    {
        Mtmchkin game("deck.txt");

        /* Use for instead of while to prevent infinite game loop. */
        for (int i = 0; i < 100; ++i)
        {
            game.playRound();
            game.printLeaderBoard();

            if (game.isGameOver())
            {
                break;
            }
        }
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
