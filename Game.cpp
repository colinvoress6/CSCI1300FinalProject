#include "Characters.cpp"
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){
srand(time(0));
scientist P1("", 0,0,0,0,0);
scientist P2("", 0,0,0,0,0);
Random events;
Board board;

greeting();
gameSetup(P1, P2, board, events);

while(board.getPlayerPosition(0) < 51 || board.getPlayerPosition(1)< 51){

turn(P1, board, events, 1);
turn(P2, board, events, 2);

}
}
    //
    
    //     cout << "Please choose from one of the following scientists. They have unique stats that differently affect the game, so choose wisely..." << endl;
    // DisplayCharacters();

    // int response1, response2;
    // do{
    // cout << "Player 1, please Press 1 for Dr.Leo, 2 for Dr.Helix, 3 for Dr.Panthera, 4 for Dr.Adenine, or 5 for Dr.K-mer" << endl;
    // cin >> response1;

    // cout<< "Player 2, please choose a character you CAN NOT choose the same character" << endl;
    // cin  >> response2;
    // }
    // while(response1 == response2);

    // P1 = ChooseScientist(response1);
    // P2 = ChooseScientist(response2);

    // cout << "Now choose a path. You can either choose a Training Fellowship, which develops skills faster at a cost of discovery points, or a Direct Lab Assignment, which gives bonus discovery points, " << endl << "but a smaller increase in stats." << endl;
    // cout << P1.getName() << " please choose a path. Press 0 for Training Fellowship, or 1 for Direct Lab Assignment." << endl;
    // cin >> response1;
    // P1.setPath(response1);
    // if(P1.getPathName() == "Training Fellowship"){
    //     cout<<P1.getName() << " has chosen a training fellowship. Please choose a mentor to train with." << endl;
    //     DisplayMentors();
    //     cin >> response1;
    //     P1.setMentor(response1);
    // }
    // else{
    //     P1.setMentor(0);
    // }

    // cout << P2.getName() << " please choose a path. Press 0 for Training Fellowship, or 1 for Direct Lab Assignment." << endl;
    // cin >> response2;
    // P2.setPath(response2);
    // if(P2.getPathName() == "Training Fellowship"){
    //     cout<<P2.getName() << " has chosen a training fellowship. Please choose a mentor to train with." << endl;
    //     DisplayMentors();
    //     cin >> response2;
    //     P2.setMentor(response1);
    // }
    // else{
    //     P2.setMentor(0);
    // }


    
    


