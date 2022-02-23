#include "std_lib_facilities.h"
#include "Menu.h"
#include "MenuItem.h"
#include "utilities.h"

auto getStream(string fDir, string fName) {
    
    ifstream iFile {fDir + fName};
    if (!iFile) {
        string errMsg = "Can't open file: " + fDir + fName;
        throw std::invalid_argument(errMsg);
    }
    return iFile
}


void charStat() {
    string fDir = "input_filed/";
   
inpName: ;
    string fName = inpFileName();
    
    try {
        getStream(fDir, fName)
    } catch (std::invalid_argument fNameErr) {
        cout << "An error occured: " << fNameErr.what() << endl;
        goto inpName;
    }


    string line = "";
    string allLines = "";

    while (getline(iFile, line)) {
        allLines += line;
    }

    map<char, int> charactertStats = generateAlphabet();
    for (char c : allLines) {
        try{
            charToLower(c);
        } catch(std::invalid_argument argExeption) {
            cout << "An error occured: " << argExeption.what() << endl;
        }
        auto mapPair = charactertStats.find(c);
        mapPair -> second ++;
        // cout << charactertStats.at(c) << endl;
    }
    printCharacterTable(charactertStats);
}