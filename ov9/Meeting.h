#pragma once
#include "Person.h"

#include <vector>

//  CAMPUS
enum class Campus {
    trd,
    aal,
    gjo
};
std::ostream& operator<<(std::ostream& os, const Campus cmp);

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
    
public:
    //  Constructors
    Meeting(
        int inpDay,
        int inpStartTime,
        int inpEndTime,
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

    std::vector<std::string> getParticipantList();

    //  Other functions
    void addParticipant(std::shared_ptr<Person> participant);

};
