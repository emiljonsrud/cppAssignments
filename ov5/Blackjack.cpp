#include "std_lib_facilities.h"
#include "Blackjack.h"
#include "Card.h"
#include "SixDeck.h"
#include "Hand.h"
#include "Options.h"
#include "BankAccount.h"

#include <unistd.h>

Blackjack::Blackjack() {
    deck.shuffle();
    dealNewCards();

    balance.setBalance(1000);
}
bool checkBlackjack(int score) {
    return score == 21;
}


void Blackjack::dealNewCards() {
    playerHands.clear();
    dealerHand.clearHand();

    Hand playerHand;

    for (int i = 0; i < 2; i++) {
        playerHand.addCard(deck.drawCard());
        dealerHand.addCard(deck.drawCard());
    }
    
    playerHands.push_back(playerHand);

}

//      MONEY
bool Blackjack::legalWager(int inp) {
    return (inp%25 == 0 and inp >= 50);
}

void Blackjack::getBet() {
    cout << "How much would you like to bet? \nMinimum bet is 50, smallest chip is 25.\n> ";
    int wager = 0;

inputWager: 
    cin >> wager;
    if (not legalWager(wager)) {
        while (not legalWager(wager)){
            cout << "Please insert a valid amount\n> ";
            cin >> wager;
        }
    }
    if (balance.getBalance() < wager) {
        cout << "You don't have this much money. Please try a lower amount.\n> ";
        goto inputWager;
    }
    bet = wager;
}

void Blackjack::preGameWager() {
    cout << "\n"
         << setfill('#')
         << setw(60) << endl;
    cout << "\nYou have a balance of " << balance.getBalance() << endl;
    getBet();
    balance.subtract(bet);
    dealNewCards();
}

int Blackjack::getPlayerBalance() {
    return balance.getBalance();
}



//          BLACKJACK
bool Blackjack::playerBlackjack() {
    return playerScore(0) == 21;
}
bool Blackjack::dealerBlackjack() {
    return dealerScore() == 21;
}

bool Blackjack::playerBust(int handInt) {
    int score = playerScore(handInt);
    if (score > 21) {return true;}
    else {return false;}
}
bool Blackjack::dealerBust() {
    int score = dealerScore();
    if (score > 21) {return true;}
    else {return false;}
}

void Blackjack::hit(int handInt) {
    playerHands.at(handInt).addCard(deck.drawCard());
}
void Blackjack::hitLoop(int handInt) {
    do {
        hit(handInt);
        printGame();
        cout << "You are currently at hand nr. " << handInt << endl;
        if (playerScore(handInt) >= 21) {break;}
    } while (playerInput(handInt) == Option::hit);
}

void Blackjack::split(int handInt) {
    Card card1 = playerHands.at(handInt).takeTopCard();
    Hand newHand;
    newHand.addCard(card1);

    // Tror disse linjene setter inn newHand i posisjonen rett 
    // bak handInt, men jeg er ikke helt sikker på hvordan det 
    // fungerer.
    auto playerHandPos =  playerHands.begin() + handInt + 1;
    playerHands.insert(playerHandPos, newHand);

    hit(handInt);
    hit(handInt + 1);
}
bool Blackjack::dealerStand() {
    return (dealerScore() > 16);
}



//          START
void Blackjack::dealPlayer() {
    for (int i = 0; i < numberOfHands(); i++) {
        cout << "You are at hand nr. " << i << endl;
        
        Option playerOption = Option::hold;
        
        if (playerBlackjack()) {
            cout << "Blackjack!" << endl;
            balance.add(bet*0.5);
            goto endHand;
        }

    reInput: ;
        playerOption = playerInput(i);
        if (playerOption == Option::hit) {
            hitLoop(i);
            if (playerBust(i)) {
                printGame();
                cout << playerScore(i) << "! You busted" << endl;
                sleep(4);
            } else {
                sleep(2);
            }
        }

        else if (playerOption == Option::doubleDown) {
            hit(i);
            if (balance.getBalance() < bet) {
                cout << "You dont have enough money for this." << endl;
                goto reInput;
            } else {
                balance.subtract(bet);
                bet = bet*2;
                cout << "You doubled down"  << endl;
            }
        }

        else if (playerOption == Option::split) {
            
            if (balance.getBalance() < bet) {
                cout << "You dont have enough money for this." << endl;
                goto reInput;
            } else {
                split(i);
                balance.subtract(bet);
                printGame();
                i--; 
            }
            
        }
    endHand: ;
    }
}


void Blackjack::dealDealer() {
    cout << "Dealer has:" << endl;
    sleep(1);
    Card card0 = dealerHand.getCard(0);
    Card card1 = dealerHand.getCard(1);
    
    cout << card0.toString() << setfill('.') << setw(15) 
    << getCardScore(card0) << endl;
    sleep(1);
    cout << dealerHand.getCard(1).toString() << setfill('.') << setw(15) 
    << getCardScore(card0) + getCardScore(card1) << endl;
    sleep(2);

    if(dealerBlackjack()) {
        cout << "Dealer has Blackjack! " << endl; 
    }


    while (not dealerStand() ) {

        Card newCard = deck.drawCard();
        dealerHand.addCard(newCard);

        cout << newCard.toString() << setfill('.') << setw(15) 
        << dealerScore() << endl;
        sleep(2);
        
    }
    if (dealerBust()) {
        cout << dealerScore() << "! Dealer busted" << endl;
    }
}
int Blackjack::getCardScore(Card card) {
    int cardInt = static_cast<int>(card.getRank());
    if (cardInt < static_cast<int>(Rank::jack)) {return cardInt;}
    else if (cardInt == static_cast<int>(Rank::ace)) {return 11;}
    else {return 10;}
}

int Blackjack::playerScore(int handInt) {
    int score = 0;
    int numberOfAce = 0;
    Hand hand = playerHands.at(handInt);

    for (int i = 0; i < hand.numberOfCards(); i++) {
        Card card = hand.getCard(i);
        int cardInt = static_cast<int>(card.getRank());

        if (cardInt < 11) {
            score += cardInt;
        } else if (card.getRank() == Rank::ace) {
            numberOfAce++;
            score += 11;
        } else {
            score += 10;
        }
    }
    for (int i = 0; i < numberOfAce; i++) {
        if (score > 21) {
            score -= 10;
        }
    }
    return score;
}

int Blackjack::dealerScore() {
    int score = 0;
    int numberOfAce = 0;
    Hand hand = dealerHand;

    for (int i = 0; i < hand.numberOfCards(); i++) {
        Card card = hand.getCard(i);
        int cardInt = static_cast<int>(card.getRank());

        if (cardInt < static_cast<int>(Rank::jack)) {
            score += cardInt;
        } else if (card.getRank() == Rank::ace) {
            numberOfAce++;
            score += 11;
        } else {
            score += 10;
        }
    }
    for (int i = 0; i < numberOfAce; i++) {
        if (score > 21) {
            score -= 10;
        }
    }
    return score;
}


void Blackjack::printPlayerHands() {
    int numberOfHands = playerHands.size();
    for (int handIndex = 0; handIndex < numberOfHands; handIndex++) {
        Hand hand = playerHands.at(handIndex);
        cout << "\nAt hand nr. " << handIndex << ", you have:" << endl;
        for (int j = 0; j < hand.numberOfCards(); j++) {
            int lastCard = hand.numberOfCards() - 1;
            if (j == lastCard) {sleep(2);}
            std::cout << "    " << hand.getCard(j).toString();
            if (j == lastCard) {
                sleep(1);
                cout << setfill('.') << setw(10) << playerScore(handIndex) << endl;

            } else {cout << endl;}
        }
        sleep(2);
    }
};

void Blackjack::printGame() {
    cout << "\n"
         << setfill('#')
         << setw(60);
    cout << "\nYou have a balance of " << balance.getBalance() << endl;
    cout << "Current bet: " << bet << endl;

    cout << "\n\nThe dealer has " << dealerHand.getCard(0).toString() << ". ("
    << getCardScore(dealerHand.getCard(0)) << ")" << endl;
    
    printPlayerHands();
    cout << endl;
}
void Blackjack::printResult() {
    for (int i = 0; i < numberOfHands(); i++) {

        int dScore = dealerScore();
        int pScore = playerScore(i);
        cout << "\nAt hand nr. " << i << endl;

        if ( playerBust(i) ) {
            cout << "You busted" << endl;
            bet = 0;
            goto endHand;
        }

        else if ( dealerBust() ) {
            cout << "Dealer busted. You win!" << endl;
            balance.add(bet*2);
            goto endHand;
        }

        cout << "    Dealer has " << dScore << ", you have " << pScore << endl;

        if ( pScore < dScore ) {
            cout << "Dealer wins" << endl;
            bet = 0;
        }

        else if (pScore == dScore) {
            cout << "It's a push" << endl;
            balance.add(bet);
        }

        else if (pScore > dScore) {
            cout << "You win!" << endl;
            balance.add(bet*2);
        }
    endHand: ;
    }
    cout << "New balance: " << balance.getBalance() << endl;
}



void Blackjack::printOptions(int handInt) {
    Hand hand = playerHands.at(handInt);

    cout << "You can:" << endl;
    cout << "    (1) Hit" << endl;
    cout << "    (2) Hold" << endl;
    if (hand.numberOfCards() == 2) {
        cout << "    (3) Double" << endl;
        if (hand.getCard(0).getRank() == hand.getCard(1).getRank()) {
            cout << "    (4) Split" << endl;
        }
    }
}
vector<Option> Blackjack::legalOptions(int handInt) {
    Hand hand = playerHands.at(handInt);
    vector<Option> legalOptions = {Option::hit, Option::hold};

    if (hand.numberOfCards() == 2) {
        legalOptions.push_back(Option::doubleDown);
        if (hand.getCard(0).getRank() == hand.getCard(1).getRank()) {
            legalOptions.push_back(Option::split);
        }
    }
    return legalOptions;
}
bool Blackjack::legalOption(Option option, int handInt) {
    vector<Option> legalOption = legalOptions(handInt);

    for (int i = 0; i < legalOption.size(); i++) {
        if (option == legalOption.at(i)) {return true;}
    }
    return false;
}

Option Blackjack::playerInput(int handInt) {
    for (int handIndex = 0; handIndex < playerHands.size(); handIndex++) {
        printOptions(handIndex);
        int userInp = 0;
        
        cout << "What would you like to do? (Choose a number)\n> ";
        cin >> userInp;
        input:
        if (not legalOption(static_cast<Option>(userInp), handInt)) {
            cout << "Please input a valid integer." << endl;
            cin >> userInp;
            goto input;
        }
        cout << endl;

        return static_cast<Option>(userInp);
    }
}

int Blackjack::numberOfHands() {
    return playerHands.size();
}




