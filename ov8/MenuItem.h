#pragma once

#include <string>
#include <functional>


class MenuItem {
private:
    std::string name;
    std::function<void()>  func;
    
    
public:
    MenuItem(std::string n, std::function<void()> f);

    std::string getName();
    void execute();
};

