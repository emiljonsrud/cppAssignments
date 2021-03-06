#include "std_lib_facilities.h"
#include "Menu.h"
#include "MenuItem.h"
#include "utilities.h"

void charStat() {
    string fDir = "text_files/";
   
inpName: ;
    cout << "What file do you want to view character stats on?";
    string fName = inpFileName();
    
    try {
        getStream(fDir, fName);
    } catch (std::invalid_argument fNameErr) {
        cout << "An error occured: " << fNameErr.what() << endl;
        goto inpName;
    }
    auto iFile = getStream(fDir, fName);


    string line = "";
    string allLines = "";

    while (getline(iFile, line)) {
        allLines += line;
    }

    map<char, int> charactertStats = generateAlphabet();
    for (char c : allLines) {
        try{
            charToLower(c);
            auto mapPair = charactertStats.find(c);
            mapPair -> second ++;
        } catch(std::invalid_argument argExeption) {
            cout << "An error occured: " << argExeption.what() << endl;
        }
        // cout << charactertStats.at(c) << endl;
    }
    printCharacterTable(charactertStats);
}


// Part b
const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
    return capitalsMap.find(country) -> second;
}