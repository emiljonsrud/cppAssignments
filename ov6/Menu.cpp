#include "std_lib_facilities.h"
#include "MenuItem.h"
#include "Menu.h"

Menu::Menu() {
    MenuItem quit;
    quit.setName("Quit");
    function<void()> func = []() {
        cout << "Exiting menu" << endl;
    };
    quit.setFunction(func);
    menu.push_back(quit);

    showMenu = true;
}



//      PRIVATE      
void Menu::printMenu() {
    int menuLength = menu.size();
    cout << "Please choose an option (0-" << menuLength << ")." << endl; 
    for (int i = 0; i < menuLength; i++) {
        cout << "  " << i << ") " << menu.at(i).getName() << endl;
    }
    cout << "> ";
}
void Menu::selectItem() {
    int inpChoice = 0;

    input: ;
    cin >> inpChoice;

    if (inpChoice == 0) {showMenu = false;}
    if (inpChoice < 0 or inpChoice > menu.size()) {
        cout << "Please insert a valid integer" << endl;
        goto input;
    } else {
        menu.at(inpChoice).execute();
    }
}


//      PUBLIC
void Menu::addItem(MenuItem m) {
    menu.push_back(m);
}
void Menu::activateMenu() {
    while (showMenu) {
        printMenu();
        selectItem();
    }
}





