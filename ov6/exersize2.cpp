#include "std_lib_facilities.h"
#include "Menu.h"
#include "MenuItem.h"


void charStat() {
    string fName = "input_files/test_characterstats.txt";
    ifstream iFile {fName};
    if (!iFile) error("Error: can't open file", fName);

    


}