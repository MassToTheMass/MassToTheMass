#include <string>
using namespace std;


// temp struct to check if athletes exist

struct TemplateAthlete {

    string name;
    string team;
    int grade;

    pair<string, int> race_time;

    TemplateAthlete(string n, string t, int g) : name(n), team(t), grade(g) {}
}