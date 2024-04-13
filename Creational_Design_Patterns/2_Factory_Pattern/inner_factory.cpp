// There is no factory Design pattern in the original gang of 4 Design pattern only factory method or Abstarct Factory
// but in modern c++ we have a factory method
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum class PointType
{
    cartesian,
    polar
};

class Point
{
private:
    float x, y;

    Point(float x, float y) : x{x}, y{y} {} // Now the constructor is private  ow can Point be used by Factory ?
    // 1 - we can make it public : bad idea , the client might not use the Point Factory class as Point is directly exposed
    // 2 - make PointFactory a friend of Point , violates open and closed priniciple as an addition is done to the Point

    // friend class PointFactory; put the factory inside the point inside

    class PointFactory
    {
    public:
        static Point makeCartesian(float x, float y)
        {
            return Point(x, y);
        }
        static Point makePolar(float r, float theta)
        {
            return Point(r * cos(theta), r * sin(theta));
        }
    };


public:

    static PointFactory Factory;

    friend ostream &operator<<(ostream &os, const Point &pt)
    {
        return os << "x: " << pt.x << " y: " << pt.y << endl;
    }
};

Point::PointFactory Point::Factory ;

int main()
{

    auto p = Factory::makePolar(3,3.14);
    cout << p;
    getchar();
    return 0;
}