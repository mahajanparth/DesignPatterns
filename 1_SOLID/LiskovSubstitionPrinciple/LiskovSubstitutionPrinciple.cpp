// Liskov substitution Principle Says that
//  The derived class should be substituable for the base class
//  in simple words if i replace the base class with child class it should work

#include <iostream>
using namespace std;

class rectangle
{
protected:
    int width;
    int height;

public:
    int getWidth()
    {
        return this->width;
    }

    virtual void setWidth(int width)
    {
        this->width = width;
    }

    int getHeight()
    {
        return this->height;
    }

    virtual void setHeight(int height)
    {
        this->height = height;
    }

public:
    rectangle(int width, int height) : width{width}, height{height}
    {
    }

    int area() const { return width * height; }
};

class square : public rectangle
{
    public:
    square(int dim) : rectangle(dim, dim) {}
    void setWidth(const int width) override
    {
        this->width = height = width;
    }
    void setHeight(const int height) override
    {
        this->height = width = height;
    }
};

void process(rectangle &r)
{
    int width = r.getWidth();
    r.setHeight(10);

    std::cout << "expected area " << 10 * width << " Computed Area " << r.area() << endl;
}

int main() {
    rectangle r{5, 5};
    process(r);

    square s{5};
    process(s);

    getchar();
    return 0;
}