#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "setup.cpp"
#include "Board.cpp"
#include "Board.h"
#include "RandomEvents.cpp"
#include "Riddle.cpp"
#include "DNA.cpp"



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

void greeting(){
    int response;
    cout << "Weclome to Journey Through the Genome press 0 to start:" << endl;
    cin >> response; 
    while (response !=0){
        cout << "Weclome to Journey Through the Genome press 0 to start:" << endl;
        cin >> response;
    }


    return;
}


void game(){

    scientist P1("", 0,0,0,0,0);
scientist P2("", 0,0,0,0,0);
Random events;
Board board;
board.initializeBoard();
   
    
    cout << "Please choose from one of the following scientists. They have unique stats that differently affect the game, so choose wisely..." << endl;
    DisplayCharacters();

    int response1, response2;
    do{
    cout << "Player 1, please Press 1 for Dr.Leo, 2 for Dr.Helix, 3 for Dr.Panthera, 4 for Dr.Adenine, or 5 for Dr.K-mer" << endl;
    cin >> response1;

    cout<< "Player 2, please choose a character. You CAN NOT choose the same character" << endl;
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
        P2.setMentor(response2);
    }
    else{
        P2.setMentor(0);
    }


    
    
    board.initializeBoard();

    cout << "Everything is set up! The player that reaches the genome conference, marked by the orange tile, with the most discovery points is the winner. Your other stats will also be factored in as well. Good luck!" << endl;
    board.displayBoard();
    cout << endl;
    

    while(board.getPlayerPosition(0) < 51 || board.getPlayerPosition(1)< 51){
    if(board.getPlayerPosition(0) < 51){
            //player 1 turn
            int response = 0;
    while(response != 5){
    cout<< "Main Menu ( Player 1 )..." << endl;
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
    if (event < 20){

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

else if(board.getTileColor(0) == 'B'){
 int accuracy = strandSimilarity();
 if (accuracy > .9){
    cout << "Correct! +100 accuracy points." << endl;
    P1.setAccuracy(100); 
 }
 else{
    cout<<"Incorect. -100 accuracy points" << endl;
    P1.setAccuracy(-100);
 }
}

else if(board.getTileColor(0) == 'P'){
    bool correct = unequalSimilarity();
    if(correct){
        P1.setAccuracy(500);
    }
    else{
        P1.setAccuracy(-100);
    }
}

else if(board.getTileColor(0) == 'R'){
    int correct = mutations();
    int score = correct * 100;
    cout << "Your strand mutated a total of " << correct << " times. " << score << " efficiency points." << endl;
    P1.setEfficiency(score);
}

else if(board.getTileColor(0) == 'T'){
    bool correct = Transcribe();
    if (correct){
        cout <<"Correct! +300 Accuracy!" << endl;
        P1.setAccuracy(300);
    }
    else{
        cout <<"Incorrect. -300 Accuracy." << endl;
        P1.setAccuracy(-300);
    }

}



board.displayBoard();
cout << endl;
P1.setExperience(1);
    }


    if(board.getPlayerPosition(1) < 51){
       int response = 0;
    while(response != 5){
    cout<< "Main Menu ( Player 2 )..." << endl;
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
int move = 0;
srand(time(0));
move  = rand() % 6 + 1;
cout << "You rolled a " << move << endl;
for (int i = 0; i < move; i++){
    if(board.movePlayer(1)){
        cout << "Player 2 has reached the genome conference. End of turn." << endl;
        break;
    }
    
}



    srand(time(0));
    int event = rand() % 48;
    if (event < 20){

        if(P2.getMentorNum() == events.MentorNumber[event]){
            cout << events.RandomEventDescription[event] << endl;
            cout << P2.getMentor() << " saved you. You will not lose any discovery points." << endl;
            }

        else if(P2.getPathNum() != events.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
            }

        else{
            cout << events.RandomEventDescription[event] << " " << events.DiscoveryPointGain[event] << " Discovery Points." << endl;
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



//checks color of space and what to do next
if(board.getTileColor(1) == 'G'){
    cout << "You landed on a safe space! Your turn is over." << endl;
}
else if(board.getTileColor(1) == 'U'){ //U is purple
    bool riddle = Riddle();
    if (riddle){
        P2.setInsight(500);
    }
    else{
        cout << "Better luck next time. Your turn is over." << endl;
    }
}

else if(board.getTileColor(1) == 'B'){
 int accuracy = strandSimilarity();
 if (accuracy > .9){
    cout << "Correct! +100 accuracy points." << endl;
    P2.setAccuracy(100); 
 }
 else{
    cout<<"Incorect. -100 accuracy points" << endl;
    P2.setAccuracy(-100);
 }
}

else if(board.getTileColor(1) == 'P'){
    bool correct = unequalSimilarity();
    if(correct){
        P2.setAccuracy(500);
    }
    else{
        P2.setAccuracy(-100);
    }
}

else if(board.getTileColor(1) == 'R'){
    int correct = mutations();
    int score = correct * 100;
    cout << "Your strand mutated a total of " << correct << " times. " << score << " efficiency points." << endl;
    P2.setEfficiency(score);
}

else if(board.getTileColor(1) == 'T'){
    bool correct = Transcribe();
    if (correct){
        cout <<"Correct! +300 Accuracy!" << endl;
        P2.setAccuracy(300);
    }
    else{
        cout <<"Incorrect. -300 Accuracy." << endl;
        P2.setAccuracy(-300);
    }

}



board.displayBoard();
cout << endl;
P2.setExperience(1);
}
    }






    ofstream outFile("game_results.txt");

    outFile<<"All scientists have made it to the genome conference! Time to determine the winner." << endl;
    outFile << "---------- Player 1 -----------" << endl;
    outFile << "Name:" << P1.getName() << endl;
    outFile << "Experience: " << P1.getExperience() << endl;
    outFile << "Accuracy: " << P1.getAccuracy() << endl;
    outFile << "Efficiency: " << P1.getEfficiency() << endl;
    outFile << "Insight: " << P1.getInsight() << endl;
    outFile << "Discovery Points: " << P1.getDiscoveryPoints() << endl;
    for(int i = 0; i < 5; i++){
        outFile << endl;
    }

    outFile << "---------- Player 2 -----------" << endl;
    outFile << "Name:" << P2.getName() << endl;
    outFile << "Experience: " << P2.getExperience() << endl;
    outFile << "Accuracy: " << P2.getAccuracy() << endl;
    outFile << "Efficiency: " << P2.getEfficiency() << endl;
    outFile << "Insight: " << P2.getInsight() << endl;
    outFile << "Discovery Points: " << P2.getDiscoveryPoints() << endl;

    for(int i = 0; i < 5; i++){
        outFile << endl;
    }



int P1Total = P1.getDiscoveryPoints() + (P1.getExperience()/10) + (P1.getAccuracy()/100) + (P1.getEfficiency()/100) + (P1.getInsight()/100);
int P2Total = P2.getDiscoveryPoints() + (P2.getExperience()/10) + (P2.getAccuracy()/100) + (P2.getEfficiency()/100) + (P2.getInsight()/100);

if(P1Total > P2Total){
    outFile << "Player 1 is the winner with " << P1Total << " points. Player 2 was close behind, with " << P2Total << "." << endl;
}

else if(P1Total < P2Total){
    outFile << "Player 2 is the winner with " << P2Total << " points. Player 1 was close behind, with " << P1Total << "." << endl;
}

outFile << "Thanks for playing!" << endl;
outFile <<"-------END GAME ------" << endl;

outFile.close();


cout <<"All scientists have made it to the genome conference! Time to determine the winner." << endl;
    cout << "---------- Player 1 -----------" << endl;
    cout << "Name:" << P1.getName() << endl;
    cout << "Experience: " << P1.getExperience() << endl;
    cout << "Accuracy: " << P1.getAccuracy() << endl;
    cout << "Efficiency: " << P1.getEfficiency() << endl;
    cout << "Insight: " << P1.getInsight() << endl;
    cout << "Discovery Points: " << P1.getDiscoveryPoints() << endl;
    for(int i = 0; i < 5; i++){
        cout << endl;
    }

    cout << "---------- Player 2 -----------" << endl;
    cout << "Name:" << P2.getName() << endl;
    cout << "Experience: " << P2.getExperience() << endl;
    cout << "Accuracy: " << P2.getAccuracy() << endl;
    cout << "Efficiency: " << P2.getEfficiency() << endl;
    cout << "Insight: " << P2.getInsight() << endl;
    cout << "Discovery Points: " << P2.getDiscoveryPoints() << endl;

    for(int i = 0; i < 5; i++){
        cout << endl;
    }

if(P1Total > P2Total){
    cout << "Player 1 is the winner with " << P1Total << " points. Player 2 was close behind, with " << P2Total << "." << endl;
}

else if(P1Total < P2Total){
    cout << "Player 2 is the winner with " << P2Total << " points. Player 1 was close behind, with " << P1Total << "." << endl;
}

cout << "Thanks for playing!" << endl;
cout <<"-------END GAME ------" << endl;
 

}