//Here is an example of factory method 

#include <iostream>
#include <math.h>

using namespace std;

enum class PointType
{
    cartesian,
    polar,
};


// We make the constructor private so the client can't make the object using constructor 
// Rather we provide static Api's to build the different variation of the object 
class Point
{
    Point(float x, float y): x{x}, y{x} {}

public:
    float x, y;
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }

    friend ostream &operator<<(ostream &os, const Point& pt)
    {

        return os << "x: " << pt.x << " y: " << pt.y << " \n";
    }
};

int main()
{
    auto p = Point::NewPolar(3, 3.14);
    cout << p << endl;
    p = Point::NewCartesian(3,4);
    getchar();
    return 0 ;
}