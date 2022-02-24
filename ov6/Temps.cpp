#include "std_lib_facilities.h"
#include "Temps.h"



//  Public
Temps::Temps() {

}

std::istream& operator>>(istream& ist, Temps& t) {

    string tempLine = "";

    while(ist) {

        string stringHigh = "";
        string stringLow = "";
        ist >> stringHigh >> stringLow;

        float high = 0;
        float low = 0;

        stringstream strHigh(stringHigh);
        stringstream strLow(stringLow);

        strHigh >> high;
        strLow >> low;
        
        Temp temp = {high, low};
        t.temps.push_back(temp);
    }
    return ist;
}

vector<Temp> Temps::getTemps() {
    return temps;
}

