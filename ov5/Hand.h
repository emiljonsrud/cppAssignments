#pragma once
#include "Card.h"

class Hand {
    private:
        vector<Card> hand;
    public:
        Hand();
        void addCard(Card card);
        void clearHand();
        int numberOfCards();
        Card getCard(int i);
        Card takeTopCard();

};