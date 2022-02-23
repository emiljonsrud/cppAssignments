#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
private:
    map<string, string> course;

public:
    CourseCatalog(map<string, string> course);
    friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);

    void addCourse(string courseCode, string courseName);
    void removeCourse(string courseCode);
    string getCourse(string courseCode);
    
};
