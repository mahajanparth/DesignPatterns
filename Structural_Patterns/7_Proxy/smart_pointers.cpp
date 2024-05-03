// why smart pointers can be a proxy 




int main(){

    BankAccount *a = new CurrentAcccount(123);
    a-> deposit(321);
    delete a; 

    auto b = make_shared<CurrentAcccount>(123);
    BankAccount* actual = b.get(); //enhancement over the api 
    b->deposit(321); // all the apis 

    //proxy interface isn't a complete clone of original obj but can provide other benefits too but also have the exact api and properties of the original objects/class


}