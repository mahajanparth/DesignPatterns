#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <PersonBuilder.hpp>
using namespace std;

class personJobBuilder : PersonBuilderBase
{
private:
    personJobBuilder(Person &person) : PersonBuilderBase(person)
    {
    }

public:
    personJobBuilder& at(std::string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    personJobBuilder& as_a(std::string position)
    {
        person.position = position;
        return *this;
    }

    personJobBuilder& earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};
