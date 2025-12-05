#include <iostream>
#include <string>
#include <cmath>

using namespace std;


double strandSimilarity(){
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
   cout << randStrand << endl;
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


bool unequalSimilarity(){
    cout << "You might have a new strand! Enter a 4 character long sequence of DNA to see if it fits in the strand you built. " << endl;
    string response;
    cin >> response;
    int randomChar;
    string randStrand = "";
   for(int i = 0; i < 12; i++){
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
    cout << "Here is the strand: " << randStrand << endl;

    for(int i = 0; i < 10; i++){
        if(randStrand.substr(0,i+3) == response){
            cout<<"Wow! it fits perfectly! +500 accuracy!" << endl;
            return true;
        }
        
    }
cout << "That's a shame. It doesn't fit. -100 accuracy." << endl;
return false;
}

int mutations(){
cout << "Enter a 12 letter DNA strand to be mutated. The more successful mutations, the more points you will receive." << endl;
string response;
cin >> response;
string mutate;
int random;
int correct = 0;

for(int i = 0; i < 12; i++){
    random = rand() % 5;

    if (random == 1){
        mutate += "C";
    }
    else if(random == 2){
        mutate +="T";
    }
    else if (random == 3){
        mutate +="G";
    }
    else if(random == 4){
        mutate += "A";
    }

}

cout << "Your strand has mutated to: " << mutate << endl;;

    for (int k = 0; k < 12; k++){
        if(response[k] == mutate[k]){
            correct --;
        }
        else{
            correct ++;
        }
    }

return correct;

}

bool Transcribe(){
cout << "Transcribe this DNA strand to RNA by swapping thymine (T) with uracil (U):" ;
string randStrand;
int randChar;
 for(int i = 0; i < 12; i++){
       randChar = rand() % 4;
    if (randChar == 0){
        randStrand += "T";
    }
    else if(randChar == 1){
        randStrand +="G";
    }
    else if(randChar == 2){
        randStrand += "A";
    }
    else{
        randStrand +="C";
    }
 }
    cout << randStrand << endl;

    for(int i = 0; i < 12; i++){
        if (randStrand[i] == 'T'){
            randStrand[i] = 'U';
        }
    }
    string response;
    cin >> response;

    for(int i = 0; i < 12; i++){
        if(response[i] != randStrand[i]){
            return false;
        }
    }
return true;
}
