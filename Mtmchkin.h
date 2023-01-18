#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Cards/Card.h"
#include <vector>
#include <memory>
#include <fstream>
#include "Exceptions.h"
#include <stdexcept>
#include <queue>
class Mtmchkin{
private:
    int m_round;
    int m_lineNumber;
    std::queue<std::unique_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Player>> m_players;
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
