#include<string>
#include<iostream>
//pimple idom example 

using namespace std;

class Person{
    class PersonImpl; // we forward declare a class and leave its implementation in the cpp
    
    public:
    PersonImpl *impl; //pointer to that forward declarec class 
    string name;
    Person(string name);
    ~Person();

    void greet(); //PersonImpl is delegated to implement this 
};