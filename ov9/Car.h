#pragma once

class Car{
private:
    int freeSeats;

public:
    Car(int s) : freeSeats{s} {}
    bool hasFreeSeats() const {return freeSeats > 0;}
    void reserveFreeSeat() {freeSeats--;}
    ~Car() {}
};