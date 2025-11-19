#include <iostream>

using namespace std;


//introduces the player to the game. Game will start based on their response
void greeting(){
    int response;
    cout << "Welcome to Journey Through the Genome! This is a 2 player game so make sure you have 2 people." << endl;
    cout <<"Press 0 to start, or a different number to exit."<<endl;
    cin >> response;
    if (response == 0){
        cout << "Great! Let's get started!" << endl;
    }
    else{
        cout<<"Maybe another time then :( " << endl;

        //I looked this up. Terminates the program
        exit(0);
    }

}
