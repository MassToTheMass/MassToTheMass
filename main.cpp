#include <iostream>
#include "haydens_thing/meet_storage.hpp"
#include "haydens_thing/event.hpp"
#include "haydens_thing/athlete.hpp"
#include "funcs/string_storage.hpp"
#include "athlete_storage.hpp"
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

int main(){
    //initialize storage system
    MeetStore meets;
    AthleteStore athletes;

    std::string choices;
    while(true) { 
        //options to operate the program
        std::cin.clear();
        std::cout << str::getUserRequest(str::USERCHOICES) << std::endl;
        std::getline(std::cin, choices);
        std::transform(choices.begin(), choices.end(), choices.begin(), ::tolower);
        system("clear");

        if(choices == "create"){ //create a meet
            std::string mn, date, file, l;
            std::cout << str::getUserRequest(str::MEETNAME) << std::endl;
            std::getline(std::cin, mn);
            std::cout << str::getUserRequest(str::RACEL) << std::endl;
            std::getline(std::cin, l);
            std::cout << str::getUserRequest(str::MEETD) << std::endl;
            std::getline(std::cin, date);
            std::cout << str::getUserRequest(str::RESULTSFILE) << std::endl;
            std::getline(std::cin, file);
            meets.create(l, mn, date, file);
            system("clear");
        }

        else if(choices == "meet"){ //display specific meet
            std::string meetName;
            std::cout << str::getUserRequest(str::MEETNAME) << std::endl;
            std::getline(std::cin, meetName);
            system("clear");
            meets.displayEvent(meetName);
        }

        else if(choices == "all meets"){ //display all meets
            meets.displayAll();
        }

        else if(choices == "athlete"){ // display a specific athlete within a specific meet
            std::string meetName, athleteName;
            std::cout << str::getUserRequest(str::MEETNAME) << std::endl;
            std::getline(std::cin, meetName);
            std::cout << str::getUserRequest(str::ATHLETENAME) << std::endl;
            std::getline(std::cin, athleteName);
            meets.athleteScore(meetName, athleteName);
            system("clear");
        }

        else if(choices == "all athletes"){ //display every athlete in every meet systematically for results comparison by standardized time
            meets.displayAllAthletes();
        }
        else if(choices == "quit") { //exit the program
            break;
        }
        else{ //handles incorrect user input here
            std::cout << str::getUserRequest(str::BADCHOICE) << std::endl;
        }
    }
    return 0;
}