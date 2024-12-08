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
            std::cout << "Constructing" << std::endl;
            
            std::ifstream file_map("haydens_thing/race_data/file_map.txt");
            std::string line;
            
            while (std::getline(file_map, line)) {

                std::cout << "File looping" << std::endl;

                std::vector<std::string> current_line_vector = parseLine(line, ':');

                std::ifstream current_race("haydens_thing/race_data/" + current_line_vector[0] + ".txt");
                std::string current_racer;

                while (std::getline(current_race, current_racer)) {
                    std::vector<std::string> athlete_time = parseLine(current_racer, ' ');
                    std::vector<std::string> split_name = parseLine(athlete_time[0], '_');
                    std::string athlete_name = "";
                    for (int i = 0; i < split_name.size(); i++) {
                        if (split_name.size() = i - 1) {
                            athlete_name += split_name[i];
                        } else {
                            athlete_name += split_name[i] + " ";
                        }
                    }
                    
                    if (!checkForExistingAthlete(athlete_name)) {
                        athletes[athlete_name] = Athlete(athlete_name);
                    } else {
                        // add the race to the said athlete's data
                    }
                }
            }
        }
};

std::vector<Athlete> AthleteStore::findExistingAthlete(std::string name) {
    std::map<std::string, Athlete>::iterator first = athletes.begin();
    std::map<std::string, Athlete>::iterator last = athletes.end();

    std::vector<Athlete> matching_athletes = {};

    std::cout << name << std::endl;

    while (first != last) {
        std::cout<< first->first << std::endl;

        if (first->first == name) {
            matching_athletes.push_back(first->first);
        }
        ++first;
        std::string tempvar;
        std::cin >> tempvar;
    }

    return matching_athletes;
}

Athlete* AthleteStore::getAthlete(std::string name) { 
    std::vector<Athlete> athlete_list = findExistingAthlete(name);

    if (athlete_list.size() != 0) {

        std::cout << "list exists" << std::endl;

        std::map<std::string, Athlete>::iterator first = athletes.begin();
        std::map<std::string, Athlete>::iterator last = athletes.end();
        int i = 1;

        while (first != last) {
            std::cout << first->second << std::endl;
        }

        std::cout << "Type the number of the Athlete you would like to see" << std::endl;

        std::string num;
        std::getline(std::cin, num);

        first = athletes.begin();
        for (int i = 1; i < std::stoi(num); i++) {
            if (first == last) {
                return nullptr;
            }
            ++first;
        }
        return &first->second;
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

}