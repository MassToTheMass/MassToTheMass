#include <string>

namespace str {
    enum WhichText { USERCHOICES, NAME, RACEL, MEETD, RESULTSFILE, MEETNAME, ATHLETENAME, BADCHOICE };

    std::string user_choices = 
        "What would you like to perform:\n"
        "Create: Create meet\n"
        "Meet: Display meet\n"
        "All Meets: Display all meets\n"
        "Athlete : Display athlete\n"
        "All Athletes: Display all athletes\n"
        "Quit: Quit Program :(";

    std::string name = "Enter the name with no spaces: ";
    std::string race_length = "Enter the race length in miles: ";
    std::string meet_date = "Enter the meet date: ";
    std::string results_file = "Enter the name of your results file: ";

    std::string meet_name = "Enter the name of the meet: ";
    std::string athlete_name = "Enter the name of the athlete: ";

    std::string bad_choice = "That is not an option, try checking your spelling";

    std::string getUserRequest(WhichText which_string) {
        switch(which_string) {
            case USERCHOICES:
                return user_choices;
            case NAME:
                return name;
            case RACEL:
                return race_length;
            case MEETD:
                return meet_date;
            case RESULTSFILE:
                return results_file;
            case MEETNAME:
                return meet_name;
            case ATHLETENAME:
                return athlete_name;
            case BADCHOICE:
                return bad_choice;
            default:
                return bad_choice;
        }
    }
}