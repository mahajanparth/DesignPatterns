#include <iostream>
#include <sstream>
#include <string>
#include <concepts>
#include <functional>

using namespace std;


class Shape {

    virtual string str() const =0;
};

struct Circle : Shape
{
    float radius;

    Circle() {}
    Circle(float radius) : radius{radius} {}

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override
    {

        ostringstream oss;
        oss << "A circle of radius " << radius << endl;
        return oss.str();
    }
};

struct Square : Shape
{

    float side;

    Square() {}
    Square(float side) : side{side} {}

    void resize(float factor)
    {
        side *= factor;
    }

    string str() const override
    {

        ostringstream oss;
        oss << "A square of side  " << side << endl;
        return oss.str();
    }
};


//mixing inheritance : We can derive from a templated class 
//only in c++ 
// there should be some checks on the generic class T thats why we use concepts 
//concepts are c++ 20 features that helps to establish checks on generic template T 

template <typename T>
concept IsAshape = std::is_base_of<Shape,T>:: value;

template <IsAshape T>
struct ColorDecorator : public T {

    string color;
    ColorDecorator(){}

    template<typename ...Args>
    ColorDecorator(string color,Args ...args) :  T {std::forward<Args>(args)...}, color{color} {}

    virtual string str() const override {

        ostringstream oss;
        oss << T::str() << "has a color "<< color << endl;
        return oss.str();

    }
};



template< IsAshape T >
struct transparencyDecorator : public T {
    int transparency;

    template<typename... Args>
    transparencyDecorator(int transparency, Args ...args): T{std::forward<Args>(args)...} , transparency{transparency} {}

    virtual string str() const override {
        ostringstream oss;
        oss << T::str() << "has transparency " << transparency << endl;
        return oss.str();
    }

};


int main(){

    Square sq{5};
    ColorDecorator<Square> my_square{"orange",5};

    transparencyDecorator<ColorDecorator<Square>> my_trans_square{50,"white",5};
    cout<<sq.str()<<"\n";
    cout<<my_square.str()<<"\n";
    cout<<my_trans_square.str()<<"\n";

    return 0;

}