#include "std_lib_facilities.h"

#include "MenuItem.h"
#include "Menu.h"

#include "exersizeFunctions.h"

#include "Animal.h"





int main()
{
    Menu menu;

    menu.addItem({
        "Print animals",
        []() {
           testAnimal();
        }
    });

    //          Oppgave 1
    /*
        a)  Public er tilgjengelig globalt for alle funksjoner
            Private er bare tilgjengelig for medlemsfunksjoner til klassen
            Protected er tilgjenelig for etterkommere av klassen. (Arvere)

    */  


    //           Oppgave 2
    menu.addItem({
        "Test emoji",
        []() {
            testEmoji();
        }
    });

    




    menu.activateMenu();
}