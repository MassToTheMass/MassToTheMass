#include <iostream>
#include "meet_storage.hpp"
#include "event.hpp"
#include "athlete.hpp"

int main(){
    //initialize storage system
    MeetStore meets;
    std::string choices;
    char choice;
    while(true) { //options to operate the program

        std::cout << "What would you like to perform:" << std::endl
                  << "c: Create meet" << std::endl 
                  << "M: Display meet" << std::endl
                  << "a: Display all meets" << std::endl
                  << "A: Display athlete" << std::endl
                  << "D: Display all athletes" << std::endl
                  << "q: Quit Program :(" << std::endl;
        std::getline(std::cin, choices);
        if(choices.length() == 1){
            choice = choices[0];
        }
        if(choice == 'c'){

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
        }

        else if(choice == 'M'){ //display specific meet

            std::string meetName;
            std::cout << "Enter meet name: " <<std::endl;
            std::cin >> meetName;
            
            meets.displayEvent(meetName);
        }

        else if(choice == 'a'){ //display all meets
            meets.displayAll();
        }

        else if(choice == 'A'){ // display a specific athlete within a specific meet
            std::string meetName, athleteName;
            std::cout << "What is the meet name: " << std::endl;
            std::cin >> meetName;
            std::cout << "What is the athletes name: " << std::endl;
            std::cin >> athleteName;
            meets.athleteScore(meetName, athleteName);

        }

        else if(choice == 'D'){ //display every athlete in every meet systematically for results comparison by standardized time
            meets.displayAllAthletes();
        }

        else if(choice == 'q') { //exit the program
            break;
        }

        

        else{ //handles incorrect user input here
            std::cout << "Not a choice!" << std::endl;
        }
    }
    return 0;
}