//Motostate design pattern is a curious way to implment Singleton 
//It has various design flaws so not used in implmentations
//But we learn more from design flaws and what not to do :P
#include<iostream>
using namespace std;


class Employee{

    static int id; // using static id is only inantiated once hence singleton and stored in static memory which is global 

    public:
    int get_id(){ return id;}
    void set_id(int value){ id=value;}
};

int Employee::id =0;


//Client doesn't know that the class is de facto singleton ( in layman inheritent singleton ) and might create more than 1 instance 
//static variables are not inherited so extension is low and the code is rigig ( VERY IMP POINT )


int main(){

    Employee person;
    cout<<person.get_id();


    Employee person2;
    person2.set_id(5);
}