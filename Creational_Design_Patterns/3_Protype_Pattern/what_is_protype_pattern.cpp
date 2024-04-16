#include < iostream>
using namespace std;

struct Address
{
    Address(const string &street, const string &city, int suite) : street{street}, city{city}, suite{suite} {}
}

struct Contact
{
    /* data */
    string name;
    Address address;
    Contact(const string &name, const Address &address) : name{name}, address{address} {}
};

int main()
{
    Contact john{"john doe", Address{"123 East Dr","Lodon",123}};
    //Contact jane{"jane suze", Address{"123 East Dr","Lodon",124}};
    Contact jack{"jack maa", Address{"123 East Dr","Lodon",125}};
    //Rather than making each object from scratch what we can use is reuse the object john to make jane 

    //Something like : we only change the properties that we wanna change :P
    Contact jane = john;
    jane.name =" jane suze";
    jane.address.suite = 124;

    // In long code bases this makes sence 
    // for eg rather than making the new bmw series X car from scratch we can use the old version and override the parts the needs change by extension not modification else we will break OCP of Solid Principles      
}