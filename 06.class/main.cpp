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
}