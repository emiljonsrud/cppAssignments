#include "MenuItem.h"

#include <iostream>
#include <functional>


MenuItem::MenuItem(std::string n, std::function<void()> f) {
    name = n;
    func = f;
}


std::string MenuItem::getName() {
    return name;
}

void MenuItem::execute() {
    func();
}


