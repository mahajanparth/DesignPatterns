#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class PersonBuilder;

class Person {
    string street_address ,post_code , city;
    string company_name, position;
    int annual_income{0};
    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

}