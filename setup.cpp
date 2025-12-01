#include <iostream>
#include "setup.h"
using namespace std;


string scientist::getName(){
    return name;
}

int scientist::getExperience(){
    return experience;
}

void scientist::setExperience(int exp){
    experience = exp;
}

int scientist::getAccuracy(){
    return accuracy;
}

void scientist::setAccuracy(int acc){
    accuracy = acc;
}

int scientist::getEfficiency(){
    return efficiency;
}


void scientist::setEfficiency(int eff){
    efficiency = eff;
}

int scientist::getInsight(){
    return insight;
}

void scientist::setInsight(int ins){
    insight = ins;
}

int scientist::getDiscoveryPoints(){
    return discoveryPoints;
}

void scientist::setDiscoveryPoints(int disc){
    discoveryPoints = disc;
}
scientist::scientist(string name1, int experience1, int accuracy1, int efficiency1, int insight1, int discoverypoints1){
    name = name1;
    experience = experience1;
    accuracy = accuracy1;
    efficiency = efficiency1;
    insight = insight1; 
    discoveryPoints = discoverypoints1;
}



void greeting(){
    int response;
    cout << "Weclome to Journey Through the Genome press 0 to start:" << endl;
    cin >> response; 
    while (response !=0){
        cin.clear();
        cout << "Weclome to Journey Through the Genome press 0 to start:" << endl;
        cin >> response;
    }


    return;
}

