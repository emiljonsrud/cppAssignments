#include "Meeting.h"


//# MEETING

//# PRIVATE

// Input: 4-digit in denoting time by the format: hh:mm or h:mm
std::string Meeting::formatTime(int time) const {
    // Find the minuts and hours
    int mm = time%100;
    int hh = (time-mm)/100;
    
    // Convert mm and hh to strings
    std::string mmString = std::to_string(mm);
    std::string hhString = std::to_string(hh);
    std::string formattedTime = "";
    
    if (mm < 10) {mmString.insert(0, 1, '0');}
    if (hh < 10) {hhString.insert(0, 1, '0');}
    
    formattedTime = hhString;
    formattedTime.push_back(':');
    formattedTime += mmString;
    
    return formattedTime;
}

//# PUBLIC
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
std::vector<std::string> Meeting::getParticipantList() const {
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

std::string Meeting::getTimeSpan() const {
    // Create an empty string that will contail the formatted time
    std::string timespan = "";
    timespan = formatTime(startTime);
    timespan += " - ";
    timespan += formatTime(endTime);
    return timespan;
}



//##    Other functions
void Meeting::addParticipant(std::shared_ptr<Person> participant) {
    participants.push_back(participant);    
}


//# GLOBAL

//##    Operators
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

std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
    // Create some table sizes
    int leftWidth = 15;
    int rightWidth = 20;

    // Print locations
    os << std::left << std::setw(leftWidth) << std::setfill(' ');
    os << "Location:";
    os << std::right << std::setw(rightWidth) << std::setfill(' ');
    os << meeting.getLocation() << std::endl;

    // Print subject
    os << std::left << std::setw(leftWidth) << std::setfill(' ');
    os << "Subject:";
    os << std::right << std::setw(rightWidth) << std::setfill(' ');
    os << meeting.getSubject() << std::endl;

    // Print Time
    os << std::left << std::setw(leftWidth) << std::setfill(' ');
    os << "Time:";
    os << std::right << std::setw(rightWidth) << std::setfill(' ');
    os << meeting.getTimeSpan() << std::endl;

    // Print leader
    os << std::left << std::setw(leftWidth) << std::setfill(' ');
    os << "Leader:";
    os << std::right << std::setw(rightWidth) << std::setfill(' ');
    os << meeting.getLeader().get()->getName() << std::endl;
    
    // Print participants
    std::vector<std::string> participants = meeting.getParticipantList();
    os << std::left << std::setw(leftWidth) << std::setfill(' ');
    os << "Participant(s):";
    os << std::right << std::setw(rightWidth) << std::setfill('.');
    os << participants.at(1) << std::endl; // Dont need to show the leader again

    for (int i = 2; i < participants.size(); i++) {
        os << std::right << std::setw(leftWidth) << std::setfill(' ') << " ";
        os << std::right << std::setw(rightWidth) << std::setfill('.');
        os << participants.at(i) << std::endl;
    }

    return os;
}