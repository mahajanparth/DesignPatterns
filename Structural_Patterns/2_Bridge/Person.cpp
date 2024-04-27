
#include "Person.hpp"

// hidden implementation of PersonImpl
class Person::PersonImpl
{

public:
    void greet(Person *p)
    {
        cout << "Hello" << p->name << "\n";
    }
};

Person::Person(string name) : name{name}, impl(new PersonImpl)
{
}

Person::~Person()
{
    delete impl;
}

void Person::greet()
{
    impl->greet(this);
}