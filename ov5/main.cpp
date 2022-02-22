#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "SixDeck.h"
#include "Blackjack.h"
#include "Hand.h"
#include "blackjack.h"
/*
    # Teoridel

    ## Oppgave 1e 
    Her er det lurt med enumerate, siden vi kan koble opp mot 
    fargekortene.

    ## Oppgave 3c
    Denne funksjoner burde være private, siden den bare skal 
    brukes av klassen


*/
void separate() {
    cout << "\n" << endl;
}


int main()
{
    srand(unsigned(time(nullptr)));
    /*
	// Tester opg1
    Rank r = Rank::ace;
    Suit s = Suit::spades;

    cout << "Rank: " << rankToString(r) << endl;
    cout << "Suit: " << suitToString(s) << endl;
    separate();

    //Tester opg2
    Card c{Suit::diamonds, Rank::queen};
    cout << c.toString() << endl;
    separate();

    //Tester op3

    
    deck.print();
    deck.shuffle();
    cout << endl;
    deck.print();
    */

    playBlackjack(); 
    
    

}


    
    
    
    
    
    