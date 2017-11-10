#include<iostream>
#include<string>

using namespace std;

//define a new type named Pet
//with one attribute named 'name' of type string
//and constructor can initialize the 'name' attribute
class Pet
{
public:
  Pet(string n){
    name = n;
  }

  ~Pet(){}

  Pet getThis() {
    return *this;
  }

  /* what is the difference between Pet and Pet&?
  Pet& getThis() {
    return *this;
  }*/ 

  string name;
};

//define a new type named Person
class Person {
  public:
    // constructor which does nothing
    Person() {}

    // descrtuctor which does nothing
    ~Person() {}
    
};

//define a new type named Person2
//with one attribute named 'pet' of type Pet
class Person2 {
  public:
    // constructor which does nothing
    Person2(int h, string n) {
      height = h;
      name = n;

      // let every one has a pet named 'lucky' by default
      pet = new Pet("lucky");
    }

    // descrtuctor which does nothing
    ~Person2() {}

    int height;
    string name;
    Pet *pet;

    // define a new behavior named printName
    void printName() {
      cout<<name<<endl;
    }
};

int main()
{
  cout<<"hello world"<<endl;

  //declare a variable whose type is integer
  int i;
  
  //declare a variable whose type is Person
  Person p;

  //declare a variable whose type is Person2
  //and its height is 170
  //and its name is yuyu
  Person2 p2 (170, "yuyu");

  //print p2's height and name
  cout<<p2.height<<" "<<p2.name<<endl;

  //print p2's name
  p2.printName();

  //declare another variable named p3 whose type is Person2
  //and its height is 180
  //and its name is jim
  Person2 p3(180, "jim");

  //print p3's name
  p3.printName();

  //give a pet to p2
  Pet pet ("super");
  p2.pet = &pet;

  //print the name of p2's pet
  cout<<p2.pet->name<<endl;

  //print the name of p3's pet
  cout<<p3.pet->name<<endl;

  //declare a pointer variable to store the address of object of type Person2
  Person2 *p4 = new Person2(170, "p4");
  p4->printName(); //p4
  (*p4).printName(); //p4

  //delcare a variable to store object of type Person2
  Person2 p5 (170, "p5");
  p5.printName(); //p5

  //declare a variable to store object of type Person2
  Person2 p6 = p5;
  p6.printName(); //p5

  //declare a pointer variable to store the address of object of type Person2
  Person2 *p7 = &p6;
  p7->printName(); //p5

  //declare a pointer variable to store the address of object of type Person2
  Person2 *p8 = &p5;
  p8->printName(); //p5

  //declare a pointer variable to store the address of object of type Person2
  Person2 *p9 = &(*p4);
  p9->printName(); //p4

  //declare a pointer variable to store the address of object of pointer type Person2
  Person2 **p10 = &p4;
  (*p10)->printName(); //p4
  (*(*p10)).printName(); //p4

  //
  Pet this_pet ("this-pet");
  Pet that_pet = this_pet.getThis();
  cout<<that_pet.name<<endl;
}
