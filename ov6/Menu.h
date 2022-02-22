#pragma once
#include "std_lib_facilities.h"
#include "MenuItem.h"

class Menu {
private:
    vector<MenuItem> menu;
    bool showMenu;

    void printMenu();
    void selectItem();

public:
    Menu();
    void addItem(MenuItem m);
    void activateMenu();


};