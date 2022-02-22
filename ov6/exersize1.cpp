#include "std_lib_facilities.h"
#include "exersize1.h"

void wordsToFile() {
    cout << "What file to you wish to write to?\n>";
    string ofName = "";
    cin >> ofName;
    cout << endl;
    ofstream oFile {ofName};

    if (!oFile) error("Error: can't open file", ofName);

    cout << "Please insert the words you whish to save to a file."
    << "\nTo exit, type «quit»." << endl;

    string currentWord = "";

    while (currentWord != "quit") {
        cin >> currentWord;
        if (currentWord != "quit") {
            oFile << currentWord << endl;
        }
    } 
}

void addLineNumbers() {
    /* Må få det til å funke først
    cout << "What file to you wish to add line numbers to?\n>";
    string fName = "";
    cin >> fName;
    cout << endl;

    */
    ofstream oFile {fName};
    ifstream iFile {fName + "_lines"};

    if (!iFile or !oFile) error("Error: can't open file", fName);

    string line = "";
    if (iFile.good()) {
        int i = 0;
        while (getline(iFile, line).good()) {
            oFile << i << " " << line << endl;
            i++;
        }
    }
       

}