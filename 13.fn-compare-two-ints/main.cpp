#include <iostream>
#include <string>

using namespace std; 

bool current_smaller_than_next(int current, int next) {  
    string str_current = to_string(current);
    string str_next = to_string(next);

    string candidate1 = str_current + str_next;
    string candidate2 = str_next + str_current;

    int candidate_len = candidate1.length();
    for (int i=0; i<candidate_len; i++) {
        if (candidate1[i] < candidate2[i]) {
            return true;
        }
        else if (candidate1[i] > candidate2[i]) {
            return false;
        }
        else {
            // i.e candidate1[index] == candidate2[index]
            continue;
        }
    }
}

int main() {

    // test case: 3 vs. 4
    // assert: true i.e. 1
    cout << "3 vs. 4 assert true: " << current_smaller_than_next(3, 4) << endl;

    // test case: 4 vs. 3
    // aseert: false i.e. 0
    cout << "4 vs. 3 assert false: " << current_smaller_than_next(4, 3) << endl;

    // test case: 4 vs. 30
    // aseert: false i.e. 0
    cout << "4 vs. 30 assert false: " << current_smaller_than_next(4, 30) << endl;

    // test case: 40 vs. 3
    // aseert: false i.e. 0
    cout << "40 vs. 3 assert false: " << current_smaller_than_next(40, 3) << endl;

    // test case: 35 vs. 351
    // aseert: false i.e. 0
    cout << "35 vs. 351 assert false: " << current_smaller_than_next(35, 351) << endl;

    // test case: 35 vs. 354
    // aseert: true i.e. 1
    cout << "35 vs. 354 assert true: " << current_smaller_than_next(35, 354) << endl;

    // test case: 35 vs. 35351
    // aseert: false i.e. 0
    cout << "35 vs. 35351 assert false: " << current_smaller_than_next(35, 35351) << endl;

    // test case: 35 vs. 35354
    // aseert: true i.e. 1
    cout << "35 vs. 35354 assert true: " << current_smaller_than_next(35, 35354) << endl;

    // test case: 35 vs. 35353
    // aseert: false i.e. 0
    cout << "35 vs. 35353 assert false: " << current_smaller_than_next(35, 35353) << endl;

    return 0; 
}
