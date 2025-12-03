#include <iostream>


using namespace std;


class scientist{
public:

string getName();

int getExperience();
void setExperience(int xp);

int getAccuracy();
void setAccuracy(int acc);

int getEfficiency();
void setEfficiency(int eff);


int getInsight();
void setInsight(int ins);


int getDiscoveryPoints();
void setDiscoveryPoints(int disc);

string getPathName();
int getPathNum();
void setPath(int pathType);

string getMentor();
int getMentorNum();
void setMentor(int MentorType);




scientist(string name, int experience, int accuracy, int efficiency, int insight, int discoverypoints);

private:


string name, mentor, pathName;
int experience, accuracy, efficiency, insight, discoveryPoints, mentorNum, pathNum;


};



void turn(){
    //displays main menu with different options that loop until player presses spin - see the pdf
    //press 0 to spin - rng 1-6
    //check to see if they win
    //check for in game events
    //trigger events if any
    //update stats if needed

}
