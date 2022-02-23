#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "SixDeck.h"
#include "Blackjack.h"
#include "Hand.h"
#include "Options.h"

void playBlackjack() {
    Blackjack game;

    while (game.getPlayerBalance() > 50) {
        
        game.preGameWager();
        game.printGame();
        game.dealPlayer();
        game.printGame();
        game.dealDealer();
        
        game.printResult();
    }
    cout << "You are broke" << endl;
}