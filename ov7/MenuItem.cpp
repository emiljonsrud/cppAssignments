#include "std_lib_facilities.h"
#include <functional>

#include "MenuItem.h"



MenuItem::MenuItem(string n, function<void()> f) {
    name = n;
    func = f;
}


string MenuItem::getName() {
    return name;
}

void MenuItem::execute() {
    func();
}


