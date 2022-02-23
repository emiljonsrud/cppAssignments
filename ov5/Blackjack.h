#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "SixDeck.h"
#include "Hand.h"
#include "Options.h"
#include "BankAccount.h"

// dette er fra thinkboi


class Blackjack {
    private:
        SixDeck deck;
        vector<Hand> playerHands;
        Hand dealerHand;
        BankAccount balance;
        int bet;

        void dealNewCards();
        void printPlayerHands();


        bool dealerStand();
        void hit(int handInt);
        void hitLoop(int handInt);
        void split(int handInt);

        bool playerBlackjack();
        bool dealerBlackjack();
        bool playerBust(int handInt);
        bool dealerBust();
        int getCardScore(Card card);
        int playerScore(int handInt);
        int dealerScore();

        void printOptions(int handInt);
        vector<Option> legalOptions(int handInt);
        Option playerInput(int handInt);
        bool legalOption(Option option, int handInt);

        int numberOfHands();

        void getBet();
        bool legalWager(int inp);

    public:
        Blackjack();

        void preGameWager(); 
        int getPlayerBalance();

        void dealPlayer();
        void dealDealer();
        void printGame();
        void printResult();
        
};

bool checkBust(int score);
bool checkBlackjack(int score);
