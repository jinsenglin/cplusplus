#include <iostream>

using namespace std; 

class Person {
    // private membe
    int age;

    // public member
    public:
        string gender;

        // constructor
        Person (int a, string g) {
            age = a;
            gender = g;
        }

        // getter
        int getAge() {
            return age;
        }
};

int main() {

    Person yuyu (25, "female");
    cout << "Gender: " << yuyu.gender << endl;
    cout << "Age: " << yuyu.getAge() << endl;
   
    return 0; 
}
