
#ifndef MEET_STORAGE_HPP
#define MEET_STORAGE_HPP


#include <iostream>
#include <unordered_map>
#include "event.hpp"
//meet store class is a storage system for the events allowing for editing and accessing of events and the athletes within those events and within the state_list
class MeetStore {
private: 
    std::unordered_map<std::string, Event> events;

public:
    MeetStore() {}

    void create(std::string l, std::string mn, std::string date, std::string file) { //create a event and add it to the storage system so it can be displayed and accessed 
        Event meet(mn, l, date, file);
        meet.calculateDif(file, mn);
        events[mn] = meet;
    }

    void displayAll() { //display all events in the event storage
        for(const auto& pair : events) {
            std::cout << "Meet Name: " << pair.first << std::endl; 
        }
    }

    void displayEvent(const std::string& eventName) { //display more in depth analysis of a specific event
        if(events.count(eventName)) {
            events.at(eventName).printStats();
        } else {
            std::cout << "This meet does not exist" << std::endl; 
        }
    }

    void athleteScore(const std::string& eventName, const std::string& athleteName) { //displays athlete info within a meet
        if(events.count(eventName)) {
            events.at(eventName).displayAthleteInfo(athleteName);
        } else {
            std::cout << "This meet does not exist" << std::endl; 
        }
    }

    void displayAllAthletes(){ //display every athlete from each meet with in depth information to allow for coaches to compare across meets and create a ranking with standardized scores!!!
        for(auto& pair : events){
            std::cout << "Meet: " << pair.first << std::endl;
            pair.second.meetDisplayAthletes();
            std::cout << "-------------------" << std::endl;
        }
    }
};

#endif
