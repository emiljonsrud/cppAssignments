#include "MeetingWindow.h"

//#     PUBLIC

//##        Constructor
MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string& title) :
AnimationWindow{x, y, w, h, title}, 
quitBtn(
    w-(pad+btnW),   // X-pos
    pad,            // Y-pos
    btnW,           // Button width
    btnH,           // Button height
    "Quit"
),
personName(
    fieldPad,   // X-pos
    pad,        // Y-pos
    fieldW,     // Field width
    fieldH,     // Field height
    "Name"
),
personEmail(
    fieldPad,
    2*pad + fieldH,
    fieldW,
    fieldH,
    "Email"

),
personNewBtn(
    fieldPad,
    3*pad + 2*fieldH,
    btnW,
    btnH,
    "Submit"
) {
    // Initialize button
    this->add(quitBtn);
    quitBtn.callback(cb_quit, this);

    // Initialize fields and corr. butn
    this->add(personName);
    this->add(personEmail);

    this->add(personNewBtn);
    personNewBtn.callback(cb_new_person, this);
    
    
}


//##        Call-backs
void MeetingWindow::cb_quit(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow*>(pw)->hide();
}
void MeetingWindow::cb_new_person(Fl_Widget*, void* pw) {
    try {
        static_cast<MeetingWindow*>(pw)->newPerson();
    } catch (std::invalid_argument e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
}

//##        Other functions
void MeetingWindow::newPerson() {
    std::string name = personName.value();
    std::string email = personEmail.value();
    

    // Throw invalid arg. if the fields are empty
    if(name.compare("") == 0) {
        throw std::invalid_argument("Name field is empty");
    }
    if (email.compare("") == 0) {
        throw std::invalid_argument("Email field is empty");
    }

    // Add a new person with the field values
    people.emplace_back(new Person{
        personName.value(), 
        personEmail.value()
    });

    // Clear the fields
    personName.value("");
    personEmail.value("");
}
void MeetingWindow::printPeople() {
    
    // Iterate through the people vector
    for(std::shared_ptr<Person> person : people) {
        // Print the current person
        std::cout << *person << std::endl;        
    }
}
