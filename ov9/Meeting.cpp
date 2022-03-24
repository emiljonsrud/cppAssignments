#include "Meeting.h"

//  Campus
std::ostream& operator<<(std::ostream& os, const Campus cmp) {
    switch (cmp)
    {
    case Campus::trd:
        os << "Trondheim";
        break;
    case Campus::aal:
        os << "Ålesund";
        break;
    case Campus::gjo:
        os << "Gjøvik";
        break;    
    default:
        break;
    }
    return os;
}