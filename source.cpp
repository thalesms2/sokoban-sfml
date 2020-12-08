// #include "src/game.cpp"

// int main() {
//     game();
//     return 0;
// }

// tirar do looping do mapa o fundo e paredes pq n precisa fica repetindo isso

#include <iostream>
#include <fstream>
using namespace std;
const int MAXFILENAMESIZE = 80;
void getANameAndOpenAFile(ifstream & f, char * fn) {
    cout << "Enter in a filename to open: ";
    cin >> fn;
    f.open(fn);
    while(!f.is_open()){
        cout << "\nInvalid File name, re-enter: ";
        cin >> fn;
        f.open(fn);
    }
}
int main(void) {
    ifstream inputfile;
    char filename[MAXFILENAMESIZE];
    char inputchar = ' ';
    char inpu[13];
    int i = 0;
    getANameAndOpenAFile(inputfile, filename);
    while(inputfile.get(inputchar)) { 
        inpu[i] = inputchar;
        i++;
    }
    for(int i = 0;i<13;i++){
        cout << inpu[i] << endl;
    }
    inputfile.close();
    return 0;
}
