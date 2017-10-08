#include <iostream>
#include "function.h"

using namespace std; 

class Implement : public abstractAdd {
    public:
        int add(int a, int b) {
            return a+b;
        }
};

int main() {

    Implement i;
    cout << i.add(94, 87) << endl;
    cout << i.add(55, 66) << endl;
    cout << i.add(95, 27) << endl;
   
    return 0; 
}
