#include <iostream>

using namespace std;


template <typename T>
struct property{
    T value;
    property(T value){
        *this=value;
    }

    operator T(){
        return value;
    }

    T operator=(T& new_value){
        cout<<"Assignemnt\n";
        return value = new_value;
    }
};


struct Creature{
    property<int> strength{10};
    property<int> agility{10};
};


int main(){
 Creature c;
 c.strength =11;
 int x= c.agility;
 return 0;
}