//
// Created by soso_ on 1/15/2023.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName) : m_Round(0), m_Line_Number(0)
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
                m_Line_Number++;

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
    for (std::unique_ptr<Player> & it: m_PlayersQueue)
    {
        if (it->getName() == name && it->getPlayerType() == className)
        {
            return false;
        }
    }

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
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Well")
    {
        std::unique_ptr<Card> temp(new Well());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Treasure")
    {
        std::unique_ptr<Card> temp(new Treasure());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Merchant")
    {
        std::unique_ptr<Card> temp(new Merchant());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Mana")
    {
        std::unique_ptr<Card> temp(new Mana());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Gremlin")
    {
        std::unique_ptr<Card> temp(new Gremlin());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Dragon")
    {
        std::unique_ptr<Card> temp(new Dragon());
        m_CardDeck.push_back(std::move(temp));
    } else if (line == "Barfight")
    {
        std::unique_ptr<Card> temp(new Barfight());
        m_CardDeck.push_back(std::move(temp));
    }


}