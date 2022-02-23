#include "std_lib_facilities.h"
#include "exersize1.h"

void wordsToFile() {
    cout << "What file to you wish to write to?\n>";
    string fName = "";
    cin >> fName;
    cout << endl;
    string input_directory = "input_files/";
    ofstream oFile {input_directory + fName};

    if (!oFile) error("Error: can't open file", fName);

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
    cout << "What file to you wish to add line numbers to?\n>";
    string fName = "";
    cin >> fName;
    cout << endl;

    string input_directory = "input_files/";

    ifstream iFile {input_directory + fName};
    ofstream oFile {input_directory + fName + "_lines"};

    if (!iFile or !oFile) error("Error: can't open file", fName);

    
    string line = "";
    int  i = 0;

    while( getline(iFile, line) ) {
        oFile << i << " " << line << endl;
        i++;

    }
}