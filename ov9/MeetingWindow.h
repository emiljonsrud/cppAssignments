#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "Meeting.h"

class MeetingWindow : public AnimationWindow {
private:
    
public:
    //  Constructor
    MeetingWindow(int x, int y, int w, int h, const string& title);
};