#include <iostream>

using namespace std; 

int main() {
    cout << "Enter an integer: " << endl;
    int integer;
    cin >> integer;
    cout << "You enter: " << integer << endl;

    cout << "Enter two integers seperated by a blank: " << endl;
    int integer1, integer2;
    cin >> integer1 >> integer2;
    cout << "Integer 1: " << integer1 << endl;
    cout << "Integer 2: " << integer2 << endl;

    cout << "Enter a sentence: " << endl;
    string line;
    getline(cin, line);
    getline(cin, line);
    cout << "You enter: " << line << endl;

    cout << "Start reading a line from stdin until EOF" << endl;
    while ( getline(cin, line) ) {
        cout << "You enter: " << line << endl;
    }
   
    return 0; 
}
