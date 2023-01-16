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
class Mtmchkin{
private:
    int m_Round;
    int m_Line_Number;
    vector<std::shared_ptr<Card>> m_CardDeck;
    vector<Player> m_PlayersQueue;
    std::shared_ptr<Witch> m_Witch;
    std::shared_ptr<Well> m_Well;
    std::shared_ptr<Treasure> m_Treasure;
    std::shared_ptr<Merchant> m_Merchant;
    std::shared_ptr<Mana> m_Mana;
    std::shared_ptr<Gremlin> m_Gremlin;
    std::shared_ptr<Dragon> m_Dragon;
    std::shared_ptr<Barfight> m_Barfight;
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
    int getRoundsNumberFromUser();
    void addPlayer();
};



#endif /* MTMCHKIN_H_ */
