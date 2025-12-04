#include <iostream>
#include <string>

using namespace std;

#include "setup.cpp"



void DisplayCharacters(){
    string names[5] = {"Dr.Leo", "Dr.Helix", "Dr.Panthera", "Dr.Adenine", "Dr.K-mer"};
    int experience[5] = {5, 8, 12, 7, 18};
    int accuracy[5] = {500, 900, 900, 600, 1000};
    int efficiency[5] = {500, 600, 700, 500, 500};
    int insight[5] = {1000, 600, 500, 900, 500};
    int DiscoveryPoints[5] = {20000, 20000, 20000, 20000, 20000};

    for(int i = 0; i < 5; i++){
        cout<<"Name: " << names[i] << endl;
        cout << "Experience: " << experience[i] << endl;
        cout << "Accuracy " << accuracy[i] << endl;
        cout << "Efficiency: " << efficiency[i] << endl;
        cout << "Insight: " << insight[i] << endl;
        cout << "Discovery Points: " << DiscoveryPoints[i] << endl;
        cout << endl;
    }
}


void DisplayMentors(){
    cout << "(1) Dr. Aliquot - A master of the “wet lab”, assisting in avoiding contamination" <<endl; 
    cout <<endl;
    cout << "(2) Dr. Assembler - An expert who helps improve efficiency and streamlines pipelines" << endl;
    cout <<endl;
    cout << "(3) Dr. Pop-Gen - A genetics specialist with insight for identifying rare genetic variants" << endl;
    cout <<endl;
    cout << "(4) Dr. Bio-Script - The genius behind the data analysis, helps debug code" << endl;
    cout <<endl;
    cout << "(5) Dr. Loci - Your biggest supporter assisting you in learning the equipment" << endl;



}