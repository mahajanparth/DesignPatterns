// gives the appearance of working with the object even when the object is not created

#include <iostream>

using namespace std;

struct Image
{
    virtual void draw() = 0;
};

struct BitMap : Image
{

    BitMap(const string &path)
    {
        cout << " Loading Bitmap from " << path << endl;
    }

    virtual void draw() override
    {
        cout << " Drawing Bitmap" << endl;
    }
};

struct LazyBitMap : Image
{
    string file_name;
    BitMap *bmp{nullptr}; // just like dynamic decorator we keep a reference or pointer here (interesting ...) what is the difference ? 

    LazyBitMap(const string &path) : file_name{path}
    {
    }

    virtual void draw() override
    {
        if (!bmp)
        {
            bmp = new BitMap(file_name);
        }
        cout << " Drawing Bitmap" << endl;
    }
};

int main(){
    BitMap bmp{"parth.jpg"};
    bmp.draw();

    LazyBitMap bmp2{"parth.jpg"};
    bmp2.draw(); // only load when draw is called lazy initialize 
    
}