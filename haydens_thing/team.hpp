#include "regionlist.hpp"


class Team: public Region{
    protected:
        std::string region;

    public: 
        Team(std::string regions, std::string states, std::string names): Region(states, names){
            region = regions;
        }




};