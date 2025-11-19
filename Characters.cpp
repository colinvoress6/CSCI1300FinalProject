#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



void DisplayCharacters(){

    //opens character.txt as an input stream
    ifstream inFile("characters.txt");

    string line;
    const int columnWidth = 17;

    while (getline(inFile, line)) {

        string columns[10];  // storage for each column
        int columnIndex = 0;

        // Step 1: manually split the line by '|'
        string current = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '|') {
                columns[columnIndex++] = current;
                current = "";
            } else {
                current += line[i];
            }
        }
        // last column
        columns[columnIndex++] = current;

        // Step 2: print each column padded with spaces
        for (int i = 0; i < columnIndex; i++) {

            // print column
            cout << columns[i];

            // print padding spaces
            int spacesToPrint = columnWidth - columns[i].length();
            for (int s = 0; s < spacesToPrint; s++) {
                cout << " ";
            }
        }

        cout << endl;
    }
}
