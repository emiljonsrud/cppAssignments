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

    menu.activateMenu();




}