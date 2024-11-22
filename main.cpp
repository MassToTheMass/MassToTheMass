#include <iostream>
#include "haydens_thing/meet_storage.hpp"
#include "haydens_thing/event.hpp"
#include "haydens_thing/athlete.hpp"
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

int main(){
    //initialize storage system
    MeetStore meets;
    std::string choices;
    while(true) { //options to operate the prograM
        std::cin.clear();
        std::cout << "What would you like to perform:" << std::endl
                  << "Create: Create meet" << std::endl 
                  << "Meet: Display meet" << std::endl
                  << "All Meets: Display all meets" << std::endl
                  << "Athlete : Display athlete" << std::endl
                  << "All Athletes: Display all athletes" << std::endl
                  << "Quit: Quit Program :(" << std::endl;
        std::getline(std::cin, choices);
        std::transform(choices.begin(), choices.end(), choices.begin(), ::tolower);
        system("clear");
        if(choices == "create"){ //create a meet
            std::string mn, date, file, l;
            std::cout << "Enter the meet name with no spaces: " << std::endl;
            std::cin >> mn; 
            std::cout << "Enter the race length in miles: " << std::endl;
            std::cin >> l;
            std::cout << "Enter the meet date: " << std::endl;
            std::cin >> date;
            std::cout << "Enter the name of your results file: " << std::endl;
            std::cin >> file;
            meets.create(l, mn, date, file);
            system("clear");
        }

        else if(choices == "meet"){ //display specific meet
            std::string meetName;
            std::cout << "Enter meet name: " <<std::endl;
            std::cin >> meetName;

            system("clear");
            
            meets.displayEvent(meetName);
        }

        else if(choices == "all meets"){ //display all meets
            meets.displayAll();
        }

        else if(choices == "athlete"){ // display a specific athlete within a specific meet
            std::string meetName, athleteName;
            std::cout << "What is the meet name: " << std::endl;
            std::cin >> meetName;
            std::cout << "What is the athletes name: " << std::endl;
            std::cin >> athleteName;
            meets.athleteScore(meetName, athleteName);

        }

        else if(choices == "all athletes"){ //display every athlete in every meet systematically for results comparison by standardized time
            meets.displayAllAthletes();
        
        }
        else if(choices == "quit") { //exit the program
            break;
        }
        else{ //handles incorrect user input here
            std::cout << "Not a choice!" << std::endl;
        }
    }
    return 0;
}