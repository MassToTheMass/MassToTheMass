#ifndef ATHLETE_HPP
#define ATHLETE_HPP

#include "statelist.hpp"
#include <algorithm>

//athlete class is created for each athlete found in a results list inputted into the meet, currently each meet creates individual athletes, it was not necisarry for the problem to merge athletes but I will in the future when I have more than 3 days. 
class Athlete : public State {
private:
    std::string name;
    std::string team;
    std::vector<int> records;
    std::unordered_map<std::string, int> times;
    int grade;

public:
    Athlete(std::string n) : name(n), team(""), grade(0) {} // add more vars to this as we expand the data we can obtain with athletestorage
    Athlete() : team(""), grade(0) {}
    Athlete(std::string t, int g, std::string names) : State(names), team(t), grade(g) {}

    void addTime(int time, const std::string& meet) { //add a time to the athlete, used when initializing the athletes to add in their time from the meet to their results list. 
        times[meet] = time;
        records.push_back(time);
    }

    int personalBest() const { //finds their fastest time, not very necisarry right now but once athletes have multiple times it will become essential to comparison by machine rather than by hand
        if (!records.empty()) {
            return *std::min_element(records.begin(), records.end());
        }
        return -1;
    }

    void displayTimes() const { //Display their fastest time and at which meet it occured at
        for(const auto& pair : times) {
            std::cout << "Meet Name: " << pair.first << " --- Time: " << pair.second << std::endl;
        }
    }

    void displayDetails(int speed_score) const { //Show all the details about a athlete to the user for comparison to other athletes, include standardized times so coaches can compare across meets.
        std::cout << "Athlete Name: " << name << "\nTeam: " << team << "\nGrade: " << grade << std::endl;
        std::cout << "Personal Best Time: " << personalBest() << std::endl;
        std::cout << "Personal Best Standardized Score: " << speed_score << std::endl;
        displayTimes();
    }

    //will be usefull in the future
    void updateGrade(int newGrade) { //updates grade of athlete
        grade = newGrade;
    }

    void updateTeam(const std::string& newTeam) { //updates athlete team
        team = newTeam;
    }

    friend std::ostream& operator<< (std::ostream& os, const Athlete& athlete) {
        os << "Name: " << athlete.name 
        << "\nTeam: " << athlete.team 
        << "\nGrade: " << athlete.grade;
        return os;
    }
};
#endif