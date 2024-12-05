#pragma once
#include <map>
#include "athlete.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> parseLine(std::string, char);

class AthleteStore {
    private:
        bool checkForExistingAthlete(std::string);

    public:
        std::map<std::string, Athlete> athletes = {}; // Athlete name - Athlete class
        void displayAllAthletes();
        AthleteStore() {
            // algorithm for creating unique athletes goes in this constructor
            
            std::ifstream file_map("file_map.txt");
            std::string line;
            
            while (std::getline(file_map, line)) {

                std::vector<std::string> current_line_vector = parseLine(line, ':');

                std::ifstream current_race("haydens_thing/race_data/" + current_line_vector[0] + ".txt");
                std::string current_racer;

                while (std::getline(current_race, current_racer)) {
                    std::vector<std::string> athlete_time = parseLine(current_racer, ' ');
                    std::string athlete_name = athlete_time[0];
                    if (!checkForExistingAthlete(athlete_name)) {
                        athletes[athlete_name] = Athlete(athlete_name);
                    } else {
                        // add the race to the said athlete's data
                    }
                }
            }
        }
};

void AthleteStore::displayAllAthletes() {
    std::map<std::string, Athlete>::iterator first = athletes.begin();
    std::map<std::string, Athlete>::iterator last = athletes.end();

    while (first != last) {
        std::cout << first->second << std::endl;
        ++first;
    }
}

bool AthleteStore::checkForExistingAthlete(std::string athlete_name) {
    std::map<std::string, Athlete>::iterator first = athletes.begin();
    std::map<std::string, Athlete>::iterator last = athletes.end();

    while (first != last) {
        if (athlete_name == first->first) {
            // add athlete's time to their records, don't make a new one
            return 1;
        }
        ++first;
    }
    return 0;
}

std::vector<std::string> parseLine(std::string line, char delim) {

    std::vector<std::string> string_vector = {};

    std::istringstream current_line(line);
    std::string token;

    while (std::getline(current_line, token, delim)) {
        string_vector.push_back(token);
    }
    return string_vector;
}