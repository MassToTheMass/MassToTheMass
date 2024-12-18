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
        std::vector<Athlete> findExistingAthlete(std::string);

    public:
        std::map<std::string, Athlete> athletes = {}; // Athlete name - Athlete class
        void displayAllAthletes();
        Athlete* getAthlete(std::string name);
        AthleteStore() {
            // algorithm for creating unique athletes goes in this constructor
            
            std::ifstream file_map("haydens_thing/race_data/file_map.txt");
            std::string line;
            
            while (std::getline(file_map, line)) {

                std::vector<std::string> current_line_vector = parseLine(line, ':');

                std::ifstream current_race("haydens_thing/race_data/" + current_line_vector[0] + ".txt");
                std::string current_racer;

                while (std::getline(current_race, current_racer)) {
                    std::vector<std::string> athlete_time = parseLine(current_racer, ' ');
                    std::vector<std::string> split_name = parseLine(athlete_time[0], '_');
                    std::string athlete_name = "";
                    for (int i = 0; i < split_name.size(); i++) {
                        std::string current_name = split_name[i];
                        std::transform(current_name.begin(), current_name.end(), current_name.begin(), ::tolower);
                        if (split_name.size() == i - 1) {
                            athlete_name += current_name;
                        } else {
                            athlete_name += current_name + " "; 
                        }
                    }
                    
                    if (!checkForExistingAthlete(athlete_name)) {
                        athletes[athlete_name] = Athlete(athlete_name);
                    } else {
                        
                        // add time to athelete

                    }
                }
            }
        }
};

std::vector<Athlete> AthleteStore::findExistingAthlete(std::string name) {
    std::map<std::string, Athlete>::iterator first = athletes.begin();
    std::map<std::string, Athlete>::iterator last = athletes.end();

    std::vector<Athlete> matching_athletes = {};

    std::string current_name;
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());

    while (first != last) {

        current_name = first->first;
        current_name.erase(std::remove_if(current_name.begin(), current_name.end(), ::isspace), current_name.end());

        if (current_name == name) {
            matching_athletes.push_back(first->first);
        }
        ++first;
    }

    return matching_athletes;
}

Athlete* AthleteStore::getAthlete(std::string name) { 
    std::vector<Athlete> athlete_list = findExistingAthlete(name);

    if (athlete_list.size() != 0) {

        if (athlete_list.size() == 1) {
            return &athlete_list.at(0);
        } else {

        std::vector<Athlete>::iterator first = athlete_list.begin();
        std::vector<Athlete>::iterator last = athlete_list.end();
        int i = 1;

        while (first != last) {
            std::cout << *first << std::endl;
            ++first;
        }

        std::cout << "Type the number of the Athlete you would like to see" << std::endl;

        std::string num;
        std::getline(std::cin, num);

        first = athlete_list.begin();
        for (int i = 1; i < std::stoi(num); i++) {
            if (first == last) {
                return nullptr;
            }
            ++first;
        }
        return &*first;
    }
    }
    return nullptr;
}

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

std::string injectUnderScore(std::string name) {
    return "";
}