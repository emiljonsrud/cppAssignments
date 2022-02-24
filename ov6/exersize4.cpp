#include "std_lib_facilities.h"
#include "exersize4.h"

vector<Temp> readTemps(string fName) {
    Temps temps;
    string fDir = "text_files/";

    ifstream ist {fDir + fName};
    if (!ist) error("Error: could not open file: " + fDir + fName);

    ist >> temps;
    return temps.getTemps();
}

void tempStats(vector<Temp> temps) {
    float maxTemp = 0;
    float minTemp = 0;

    for (Temp temp : temps) {
        if (temp.high > maxTemp) {
            maxTemp = temp.high;
        }
        if (temp.low < minTemp) {
            minTemp = temp.low;
        }
    }

    cout << "Max temperature: " << maxTemp << endl;
    cout << "Min temperature: " << minTemp << endl;
}
