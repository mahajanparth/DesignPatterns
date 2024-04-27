//manifestation of bridge design pattern 

//it hides the implementation of the class by sticking it in cPP
#include "Person.hpp"

int main(){

    Person P{"Parth"};
    P.greet();

}


//Two advantages of pimple idiom 

//main advantage :  The implmentation is hidden from client and not passed in the class itself 

// the APi signature remains unchanged so the compiler doesn't have to rebuild everything only the cpp files that is changed not the dependent modules on that lib 
//less important nowdays 

