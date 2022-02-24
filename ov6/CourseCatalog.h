#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
private:
    map<string, string> courses;
    string fDir = "text_files/";
    string fName = "course_catalog";

public:
    CourseCatalog();
    friend ostream& operator<<(std::ostream& os, const CourseCatalog& c);

    void addCourse(string courseCode, string courseName);
    void removeCourse(string courseCode);
    string getCourse(string courseCode);

    void loadFromFile();
    void saveToFile();
    
};
