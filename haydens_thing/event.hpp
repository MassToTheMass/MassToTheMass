#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "athlete.hpp"

//event class is created for each meet and allows for the handling of times, results, and athletes within this meet.
class Event {
private:
    std::string course_len;
    std::string date;
    std::unordered_map<std::string, Athlete> athletes; //dictionary holding each athletes name and its instance for automatic creation and individual manipulation

public:
    std::string results;
    std::string name;
    Event() : name(""), course_len(""), date(""), results("") {}
    Event(std::string n, std::string r) : name(n), results(r) {} //This one is for the files we already have
    Event(std::string n, std::string len, std::string d, std::string r) : name(n), course_len(len), date(d), results(r) {}

    void printStats(std::string file_name) { //print the details of the meet so the variables can remain private. 
        std::cout << "Name: " << name << " --- Course Length: " << course_len << " --- Date of meet: " << date << std::endl;

        std::ifstream race_results("haydens_thing/race_data/" + file_name + ".txt");

        std::string line;
        while (std::getline(race_results, line)) {
            std::cout << line << std::endl;
        }

    }

    int string_seconds(const std::string& seconds) { //turns a string of mm:ss into a integer of just seconds
        size_t position = seconds.find(':');
        if (position == std::string::npos) {
            return 0;
        } else {
            int min = std::stoi(seconds.substr(0, position));
            int sec = std::stoi(seconds.substr(position + 1));
            return min * 60 + sec;
        }
    }

    std::vector<std::string> splitResult(const std::string& line) { // actually does the result splitting into name/time so they can handels appropriately
        size_t position = line.find(' ');
        if (position == std::string::npos) {
            return {};
        } else {
            std::string athlete_name = line.substr(0, position);
            std::string time = line.substr(position + 1);
            return {athlete_name, time};
        }
    }

    int calculateDif(const std::string& filename, const std::string& meet) { //reads from the file inputted into the event, seperates the file into names and times and correctly deals which each. 
        int sum = 0;
        int times = 0;
        int average = 0;
        std::vector<std::string> athletes_in_event;
        std::ifstream file(filename);
        std::string line;
        std::vector<int> results;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                auto result = splitResult(line);
                if (result.size() == 2) {
                    int time_sec = string_seconds(result.at(1));
                    sum += time_sec;
                    results.push_back(time_sec);
                    athletes_in_event.push_back(result.at(0));
                    times++;
                }
            }
            file.close();
            average = times ? sum / times : 0;
        } else {
            std::cout << "Unable to open file." << std::endl;
        }

        for (size_t i = 0; i < athletes_in_event.size(); i++) {
            if (athletes.count(athletes_in_event.at(i))) {
                athletes.at(athletes_in_event.at(i)).addTime(results.at(i), meet);
            } else {
                Athlete athlete("Bountiful", 12, athletes_in_event.at(i));
                athlete.addTime(results.at(i), meet);
                athletes[athletes_in_event.at(i)] = athlete;
            }
        }

        return 1260 - average;
    }

    int standardizedTime(int racetime_sec) { //calculation for standardizing races, its not perfect but it works and I will tweak later cause I think ima work on this after this term
        int diff = calculateDif(results, name);
        return (1560 - racetime_sec - diff) / 3;
    }

    Athlete* findAthlete(const std::string& athleteName) { //basically make sure that athlete exists where we think it should
        if (athletes.count(athleteName)) {
            return &athletes.at(athleteName);
        }
        return nullptr;
    }

    void displayAthleteInfo(const std::string& athleteName) { //access the details of an individually called upon athlete from the athlete class
        Athlete* athlete = findAthlete(athleteName);
        if (athlete) {
            athlete->displayDetails(standardizedTime(athlete->personalBest()));
        } else {
            std::cout << "Athlete not available in this event!" << std::endl;
        }
    }

    void meetDisplayAthletes(){ //display all athletes within this event

        std::ifstream file("haydens_thing/race_data/" + results + ".txt");
        std::string line;

        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
};

#endif