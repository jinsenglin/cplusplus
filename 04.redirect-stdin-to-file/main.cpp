#include <iostream>
#include <cstdio>

using namespace std; 

int main() {
    
    // redirect stdin to data.txt file
    freopen("data.txt", "r", stdin);    

    string line;
    cout << "Start reading a line from stdin until EOF" << endl;
    while ( getline(cin, line) ) {
        cout << "You enter: " << line << endl;
    }
   
    return 0; 
}
