#pragma once

#include <iostream>

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }

    ~Dummy() {
        std::cout << "A dummy has been deleted" << std::endl;
        delete num;
    }
};