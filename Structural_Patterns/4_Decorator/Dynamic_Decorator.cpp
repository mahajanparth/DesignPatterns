#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Shape
{
    virtual string str() const = 0;
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

struct ColorShape : Shape
{
    Shape &shape;
    string color;
    ColorShape(Shape &shape, const string &color) : shape{shape}, color{color} {}

    string str() const override
    {

        ostringstream oss;
        oss << shape.str() << "has the color" << color << endl;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape &shape;
    int transparency;
    TransparentShape(Shape &shape, int transparency) : shape{shape}, transparency{transparency} {}

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.0f * 100.0f << "% transparency\n";
        return oss.str();
    }
};

int main()
{
    Square square{5};
    ColorShape colorsq{square, " orange"};
    TransparentShape my_square{colorsq, 51};
    cout << square.str() << "\n";
    cout << colorsq.str() << "\n";
    cout << my_square.str() << "\n";
}