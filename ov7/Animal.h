#pragma once
#include "std_lib_facilities.h"

class Animal {
private:

protected:
    string name;
    int age;

public:
    Animal(string n, int a);
    virtual ~Animal() {};
    virtual string toString();

};


class Cat : public Animal {
private:

public:
    Cat(string n, int a);
    string toString();
};
class Dog : public Animal {
private:

public:
    Dog(string n, int a);
    string toString();
};

