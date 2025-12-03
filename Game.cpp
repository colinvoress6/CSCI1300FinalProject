#include "Characters.cpp"
#include "Board.cpp"
#include "Board.h"


using namespace std;

int main(){

greeting();
    
    scientist P1("", 0,0,0,0,0);
    scientist P2("", 0,0,0,0,0);
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

    cout << "Now choose a path. You can either choose a Training Fellowship, which develops skills faster at a cost of discovery points, or a Direct Lab Assignment, which gives bonus discovery points, but a smaller increase in stats." << endl;
    cout << P1.getName() << " please choose a path. Press 0 for Training Fellowship, or 1 for Direct Lab Assignment." << endl;
    cin >> response1;
    P1.setPath(response1);
    if(P1.getPathName() == "Training Fellowship"){
        cout<<P1.getName() << " has chosen a training fellowship. Please choose a mentor to train with." << endl;
        DisplayMentors();
        cin >> response1;
        P1.setMentor(response1);
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


    srand(time(0));
    Board board;

    board.displayBoard();


 

    
   

}