#include <iostream>
#include <string>

using namespace std;
class Address{
    public:
    string street,building;
    int suite;
    
    Address(const string& street, const string& building, const int suite): street{ street} , building{building} , suite{suite}{}
    Address(const Address& other): street{ other.street} , building{other.building} , suite{other.suite}{}
    
};


class Contact{

    public:

    string name;
    Address* address;
    Contact(const string &name, const Address* address) : name{name}, address{new Address(address)} {}
    ~Contact(){
        delete address;
    }
};

//If you wanna keep your protype safe 
//keep protype safe in a factory 


class EmployeeFactory{
    public:
    //This is a specific version of the employee that share some values of base constructor 
    static Contact& new_main_office_Employee(const string& name, const int suite){
        static Contact protype{"Parth", new Address("123 East drive","New Delhi",0)};
        return new_employee(name,suite,protype);
    }

    private:
    //This is a generalized new employee
    static Contact& new_employee(const string& name, int suite,const Contact& prototype){
        auto result = Contact(prototype);
        result.name=name;
        result.address->suite= suite;  
    }
};


int main(){
    auto john= EmployeeFactory::new_main_office_Employee("john",123);
    //auto jane= EmployeeFactory::new_main_office_Employee("john",123);
    
    return 0;
}