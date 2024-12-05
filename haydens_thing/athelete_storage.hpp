#pragma once
#include <map>
#include "athlete.hpp"


class AthleteStore {
    private:
        

    public:
        std::map<std::string, Athlete> athletes; // Athlete name - Athlete class
        AthleteStore() {
            // algorithm for creating unique athletes goes in this constructor
            
            

        }
}