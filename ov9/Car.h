#pragma once

class Car{
private:
    int freeSeats;

public:
    Car(int s = 0) : freeSeats{s} {}
    bool hasFreeSeats() const {return freeSeats > 0;}
    void reserveFreeSeat() {freeSeats--;}
    ~Car() {}
};