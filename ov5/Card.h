#pragma once

enum class Suit {
    clubs,
    diamonds,
    hearts,
    spades
};
enum class Rank{
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13,
    ace = 14
};
class Card{
private:
    Suit s;
    
}


string suitToString(Suit suit);
string rankToString(Rank rank);

