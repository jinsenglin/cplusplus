#include <iostream>
#include <sstream>

using namespace std; 

int main() {
    cout << "Enter a sentence: " << endl;
    string line;
    getline(cin, line);
    cout << "You enter: " << line << endl;

    istringstream iss(line);
    string word;
    while ( iss >> word ) {
        cout << "Word: " << word << endl;
    }
    
    istringstream iss2(line);
    string word2;
    while ( getline( iss2, word2, ' ' ) ) {
        cout << "Word: " << word2.c_str() << endl;
    }
   
    return 0; 
}
