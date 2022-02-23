#pragma once
#include "Card.h"

class SixDeck {
    private:
        vector<Card> cards;
        void swap(int card1, int card2);
    public:
        SixDeck();
        void print();
        void shuffle();
        Card drawCard();

};
