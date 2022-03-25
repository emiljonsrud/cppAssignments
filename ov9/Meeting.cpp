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


//# MEETING

//##    Constructor
Meeting::Meeting(
    int inpDay,
    int inpStartTime,
    int inpEndTime,
    Campus inpLocation,
    std::string inpSubject,
    std::shared_ptr<Person> inpLeader
) : 
day{inpDay}, 
startTime{inpStartTime}, 
endTime{inpEndTime}, 
location{inpLocation}, 
subject{inpSubject},
leader{inpLeader} {
    //  The leader is also a participant
    addParticipant(leader);    
}

//##    Gets
std::vector<std::string> Meeting::getParticipantList() {
    // Create an ampty vector that will contain the names of 
    // the participants
    std::vector<std::string> participantList;

    // Loop through all the participants
    for (std::shared_ptr<Person> participant : participants) {
        // Get the participants name as a string and add it to the vector
        std::string currentName = participant.get()->getName();
        participantList.push_back(currentName);
    }
    return participantList;
}



//##    Other functions
void Meeting::addParticipant(std::shared_ptr<Person> participant) {
    participants.push_back(participant);    
}


