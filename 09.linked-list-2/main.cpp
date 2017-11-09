#include <iostream>

using namespace std; 

/*
Input

3
InsertBack 1
InsertAfter 1 2
Reverse 
2
InsertBack 2
InsertBack 4
ADD
1
Reverse

Output

1->2->4->5
*/
void load_data() {
    // load M
    string M;
    getline(cin, M);
    cout << "DEBUG: M = " << M << endl;

    // load M instructions
    for (int i=0; i<atoi(M.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO
    }

    // load N
    string N;
    getline(cin, N);
    cout << "DEBUG: N = " << N << endl;

    // load N instructions
    for (int i=0; i<atoi(N.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO
    }

    // load ADD
    string ADD;
    getline(cin, ADD);
    cout << "DEBUG: ADD = " << ADD << endl;

    // load K
    string K;
    getline(cin, K);
    cout << "DEBUG: K = " << K << endl;

    // load K instructions
    for (int i=0; i<atoi(K.c_str()); i++) {
        string instruction;
        getline(cin, instruction);
        cout << "DEBUG: instruction = " << instruction << endl;

        // TODO
    } 
}

int main() {
    load_data(); 
    return 0; 
}
