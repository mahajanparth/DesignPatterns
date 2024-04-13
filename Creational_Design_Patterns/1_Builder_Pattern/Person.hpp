#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class personBuilder;

class Person
{

    string street_address, post_code, city;
    string company_name, position;
    int annual_income{0};

    Person()
    {
        std::cout << "Person Created\n";
    }

public:
    ~Person()
    {
        std::cout << "Person Destroyed\n";
    }

    Person(Person &&other) : street_address{move(other.street_address)},
                             post_code{move(other.post_code)},
                             city{move(other.city)},
                             company_name{move(other.company_name)},
                             position{move(other.position)},
                             annual_income{other.annual_income}
    {
    }

    Person &operator=(Person &&other)
    {
        if (this == &other)
            return *this;
        street_address = move(other.street_address);
        post_code = move(other.post_code);
        city = move(other.city);
        company_name = move(other.company_name);
        position = move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Person &obj)
    {
        return os << "street_address: " << obj.street_address << " post_code: " << obj.post_code << " city: " << obj.city << " company_name: " << obj.company_name << " position: " << obj.position;
    }

    Person create(){
        return personBuilder{}
    }
};