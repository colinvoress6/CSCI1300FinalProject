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
board.initializeBoard();

greeting();
gameSetup(P1, P2, board, events);

while(board.getPlayerPosition(0) < 51 || board.getPlayerPosition(1)< 51){


if(board.getPlayerPosition(0) < 51){
    turn(P1, board, events, 1);
    P1.setExperience(1);
}

if(board.getPlayerPosition(1) < 51){
    turn(P2, board, events, 2);
    P2.setExperience(1);
}


}

ending (P1, P2);
}
   