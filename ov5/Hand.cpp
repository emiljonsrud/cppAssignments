#include "std_lib_facilities.h"
#include "Card.h"
#include "Hand.h"
#include "Blackjack.h"


Hand::Hand() {
    vector<Card> hand;
}

void Hand::addCard(Card card) {
    hand.push_back(card);
}
void Hand::clearHand() {
    hand.clear();
}


int Hand::numberOfCards() {
    return hand.size();
}
Card Hand::getCard(int i) {
    return hand.at(i);
}
Card Hand::takeTopCard() {
    Card topCard = hand.back();
    hand.pop_back();
    return topCard;
}
