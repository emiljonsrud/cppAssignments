#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

CardDeck::CardDeck() {
    for (int i = 0; i < 4; i++) {
        for (
            int j = static_cast<int>(Rank::two); 
            j <= static_cast<int>(Rank::ace);
            j++
            ) {
                Card currentCard = {
                    static_cast<Suit>(i),
                    static_cast<Rank>(j)
                };
                cards.push_back(currentCard);
            }
    }
}
void CardDeck::swap(int card1, int card2) {
    Card tempCard = cards.at(card1);
    cards.at(card1) = cards.at(card2);
    cards.at(card2) = tempCard;
}
void CardDeck::print() {
    for (int i = 0; i < cards.size(); i++) {
        cout << cards.at(i).toString() << endl;
    }
}
void CardDeck::shuffle() {
    for(int i = 0; i < 100000; i++) {
        int numberOfCards = cards.size();
        int card1 = rand()%numberOfCards;
        int card2 = rand()%numberOfCards;
        
        int intervall = rand()%(numberOfCards/2);
        for (int j = 0; j < intervall; j++) {
            CardDeck::swap(
                (card1+j)%numberOfCards,
                (card2+j)%numberOfCards
            );
        }        
    }
}
Card CardDeck::drawCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

