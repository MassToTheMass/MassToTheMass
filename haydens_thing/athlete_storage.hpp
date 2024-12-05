#pragma once
#include <map>
#include "athlete.hpp"
#include <fstream>
#include <iostream>


class AthleteStore {
    private:
        

    public:
        std::map<std::string, Athlete> athletes; // Athlete name - Athlete class
        AthleteStore() {
            // algorithm for creating unique athletes goes in this constructor
            
            std::ifstream file_map("file_map.txt");
            std::string line;
            
            while (std::getline(file_map, line)) {
                std::cout << line << std::endl;
                
            }

        }
};