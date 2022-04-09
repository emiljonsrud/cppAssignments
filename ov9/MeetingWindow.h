#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "Meeting.h"

class MeetingWindow : public AnimationWindow {
private:
    //  Static expresions
    static constexpr int pad = 20;
    static constexpr int btnW = 80;
    static constexpr int btnH = 50;
    static constexpr int fieldW   = 100;
    static constexpr int fieldH   = 40;
    static constexpr int fieldPad = 80;

    //  Fl objects
    Fl_Button quitBtn;

    Fl_Input personName;
    Fl_Input personEmail;
    Fl_Button personNewBtn;

    //  Member variables
    std::vector<std::shared_ptr<Person>> people;
    
public:
    //  Constructor
    MeetingWindow(int x, int y, int w, int h, const string& title);

    // Call-backs
    static void cb_quit(Fl_Widget*, void* pw);
    static void cb_new_person(Fl_Widget*, void* pw);

    // Other functions
    void newPerson();
    void printPeople();
};
