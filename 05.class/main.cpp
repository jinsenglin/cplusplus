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

class SubPerson : public Person {
    public:
        string vendor;

        // constructor
        SubPerson (int a, string g, string v) : Person(a, g) {
            vendor = v;
        }
};

int main() {

    Person yuyu (25, "female");
    cout << "Gender: " << yuyu.gender << endl;
    cout << "Age: " << yuyu.getAge() << endl;
   
    SubPerson david (35, "male", "Weyland Corporation");
    cout << "Gender: " << david.gender << endl;
    cout << "Age: " << david.getAge() << endl;
    cout << "Vendor: " << david.vendor << endl;

    return 0; 
}
