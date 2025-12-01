#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
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

void chooseCharacter(scientist &P1, scientist &P2){

    cout << "Please choose from one of the following scientists. They have unique stats that differently affect the game, so choose wisely..." << endl;
    DisplayCharacters();

    int response1, response2;
    do{
    cout << "Player 1, please Press 1 for Dr.Leo, 2 for Dr.Helix, 3 for Dr.Panthera, 4 for Dr.Adenine, or 5 for Dr.K-mer" << endl;
    cin >> response1;

    cout<< "Player 2, please choose a character you CAN NOT choose the same character" << endl;
    cin  >> response2;
    }
    while(response1 == response2);


//initialize player 1
if (response1 == 1) {
    P1 = scientist("Dr.Leo", 5, 500, 500, 1000, 20000);
   
}
else if(response1 == 2){
    P1 = scientist("Dr.Helix", 8, 900, 600, 600, 200000); 
}

else if(response1 == 3){
    P1 = scientist("Dr.Panthera", 12, 900, 700, 500, 20000);
}
else if(response1 == 4){
    P1 = scientist("Dr.Adenine", 7, 600, 500, 900, 20000);
}
else{
    P1 = scientist("Dr.K-mer", 18, 1000, 500, 500, 20000);
}


//initialize player 2
if(response2 == 1){
    P2 = scientist("Dr.Leo", 5, 500, 500, 1000, 20000);
}
else if(response2 == 2){
    P2 = scientist("Dr.Helix", 8, 900, 600, 600, 200000); 
}

else if(response2 == 3){
   P2 = scientist("Dr.Panthera", 12, 900, 700, 500, 20000);
}
else if(response2 == 4){
    P2 = scientist("Dr.Adenine", 7, 600, 500, 900, 20000);
}
else{
    P2 = scientist("Dr.K-mer", 18, 1000, 500, 500, 20000);
}

}
