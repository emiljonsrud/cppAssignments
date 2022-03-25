#pragma once
#include "Person.h"

#include <vector>

//  CAMPUS
enum class Campus {
    trd,
    aal,
    gjo
};

//  MEETING
class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;
    
    std::string formatTime(int time) const;
    
public:
    //  Constructors
    Meeting(
        int inpDay,
        int inpStartTime,   // hh:mm or h:mm
        int inpEndTime,     // hh:mm or h:mm
        Campus inpLocation,
        std::string inpSubject,
        std::shared_ptr<Person> inpLeader
    );
    //  Gets
    int getDay()            const {return day;}
    int getStartTime()      const {return startTime;}
    int getEndTime()        const {return endTime;}
    Campus getLocation()    const {return location;}
    std::string getSubject()    const {return subject;}
    std::shared_ptr<Person> getLeader() const {return leader;}

    std::vector<std::string> getParticipantList() const;
    std::string getTimeSpan() const;

    //  Other functions
    void addParticipant(std::shared_ptr<Person> participant);

};

//  GLOBAL
//      Operators   
std::ostream& operator<<(std::ostream& os, const Campus cmp);
std::ostream& operator<<(std::ostream& os, const Meeting& meeting);