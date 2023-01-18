#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Cards/Card.h"
#include <vector>
#include <memory>
#include <fstream>
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
#include <stdexcept>
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/HitPoints.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
class Mtmchkin{
private:
    int m_Round;
    int m_Line_Number;
    std::vector<std::unique_ptr<Card>> m_CardDeck;
    std::vector<std::unique_ptr<Player>> m_PlayersQueue;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    void addCard(std::string line);
    void startGame();
    int getPlayerCount();
    void addPlayer();
    bool testPlayerNameClass(std::string name, std::string className);
};



#endif /* MTMCHKIN_H_ */
