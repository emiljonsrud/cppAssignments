#include "std_lib_facilities.h"
#include "Card.h"

Card::Card(Suit s, Rank r): suit{s}, rank{r}
{}

Suit Card::getSuit() {
    return suit;
}
Rank Card::getRank() {
    return rank;
}
string Card::toString() {
    string suitStr = suitToString(suit);
    string rankStr = rankToString(rank);
    string combinedStr = rankStr + " of " + suitStr;
    
    return combinedStr;
}


string suitToString(Suit suit) {
    if (suit == Suit::clubs) {return "Clubs";}
    else if (suit == Suit::diamonds) {return "Diamonds";}
    else if (suit == Suit::hearts) {return "Hearts";}
    else if (suit == Suit::spades) {return "Spades";}

    return "None";
}

string rankToString(Rank rank) {
    if (rank == Rank::two) {return "Two";}
    if (rank == Rank::three) {return "three";}
    if (rank == Rank::four) {return "Four";}
    if (rank == Rank::five) {return "Five";}
    if (rank == Rank::six) {return "Six";}
    if (rank == Rank::seven) {return "Seven";}
    if (rank == Rank::eight) {return "Eight";}
    if (rank == Rank::nine) {return "Nine";}
    if (rank == Rank::ten) {return "Ten";}
    if (rank == Rank::jack) {return "Jack";}
    if (rank == Rank::queen) {return "Queen";}
    if (rank == Rank::king) {return "King";}
    if (rank == Rank::ace) {return "Ace";}

    return "None";
}





