#include "std_lib_facilities.h"

#include "MenuItem.h"
#include "Menu.h"





int main()
{
    Menu menu;

    menu.addItem({
        "test option",
        []() {
            cout << "this" << endl;
            cout << "is" << endl;
            cout << "working" << endl;
        }
    });

    //          Oppgave 1
    /*
        a)  Public er tilgjengelig globalt for alle funksjoner
            Private er bare tilgjengelig for medlemsfunksjoner til klassen
            Protected er tilgjenelig for etterkommere av klassen. (Arvere)

    */  

    




    menu.activateMenu();
}