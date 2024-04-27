#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Rasterizer
{
public:
    Rasterizer() = default;
    ~Rasterizer() = default;
    virtual void draw() = 0;
};

class PixelRasterizer : public Rasterizer
{
public:
    PixelRasterizer() = default;
    ~PixelRasterizer() = default;

    void draw() override
    {
        cout << "This is a pixel rasterizer\n";
    }
};

class LineRasterizer : public Rasterizer
{
public:
    LineRasterizer() = default;
    ~LineRasterizer() = default;

    void draw() override
    {
        cout << "This is a line rasterizer\n";
    }
};

class Shape
{
protected:
    Rasterizer &raster;

    Shape(Rasterizer &rz) : raster(rz)
    {
    }
    ~Shape() = default;

    virtual void draw() = 0;
};

class Circle : public Shape
{
    int cx, cy, radius;

public:
    Circle(Rasterizer &rz, int cx, int cy, int radius) : Shape(raster), cx{cx}, cy{cy}, radius{radius}
    {
    }
    ~Circle() = default;

    void draw() override
    {
        
        cout<<"drawing circle \n";
        raster.draw();
    }
};

class Rect : public Shape
{
    int cx, cy, w, h;

public:
    Rect(Rasterizer &rz, int cx, int cy, int w, int h) : Shape(rz), cx{cx}, cy{cy}, w{w}, h{h}
    {
    }
    ~Rect() = default;

    void draw() override
    {
        cout<<"drawing rect \n";
        raster.draw();
    }
};

int main()
{

    PixelRasterizer rz;


    Rect cs(rz, 1, 2, 3, 4);
    Circle cs1(rz, 1, 2,4);
    
    cs.draw();
    cs1.draw();
}