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
    
   

}