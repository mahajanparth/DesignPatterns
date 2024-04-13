#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Person.hpp"
#include <memory>
using namespace std;

class personBuilderBase
{
protected:
    Person &person;
    PersonBuilderBase(Person &person) : Person{person}
    {
    }

public:
    operator Person() const
    {
        return std::move(person);
    }
    // builder facets
    personBuilderBase &lives() const
    {
        return personAddressBuilder(person);
    }

    personBuilderBase &works() const
    {
        return personJobBuilder(person);
    }
};

class personBuilder : personBuilderBase
{
public:
    PersonBuilder() : PersonBuilderBase{person}
    {
    }

private:
    Person person;
};