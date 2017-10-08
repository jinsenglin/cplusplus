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
    while ( getline( iss, word, ' ' ) ) {
        cout << "Word: " << word.c_str() << endl;
    }
   
    return 0; 
}
