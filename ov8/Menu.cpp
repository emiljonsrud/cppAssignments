#include "std_lib_facilities.h"
#include <functional>

#include "MenuItem.h"
#include "Menu.h"

Menu::Menu() {
    MenuItem quit = {
        "Exit menu", 
        []() {
            cout << "Exiting menu" << endl;
        }
    };
    menu.push_back(quit);

    showMenu = true;
}



//      PRIVATE      
void Menu::printMenu() {
    int menuLength = menu.size();
    cout << "Please choose an option (0-" << menuLength - 1 << ")." << endl; 
    for (int i = 0; i < menuLength; i++) {
        cout << "  " << i << ") " << menu.at(i).getName() << endl;
    }
    cout << "> ";
}
void Menu::selectItem() {
    int inpChoice = 0;

    while(!(cin >> inpChoice)) {
        cout << "Please insert an integer.\n> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    if (( (inpChoice < 0) || (inpChoice >= static_cast<int>(menu.size())) )) {
        string errMsg = "This is not an option: " + to_string(inpChoice);
        throw std::invalid_argument(errMsg);

    } else if (inpChoice == 0) {
        showMenu = false;

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
        cout << endl;
        printMenu();
        try {
            selectItem();
        } catch (std::invalid_argument argExeption) {
            cout << "Error: " << argExeption.what() << endl;
        }
    }
    cout << "-------- Exiting menu --------\n\n" << endl;
}





