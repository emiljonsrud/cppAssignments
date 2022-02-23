#pragma once
#include "std_lib_facilities.h"
#include <functional>


class MenuItem {
private:
    string name;
    function<void()>  func;
    
    
public:
    MenuItem();
    void setName(string str);
    string getName();

    void setFunction(function<void()> f);
    void execute();

    
};

