#include "std_lib_facilities.h"
#include "CourseCatalog.h"

CourseCatalog::CourseCatalog(){

}



//  PUBLIC
void CourseCatalog::addCourse(string courseCode, string courseName) {
    // courses.insert({courseCode, courseName});
    courses.operator[](courseCode) = courseName;
}

std::ostream& operator<<(std::ostream& os, const CourseCatalog& c) {
    auto thisCourse = c.courses;
    for (auto course : c.courses) {
        os << setw(10) << setfill(' ')
        << course.first
        << " - " << course.second
        << endl;
    }
    return os;
}

void CourseCatalog::removeCourse(string courseCode) {
    courses.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode) {
    return courses.find(courseCode) -> second;
}


void CourseCatalog::loadFromFile() {
    ifstream ist {fDir + fName};
    if (!ist) error("Error: could not open file: " + fDir + fName);


    string tempLine = "";
    while ( getline(ist, tempLine) ) {
        string cCode = "";
        string cName = "";

        bool split = false;
        for (char c : tempLine) {
            if (c == ',') {
                split = true;
            } 
            else if (not split) {
                cCode.push_back(c);
            } 
            else if (split) {
                cName.push_back(c);
            }
        }
        addCourse(cCode, cName);

    }
}

void CourseCatalog::saveToFile() {
    std::ofstream ost {fDir + fName};
    if (!ost) error("Error: could not open course file: " + fDir + fName);

    
    for (auto course : courses) {
        ost << course.first
        << "," << course.second
        << endl;
    }
}


