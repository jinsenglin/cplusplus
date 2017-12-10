#include <iostream>
#include <string>

using namespace std; 

bool current_smaller_than_next(int current, int next, int index) {
   return false;
}

int main() {

    // test case: 3 vs. 4
    // assert: true i.e. 1
    cout << "3 vs. 4 assert true: " << current_smaller_than_next(3, 4, 0) << endl;

    // test case: 4 vs. 3
    // aseert: false i.e. 0
    cout << "4 vs. 3 assert false: " << current_smaller_than_next(4, 3, 0) << endl;

    // test case: 4 vs. 30
    // aseert: false i.e. 0
    cout << "4 vs. 30 assert false: " << current_smaller_than_next(4, 30, 0) << endl;

    // test case: 40 vs. 3
    // aseert: false i.e. 0
    cout << "40 vs. 3 assert false: " << current_smaller_than_next(40, 3, 0) << endl;

    return 0; 
}
