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
scientist();

private:


string name, mentor, pathName;
int experience, accuracy, efficiency, insight, discoveryPoints, mentorNum, pathNum;


};


