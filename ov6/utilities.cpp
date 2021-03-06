#include "std_lib_facilities.h"
#include "utilities.h"

string inpFileName() {
    string fName = "";
    cout << "\n> ";
    cin >> fName;
    return fName;
    cout << endl;
}

ifstream getStream(string fDir, string fName) {
    
    ifstream iFile {fDir + fName};
    if (!iFile) {
        string errMsg = "Can't open file: " + fDir + fName;
        throw std::invalid_argument(errMsg);
    }
    return iFile;
}


void charToLower(char &c) {
    char lower = 'a';
    char upper = 'z';
    int intervall = 32;

    if (
        (c < lower or c > upper) and 
        (c + intervall < lower or c + intervall > upper)
        ) {
            string errMsg = "This is not a letter Aa-Zz: ";
            errMsg.push_back(c);
            throw std::invalid_argument(errMsg);
    }
    else if (c < lower) {
        c += intervall;
    }
} 

map<char, int> generateAlphabet() { //char is the key, and int is char-count
    map<char, int> alphabet;
    char lower = 'a';
    char upper = 'z';

    for (char i = lower; i <= upper; i++) {
        alphabet.insert({i, 0});
    }
    return alphabet;
}

void printCharacterTable(map<char, int> charTable) {
    int i = 1;
    for (auto c : charTable) {

        cout << right << setw(10) << setfill(' ');
        cout // << left << setw(10) << setfill(' ') 
        << c.first << ":" << right << setw(4) << setfill(' ')
        << c.second;

        if (i%3==0) {
            cout << endl;
        }
        i++;
    }
    cout << endl;
}