#include "std_lib_facilities.h"
#include "MenuItem.h"
#include <functional>



MenuItem::MenuItem() {

}

void MenuItem::setName(string str) {
    name = str;
}
string MenuItem::getName() {
    return name;
}

void MenuItem::setFunction(std::function<void()> f) {
    func = f;
}
void MenuItem::execute() {
    func();
}


