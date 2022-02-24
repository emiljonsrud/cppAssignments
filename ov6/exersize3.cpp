#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "exersize3.h"

void testCourseCatalog() {
    CourseCatalog catalog;
    catalog.loadFromFile();


    
    // catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    // catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    // catalog.addCourse("TMA4100", "Matematikk 1");
    // cout << catalog << endl;
    

    //Oppgave d
    catalog.addCourse("TDT4102", "C++"); //ingenting sjedde med insert, men operator[] endra
    cout << catalog << endl;

    catalog.saveToFile();
}

