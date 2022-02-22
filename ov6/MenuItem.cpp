#include "std_lib_facilities.h"
#include "MenuItem.h"


MenuItem::MenuItem() {

}

void MenuItem::setName(string str) {
    name = str;
}
string MenuItem::getName() {
    return name;
}

void MenuItem::setFunction(function<void()> f) {
    func = f;
}
void MenuItem::execute() {
    func();
}


