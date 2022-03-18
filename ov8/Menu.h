#pragma once
#include "MenuItem.h"

#include <vector>


class Menu {
private:
    std::vector<MenuItem> menu;
    bool showMenu;

    void printMenu();
    void selectItem();

public:
    Menu();
    void addItem(MenuItem m);
    void activateMenu();


};