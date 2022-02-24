#pragma once

string inpFileName();
ifstream getStream(string fDir, string fName);

void charToLower(char &c);
map<char, int> generateAlphabet();
void printCharacterTable(map<char, int> charTable);



