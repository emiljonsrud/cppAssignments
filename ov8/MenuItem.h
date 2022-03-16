#pragma once
#include "std_lib_facilities.h"
#include <functional>


class MenuItem {
private:
    string name;
    function<void()>  func;
    
    
public:
    MenuItem(string n, function<void()> f);

    string getName();
    void execute();
};

