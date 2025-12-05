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

void gameSetup(scientist &P1, scientist &P2, Board &board, Random &events){
   
    
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
        P2.setMentor(response2);
    }
    else{
        P2.setMentor(0);
    }


    
    
    board.initializeBoard();

    cout << "Everything is set up! The player that reaches the genome conference, marked by the orange tile, with the most discovery points is the winner. Your other stats will also be factored in as well. Good luck!" << endl;
    board.displayBoard();
    cout << endl;

}


void turn(scientist &s, Board &b, Random &r, int playerNum){


    int response = 0;
    while(response != 5){
    cout<< "Main Menu ( Player " << playerNum << " )..." << endl;
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
            cout << "You have " << s.getDiscoveryPoints() << " Discovery Points" << endl;
        }
        else{
            cout << "Trait Stats:" <<endl;
            cout <<"Accuracy:" << s.getAccuracy() << endl;
            cout <<"Efficiency:" << s.getEfficiency() << endl;
            cout <<"Insight:" << s.getInsight() << endl;
        }
    }

    else if (response == 2){
        cout << "(1) Review Name" << endl;
        cout << "(2) Review Experience " << endl;
        cin >> response;

        if(response == 1){
            cout << "Name: " << s.getName() << endl;
        }
        else{
            cout << "Experience " << s.getExperience() << endl;
        }
    }

    else if(response == 3){
        b.displayBoard();
    }

    else if(response == 4){
        cout << "Your advisor is " << s.getMentor() << endl;
    }
}
int move = 0;
srand(time(0));
move  = rand() % 6 + 1;
cout << "You rolled a " << move << endl;
for (int i = 0; i < move; i++){
    if(b.movePlayer(playerNum - 1)){
        cout << "Player " << playerNum << " has reached the genome conference. End of turn." << endl;
        break;
    }
    
}



    srand(time(0));
    int event = rand() % 48;
    if (event < 20){

        if(s.getMentorNum() == r.MentorNumber[event]){
            cout << r.RandomEventDescription[event] << endl;
            cout << s.getMentor() << " saved you. You will not lose any discovery points." << endl;
            }

        else if(s.getPathNum() != r.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
            }

        else{
            cout << r.RandomEventDescription[event] << " " << r.DiscoveryPointGain[event] << " Discovery Points." << endl;
            s.setDiscoveryPoints(r.DiscoveryPointGain[event]);
            }
}

    else{
        if(s.getPathNum() != r.RandomEventPath[event]){
            cout << "Nothing eventful happened this time." << endl;
        }
        else{
            cout << r.RandomEventDescription[event] << ". +" << r.DiscoveryPointGain[event] << " Discovery Points." << endl;
            s.setDiscoveryPoints(r.DiscoveryPointGain[event]);
        }
    }



//checks color of space and what to do next
if(b.getTileColor(playerNum-1) == 'G'){
    cout << "You landed on a safe space! Your turn is over." << endl;
}
else if(b.getTileColor(playerNum-1) == 'U'){ //U is purple
    bool riddle = Riddle();
    if (riddle){
        s.setInsight(500);
    }
    else{
        cout << "Better luck next time. Your turn is over." << endl;
    }
}

else if(b.getTileColor(playerNum-1) == 'B'){
 int accuracy = strandSimilarity();
 if (accuracy ==  1){
    cout << "Correct! +100 accuracy points." << endl;
    s.setAccuracy(100); 
 }
 else{
    cout<<"Incorect. -100 accuracy points" << endl;
    s.setAccuracy(-100);
 }
}

else if(b.getTileColor(playerNum-1) == 'P'){
    bool correct = unequalSimilarity();
    if(correct){
        s.setAccuracy(500);
    }
    else{
        s.setAccuracy(-100);
    }
}

else if(b.getTileColor(playerNum-1) == 'R'){
    int correct = mutations();
    int score = correct * 100;
    cout << "Your strand mutated a total of " << correct << " times. " << score << " efficiency points." << endl;
    s.setEfficiency(score);
}

else if(b.getTileColor(playerNum-1) == 'T'){
    bool correct = Transcribe();
    if (correct){
        cout <<"Correct! +300 Accuracy!" << endl;
        s.setAccuracy(300);
    }
    else{
        cout <<"Incorrect. -300 Accuracy." << endl;
        s.setAccuracy(-300);
    }

}



b.displayBoard();
cout << endl;


}


void ending(scientist s1, scientist s2){
    ofstream outFile("game_results.txt");

    outFile<<"All scientists have made it to the genome conference! Time to determine the winner." << endl;
    outFile << "---------- Player 1 -----------" << endl;
    outFile << "Name:" << s1.getName() << endl;
    outFile << "Experience: " << s1.getExperience() << endl;
    outFile << "Accuracy: " << s1.getAccuracy() << endl;
    outFile << "Efficiency: " << s1.getEfficiency() << endl;
    outFile << "Insight: " << s1.getInsight() << endl;
    outFile << "Discovery Points: " << s1.getDiscoveryPoints() << endl;
    for(int i = 0; i < 5; i++){
        outFile << endl;
    }

    outFile << "---------- Player 2 -----------" << endl;
    outFile << "Name:" << s2.getName() << endl;
    outFile << "Experience: " << s2.getExperience() << endl;
    outFile << "Accuracy: " << s2.getAccuracy() << endl;
    outFile << "Efficiency: " << s2.getEfficiency() << endl;
    outFile << "Insight: " << s2.getInsight() << endl;
    outFile << "Discovery Points: " << s2.getDiscoveryPoints() << endl;

    for(int i = 0; i < 5; i++){
        outFile << endl;
    }



int s1Total = s1.getDiscoveryPoints() + (s1.getExperience()/10) + (s1.getAccuracy()/100) + (s1.getEfficiency()/100) + (s1.getInsight()/100);
int s2Total = s2.getDiscoveryPoints() + (s2.getExperience()/10) + (s2.getAccuracy()/100) + (s2.getEfficiency()/100) + (s2.getInsight()/100);

if(s1Total > s2Total){
    outFile << "Player 1 is the winner with " << s1Total << " points. Player 2 was close behind, with " << s2Total << "." << endl;
}

else if(s1Total < s2Total){
    outFile << "Player 2 is the winner with " << s2Total << " points. Player 1 was close behind, with " << s1Total << "." << endl;
}

outFile << "Thanks for playing!" << endl;
outFile <<"-------END GAME ------" << endl;

outFile.close();

 cout<<"All scientists have made it to the genome conference! Time to determine the winner." << endl;
    cout << "---------- Player 1 -----------" << endl;
    cout << "Name:" << s1.getName() << endl;
    cout << "Experience: " << s1.getExperience() << endl;
    cout << "Accuracy: " << s1.getAccuracy() << endl;
    cout << "Efficiency: " << s1.getEfficiency() << endl;
    cout << "Insight: " << s1.getInsight() << endl;
    cout << "Discovery Points: " << s1.getDiscoveryPoints() << endl;
    for(int i = 0; i < 5; i++){
        cout << endl;
    }

    cout << "---------- Player 2 -----------" << endl;
   cout << "Name:" << s2.getName() << endl;
    cout << "Experience: " << s2.getExperience() << endl;
    cout << "Accuracy: " << s2.getAccuracy() << endl;
    cout << "Efficiency: " << s2.getEfficiency() << endl;
    cout << "Insight: " << s2.getInsight() << endl;
    cout << "Discovery Points: " << s2.getDiscoveryPoints() << endl;

    for(int i = 0; i < 5; i++){
        cout << endl;
    }


if(s1Total > s2Total){
    cout << "Player 1 is the winner with " << s1Total << " points. Player 2 was close behind, with " << s2Total << "." << endl;
}

else if(s1Total < s2Total){
    cout << "Player 2 is the winner with " << s2Total << " points. Player 1 was close behind, with " << s1Total << "." << endl;
}

cout << "Thanks for playing!" << endl;
cout <<"-------END GAME ------" << endl;

}