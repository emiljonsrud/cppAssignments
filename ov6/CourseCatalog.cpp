#include "std_lib_facilities.h"
#include "CourseCatalog.h"

CourseCatalog::CourseCatalog(map<string, string> course) : course{course} {}






//  PUBLIC
void CourseCatalog::addCourse(string courseCode, string courseName) {
    course.insert({courseCode, courseName});
}

ostream& operator<<(ostream& os, CourseCatalog& c) {
    os << "Course code: " << c.course.first << endl;
    return os;
}

void CourseCatalog::removeCourse(string courseCode) {
    course.erase(courseCode);
}

string CourseCatalog::getCourse(string courseCode) {
    return course.find(courseCode) -> second;
}