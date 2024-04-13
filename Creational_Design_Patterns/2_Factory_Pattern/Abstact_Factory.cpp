// Read from Here as Well 

// Step 1 ) Create an Abstarct Factory Interface 
// Step 2_ Create Concrete Implementation of Abstarct Factory Interface , Factory A , Factory B 
// Step 3 Create Abstract Product that will be me made in these concrete Factories 
// Step 4) Create Concrete Implementation of these abstract products in these concrete factories 
//See the UML HERE : https://www.geeksforgeeks.org/abstract-factory-pattern-c-design-patterns/

#include<iostream>
#include<vector>
#include "HotDrinkFactory.cpp"
using namespace std;

unique_ptr<Hotdrink> make_drink(string type){
    unique_ptr<Hotdrink> drink;

    if(type == "tea"){
        drink= make_unique<Tea>();
        drink->prepare(200);
    }
    else if(type == "coffe"){
        drink= make_unique<Coffee>();
        drink->prepare(200);
    }

    return drink;

}

int main(){

    DrinkFactory factory;
    auto obj=factory.make_drink("coffee");

}
