#include "std_lib_facilities.h"
#include "exersize1.h"
#include "utilities.h"

void wordsToFile() {
    cout << "What file to you wish to write to?";
    string fName = inpFileName();

    string input_directory = "text_files/";
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
    string fDir = "text_files/";

input: ;
    cout << "What file to you wish to add line numbers to?";
    string fName = inpFileName();
    try {
        getStream(fDir, fName);
    } catch (std::invalid_argument fNameExeption) {
        cout << "An error occured: " << fNameExeption.what() << endl;
        goto input;
    }

    ifstream iFile = getStream(fDir, fName);
    ofstream oFile {fDir + fName + "_lines"};

    string line = "";
    int  i = 0;

    while( getline(iFile, line) ) {
        oFile << i << " " << line << endl;
        i++;
    }
}