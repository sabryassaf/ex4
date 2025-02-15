#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <memory>
#include <queue>
#include <vector>
#include <fstream>
#include "Players/Player.h"
#include "Cards/Card.h"

class Mtmchkin
{
private:
    int m_round;

    std::vector<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;

    std::queue<std::unique_ptr<Card>> m_deck;

    /**
     * Have the given `player` draw and play the next card in the deck.
     *
     * @param player The player that plays the current turn.
     * */
    void playCard(std::unique_ptr<Player>& player);

    void addCard(const std::string& line);
    void startGame();
    static int getPlayerCount();
    void addPlayer();
    bool testPlayerNameClass(const std::string& name, const std::string& className);

public:
    Mtmchkin(Mtmchkin&) = delete;
    Mtmchkin operator=(Mtmchkin&) = delete;

    /**
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& fileName);

    /**
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /**
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /**
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /**
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};


#endif /* MTMCHKIN_H_ */
