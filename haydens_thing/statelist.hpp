#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <string>
#include <unordered_map>

//forward declaration to avoid re-calling and to initialize the unordered map.
class Athlete;
//will always be a pure virtual class, region and team will not be however.
//athletes parent class, eventually will be used to parent region and team classes which will be able to display top athletes and teams within them for deeper analysis
class State {
protected:
    std::string name;
    std::unordered_map<std::string, Athlete*> athletes;

public:
    State() : name("") {}
    State(const std::string& names) : name(names) {}
    
    //function decomposition
    void addAthlete(Athlete* athlete);
    Athlete* findAthlete(const std::string& athleteName);
    void addTime(int time, const std::string& meet);
    int personalBest();
    void displayTimes();
    void displayDetails(int speed_score);
    void updateGrade(int newGrade);
    void updateTeam(const std::string& newTeam);

};

#endif