#pragma once
#include "Person.h"

enum class Campus {
    trd,
    aal,
    gjo
};
std::ostream& operator<<(std::ostream& os, const Campus cmp);