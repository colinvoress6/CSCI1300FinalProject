#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool Riddle(){
    ifstream inFile("riddles.txt");

    string questions[25];
    string answers[25];
  

for(int i = 0; i < 25; i++){
    getline(inFile, questions[i], '|');
    getline(inFile, answers[i]);
}

srand(time(0));
int riddleNum = rand() % 25;
string riddleResponse;

cout <<"You landed on a riddle space! Be prepared to have your wits tested." << endl;
cout << "Riddle: " << questions[riddleNum] << endl;
cin >> riddleResponse;

if(riddleResponse == answers[riddleNum]){
    cout << "Correct! You have gained 500 insight points." << endl;
    return true;
}
else {
    return false;
}

}