#include "MenuItem.h"
#include "Menu.h"

#include <iostream>
#include <functional>

Menu::Menu() {
    MenuItem quit = {
        "Exit menu", 
        []() {
            std::cout << "Exiting menu" << std::endl;
        }
    };
    menu.push_back(quit);

    showMenu = true;
}



//      PRIVATE      
void Menu::printMenu() {
    int menuLength = menu.size();
    std::cout << "Please choose an option (0-" << menuLength - 1 << ")." << std::endl; 
    for (int i = 0; i < menuLength; i++) {
        std::cout << "  " << i << ") " << menu.at(i).getName() << std::endl;
    }
    std::cout << "> ";
}
void Menu::selectItem() {
    int inpChoice = 0;

    while(!(std::cin >> inpChoice)) {
        std::cout << "Please insert an integer.\n> ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };

    if (( (inpChoice < 0) || (inpChoice >= static_cast<int>(menu.size())) )) {
        std::string errMsg = "This is not an option: " + std::to_string(inpChoice);
        throw std::invalid_argument(errMsg);

    } else if (inpChoice == 0) {
        showMenu = false;

    } else {
        menu.at(inpChoice).execute();
    }
}


//      PUBLIC

//  Add a MenuItem on the form 
// MenuItem {
//     "Name",
//     []() {
//         /* function contents*/
//     }
// }
void Menu::addItem(MenuItem m) {
    menu.push_back(m);
}
void Menu::activateMenu() {
    while (showMenu) {
        std::cout << std::endl;
        printMenu();
        try {
            selectItem();
        } catch (std::invalid_argument argExeption) {
            std::cout << "Error: " << argExeption.what() << std::endl;
        }
    }
    std::cout << "-------- Exiting menu --------\n\n" << std::endl;
}





