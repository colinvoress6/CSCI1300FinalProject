#include "Characters.cpp"
#include "Board.cpp"
#include "Board.h"
#include <ctime>
#include <vector>
#include "RandomEvents.cpp"
#include <fstream>
#include <string>


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

cout<<"You landed on a riddle space! Be prepared to have your wits tested." << endl;
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

double strandSimilarity(string strand1, string strand2){
    int randomChar;
    string randStrand = "";
   for(int i = 0; i < 6; i++){
       randomChar = rand() % 4;
    if (randomChar == 0){
        randStrand += "T";
    }
    else if(randomChar == 1){
        randStrand +="G";
    }
    else if(randomChar == 2){
        randStrand += "A";
    }
    else{
        randStrand +="C";
    }
}
   cout <<"Here is a random strand of DNA. In order to transfer it to your database, please enter the same strand. Accuracy is rewarded." << endl;
   cout << randStrand;
   string response;
   cin >> response;

   int correct = 0;
   int total = 6;

   for(int k = 0; k < 6; k++){
        if (response[k] == randStrand[k]){
            correct++;
        }
   }

   double accuracy;

   accuracy = correct/total;

   return accuracy;

}

int main(){
    srand(time(0));

greeting();
    
    scientist P1("", 0,0,0,0,0);
    scientist P2("", 0,0,0,0,0);
    Random events;
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

    P1 = ChooseScientist(response1);
    P2 = ChooseScientist(response2);

    cout << "Now choose a path. You can either choose a Training Fellowship, which develops skills faster at a cost of discovery points, or a Direct Lab Assignment, which gives bonus discovery points, " << endl << "but a smaller increase in stats." << endl;
    cout << P1.getName() << " please choose a path. Press 0 for Training Fellowship, or 1 for Direct Lab Assignment." << endl;
    cin >> response1;
    P1.setPath(response1);
    if(P1.getPathName() == "Training Fellowship"){
        cout<<P1.getName() << " has chosen a training fellowship. Please choose a mentor to train with." << endl;
        DisplayMentors();
        cin >> response1;
        P1.setMentor(response1);
    }
    else{
        P1.setMentor(0);
    }

    cout << P2.getName() << " please choose a path. Press 0 for Training Fellowship, or 1 for Direct Lab Assignment." << endl;
    cin >> response2;
    P2.setPath(response2);
    if(P2.getPathName() == "Training Fellowship"){
        cout<<P2.getName() << " has chosen a training fellowship. Please choose a mentor to train with." << endl;
        DisplayMentors();
        cin >> response2;
        P2.setMentor(response1);
    }
    else{
        P2.setMentor(0);
    }


    
    Board board;

    cout << "Everything is set up! The player that reaches the genome conference, marked by the orange tile, with the most discovery points is the winner. Your other stats will also be factored in as well. Good luck!" << endl;

while(board.getPlayerPosition(0) < 51 && board.getPlayerPosition(1) < 51){

    //Player 1 Turn
    int response = 0;
    while(response != 5){
    cout<< "Main Menu (Player 1)..." << endl;
    cout << "(1) Check Player Progress" << endl;
    cout << "(2) Review Character" << endl;
    cout << "(3) Check Position" << endl;
    cout << "(4) Review Your Advisor" << endl;
    cout << "(5) Take Your Turn" << endl;
    cin >> response;

    if(response == 1){
        cout << "(1) Review Discover Points" << endl;
        cout << "(2) Review Trait Stats" << endl;
        cin >> response;
        if (response == 1){
            cout << "You have " << P1.getDiscoveryPoints() << " Discovery Points" << endl;
        }
        else{
            cout << "Trait Stats:" <<endl;
            cout <<"Accuracy:" << P1.getAccuracy() << endl;
            cout <<"Efficiency:" << P1.getEfficiency() << endl;
            cout <<"Insight:" << P1.getInsight() << endl;
        }
    }

    else if (response == 2){
        cout << "(1) Review Name" << endl;
        cout << "(2) Review Experience " << endl;
        cin >> response;

        if(response == 1){
            cout << "Name: " << P1.getName() << endl;
        }
        else{
            cout << "Experience " << P1.getExperience() << endl;
        }
    }

    else if(response == 3){
        board.displayBoard();
    }

    else if(response == 4){
        cout << "Your advisor is " << P1.getMentor() << endl;
    }
}
int move = 0;
srand(time(0));
move  = rand() % 6 + 1;
cout << "You rolled a " << move << endl;
for (int i = 0; i < move; i++){
    if(board.movePlayer(0)){
        cout << "Player 1 has reached the genome conference. End of turn." << endl;
        break;
    }
    
}



    srand(time(0));
    int event = rand() % 48;
    if (event <= 20){

        if(P1.getMentorNum() == events.MentorNumber[event]){
            cout << events.RandomEventDescription[event] << endl;
            cout << P1.getMentor() << " saved you. You will not lose any discovery points." << endl;
            }

        else if(P1.getPathNum() != events.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
            }

        else{
            cout << events.RandomEventDescription[event] << " " << events.DiscoveryPointGain[event] << " Discovery Points." << endl;
            P1.setDiscoveryPoints(events.DiscoveryPointGain[event]);
            }
}

    else{
        if(P1.getPathNum() != events.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
        }
        else{
            cout << events.RandomEventDescription[event] << ". +" << events.DiscoveryPointGain[event] << " Discovery Points." << endl;
            P1.setDiscoveryPoints(events.DiscoveryPointGain[event]);
        }
    }



//checks color of space and what to do next
if(board.getTileColor(0) == 'G'){
    cout << "You landed on a safe space! Your turn is over." << endl;
}
else if(board.getTileColor(0) == 'U'){ //U is purple
    bool riddle = Riddle();
    if (riddle){
        P1.setInsight(500);
    }
    else{
        cout << "Better luck next time. Your turn is over." << endl;
    }
}

else if(board.getTileColor(0) == 'e'){

}




board.displayBoard();




//Player 2 turn
    response = 0;
    while(response != 5){
    cout<< "Main Menu (Player 2)..." << endl;
    cout << "(1) Check Player Progress" << endl;
    cout << "(2) Review Character" << endl;
    cout << "(3) Check Position" << endl;
    cout << "(4) Review Your Advisor" << endl;
    cout << "(5) Take Your Turn" << endl;
    cin >> response;

    if(response == 1){
        cout << "(1) Review Discover Points" << endl;
        cout << "(2) Review Trait Stats" << endl;
        cin >> response;
        if (response == 1){
            cout << "You have " << P2.getDiscoveryPoints() << " Discovery Points" << endl;
        }
        else{
            cout << "Trait Stats:" <<endl;
            cout <<"Accuracy:" << P2.getAccuracy() << endl;
            cout <<"Efficiency:" << P2.getEfficiency() << endl;
            cout <<"Insight:" << P2.getInsight() << endl;
        }
    }

    else if (response == 2){
        cout << "(1) Review Name" << endl;
        cout << "(2) Review Experience " << endl;
        cin >> response;

        if(response == 1){
            cout << "Name: " << P2.getName() << endl;
        }
        else{
            cout << "Experience " << P2.getExperience() << endl;
        }
    }

    else if(response == 3){
        board.displayBoard();
    }

    else if(response == 4){
        cout << "Your advisor is " << P2.getMentor() << endl;
    }
}
move = 0;
srand(time(0));
move  = rand() % 6 + 1;
cout << "You rolled a " << move << endl;
for (int i = 0; i < move; i++){
    if(board.movePlayer(1)){
        cout << "Player 2 has reached the genome conference. End of turn." << endl;
    }
}
board.displayBoard();

    srand(time(0));
     event = rand() % 48;
    if (event <= 20){

        if(P2.getMentorNum() == events.MentorNumber[event]){
            cout << events.RandomEventDescription[event] << endl;
            cout << P2.getMentor() << " saved you. You will not lose any discovery points." << endl;
            }

        else if(P2.getPathNum() != events.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
            }

        else{
            cout << events.RandomEventDescription[event] << ". " << events.DiscoveryPointGain[event] << " Discovery Points." << endl;
            P2.setDiscoveryPoints(events.DiscoveryPointGain[event]);
            }
}

    else{
        if(P2.getPathNum() != events.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
        }
        else{
            cout << events.RandomEventDescription[event] << ". +" << events.DiscoveryPointGain[event] << " Discovery Points." << endl;
            P2.setDiscoveryPoints(events.DiscoveryPointGain[event]);
        }
    }





if(board.getTileColor(1) == 'U'){ //U is purple
    bool riddle = Riddle();
    if (riddle){
        P2.setInsight(500);
    }
    else{
        cout << "Better luck next time. Your turn is over." << endl;
    }
}





}
 





// while(board.movePlayer(0) && !board.movePlayer(1)){

// }

// while(!board.movePlayer(0) && board.moveplayer(1)){

// }
   

}