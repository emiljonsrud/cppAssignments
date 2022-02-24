#pragma once
struct Temp {
    float high;
    float low;
};

class Temps {
private:
    vector<Temp> temps;

public:
    Temps();
    friend istream& operator>>(istream& ist, Temps& t);

    vector<Temp> getTemps();

};