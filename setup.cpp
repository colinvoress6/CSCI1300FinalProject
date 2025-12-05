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
    experience += exp;
}

int scientist::getAccuracy(){
    return accuracy;
}

void scientist::setAccuracy(int acc){
    accuracy += acc;
}

int scientist::getEfficiency(){
    return efficiency;
}


void scientist::setEfficiency(int eff){
    efficiency += eff;
}

int scientist::getInsight(){
    return insight;
}

void scientist::setInsight(int ins){
    insight += ins;
}

int scientist::getDiscoveryPoints(){
    return discoveryPoints;
}

void scientist::setDiscoveryPoints(int disc){
    discoveryPoints += disc;
}
scientist::scientist(string name1, int experience1, int accuracy1, int efficiency1, int insight1, int discoverypoints1){
    name = name1;
    experience = experience1;
    accuracy = accuracy1;
    efficiency = efficiency1;
    insight = insight1; 
    discoveryPoints = discoverypoints1;
}


scientist::scientist(){
    name = "";
    experience = 0;
    accuracy = 0;
    efficiency = 0;
    insight = 0;
    discoveryPoints = 0;
}

scientist ChooseScientist(int response)
{
    if (response == 1)
        return scientist("Dr.Leo", 5, 500, 500, 1000, 20000);
    else if (response == 2)
        return scientist("Dr.Helix", 8, 900, 600, 600, 20000);
    else if (response == 3)
        return scientist("Dr.Panthera", 12, 900, 700, 500, 20000);
    else if (response == 4)
        return scientist("Dr.Adenine", 7, 600, 500, 900, 20000);
    else
        return scientist("Dr.K-mer", 18, 1000, 500, 500, 20000);
}


void scientist::setPath(int pathType){
    if (pathType == 0){
        pathName = "Training Fellowship";
        setAccuracy(500);
        setEfficiency(500);
        setInsight(1000);
        setDiscoveryPoints(-5000);
        pathNum = 0;
    }
    else{
        pathName = "Direct Lab Assignment";
        setDiscoveryPoints(5000);
        setAccuracy(200);
        setEfficiency(200);
        setInsight(200);
        pathNum = 1;
    }
    
}

string scientist::getPathName(){
    return pathName;
}
int scientist::getPathNum(){
    return pathNum;
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


string scientist::getMentor(){
    return mentor;
}

int scientist::getMentorNum(){
    return mentorNum;
}

void scientist::setMentor(int mentorType){
    if (mentorType == 0){
        mentor = "none";
        mentorNum = 0;
    }
    else if (mentorType == 1){
        mentor = "Dr.Aliquot";
        mentorNum = 1;
    }
    else if (mentorType == 2){
        mentor = "Dr.Assembler";
        mentorNum = 2;
    }
    else if (mentorType == 3){
        mentor = "Dr.Pop-Gen";
        mentorNum = 3;
    }
    else if (mentorType == 4){
        mentor = "Dr.Bio-Script";
        mentorNum = 4;
    }
    else{
        mentor = "Dr.Loci";
        mentorNum = 5;
    }
}



