//
//

#include "Mtmchkin.h"
#include "Exceptions.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "Cards/Card.h"
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/HitPoints.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "utilities.h"

Mtmchkin::Mtmchkin(const std::string &fileName) : m_round(0), m_lineNumber(0)
{
    try
    {
        std::ifstream file(fileName);
//        std::cout << !file.is_open() << std::endl;
        if (!file.is_open())
        {
            throw std::runtime_error("need to change it");
        }
        std::string line;

        while (std::getline(file, line))
        {
            try
            {
                addCard(line);
                m_lineNumber++;

            }
            catch (...)
            {
                printf("hi");
            }
        }
    }
    catch (...)
    {
        printf("end");
    }
    startGame();
}

void Mtmchkin::playCard(std::unique_ptr<Player>& player)
{
    std::unique_ptr<Card> card = std::move(this->m_deck.front());
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

void Mtmchkin::startGame()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int i = getPlayerCount();
    for (int x = 0; x < i; x++)
    {
        addPlayer();
    }
}

void Mtmchkin::addPlayer()
{
    printInsertPlayerMessage();
    std::string name, className;
    std::cin >> name >> className;
    while (!testPlayerNameClass(name, className))
    {

    }

}

bool Mtmchkin::testPlayerNameClass(std::string name, std::string className)
{
    if (className != "Warrior" && className != "Ninja" && className != "Healer")
    {
        return false;
    }
    for (std::unique_ptr<Player> & it : m_players)
    {
        if (it->getName() == name && it->getPlayerType() == className)
        {
            return false;
        }
    }

    /* TODO */
    return true;
}

int Mtmchkin::getPlayerCount()
{
    int input = 0;
    bool Flag = false;
    while (!Flag)
    {
        try
        {
            std::cin >> input;
            if (std::cin.fail())
            {
                throw std::invalid_argument("");
            }
            if (input < 2 || input > 6)
            {
                printInvalidTeamSize();
                throw std::out_of_range("");
            }
            Flag = true;
        }
        catch (const std::exception &e)
        {
// not sure what to do here
        }
    }
    return input;
}

void Mtmchkin::addCard(std::string line)
{
    if (line == "Witch")
    {
        std::unique_ptr<Card> temp(new Witch());
        m_deck.push(std::move(temp));
    } else if (line == "Well")
    {
        std::unique_ptr<Card> temp(new Well());
        m_deck.push(std::move(temp));
    } else if (line == "Treasure")
    {
        std::unique_ptr<Card> temp(new Treasure());
        m_deck.push(std::move(temp));
    } else if (line == "Merchant")
    {
        std::unique_ptr<Card> temp(new Merchant());
        m_deck.push(std::move(temp));
    } else if (line == "Mana")
    {
        std::unique_ptr<Card> temp(new Mana());
        m_deck.push(std::move(temp));
    } else if (line == "Gremlin")
    {
        std::unique_ptr<Card> temp(new Gremlin());
        m_deck.push(std::move(temp));
    } else if (line == "Dragon")
    {
        std::unique_ptr<Card> temp(new Dragon());
        m_deck.push(std::move(temp));
    } else if (line == "Barfight")
    {
        std::unique_ptr<Card> temp(new Barfight());
        m_deck.push(std::move(temp));
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
