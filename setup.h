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




scientist(string name, int experience, int accuracy, int efficiency, int insight, int discoverypoints);

private:


string name, mentor, path;
int experience, accuracy, efficiency, insight, discoveryPoints;


};


