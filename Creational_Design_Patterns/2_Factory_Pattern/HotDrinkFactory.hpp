#include<iostream>
#include "Abstact_Factory.cpp"
#include <memory>
using namespace std;

class HotdrinkFactory{
    virtual unique_ptr<Hotdrink> make() const =0;


}