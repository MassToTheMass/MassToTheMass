
#include "statelist.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
class Region: public State{
    protected:
        std::string state;
    public:
        Region(std::string states, std::string names):State(names){
            state = states;
        }



};
