#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck {
    private:
        vector<Card> cards;
        void swap(int card1, int card2);
    public:
        CardDeck();
        void print();
        void shuffle();
        Card drawCard();

};
