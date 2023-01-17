//
// Created by royb9 on 17/01/2023.
//

#include "Mtmchkin.h"
#include "utilities.h"

void Mtmchkin::playCard(Player* player)
{
    Card* card = this->m_deck.front();
    this->m_deck.pop_front();
    card->applyCard(*player);
    this->m_deck.push_back(card);
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(this->m_current_round);

    for (auto it = this->m_players.begin(); it != this->m_players.end(); ++it)
    {
        Player* player = *it;

        printTurnStartMessage(player->getName());
        this->playCard(player);

        if (player->isKnockedOut())
        {
            this->m_losers.push_back(player);
            it = this->m_players.erase(it);
            --it;
        }
        if (player->isMaxLevel())
        {
            this->m_losers.push_front(player);
            it = this->m_players.erase(it);
            --it;
        }
    }

    this->m_current_round++;
    if (this->isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    int i = 0;
    printLeaderBoardStartMessage();

    for (Player* player: this->m_winners)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for (Player* player: this->m_players)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for (Player* player: this->m_losers)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
}

bool Mtmchkin::isGameOver() const
{
    return this->m_players.empty();
}

int Mtmchkin::getNumberOfRounds() const
{
    return this->m_current_round;
}
