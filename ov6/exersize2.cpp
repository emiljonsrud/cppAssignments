#include "std_lib_facilities.h"
#include "Menu.h"
#include "MenuItem.h"
#include "utilities.h"


void charStat() {
    string fName = "input_files/test_characterstats.txt";
    ifstream iFile {fName};
    if (!iFile) error("Error: can't open file", fName);

    map<char, int> charactertStats = generateAlphabet();
    for (char c : fName) {
        auto mapPair = charactertStats.find(c);
        mapPair -> second ++;
        // cout << charactertStats.at(c) << endl;
    }
    for (auto m : charactertStats) {
        cout << m.first << ": " << m.second << endl;
    }

    printCharacterTable(charactertStats);
}