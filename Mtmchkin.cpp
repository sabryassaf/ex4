//
// Created by royb9 on 17/01/2023.
//

#include "Mtmchkin.h"
#include "utilities.h"

void Mtmchkin::playCard(unique_ptr<Player>& player)
{
    unique_ptr<Card> card = std::move(this->m_deck.front());
    this->m_deck.pop();
    card->applyCard(*player);
    this->m_deck.push(std::move(card));
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(this->m_current_round);

    for (std::unique_ptr<Player>& player: this->m_players)
    {
        if (nullptr == player)
        {
            continue;
        }

        printTurnStartMessage(player->getName());
        this->playCard(player);

        if (player->isKnockedOut())
        {
            this->m_losers.push_back(std::move(player));
        }
        else if (player->isMaxLevel())
        {
            this->m_winners.push_back(std::move(player));
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

    for (const std::unique_ptr<Player>& player: this->m_winners)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for (const std::unique_ptr<Player>& player: this->m_players)
    {
        i++;
        printPlayerLeaderBoard(i, *player);
    }
    for (const std::unique_ptr<Player>& player: this->m_losers)
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
