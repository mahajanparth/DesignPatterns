#include<iostream>
using namespace std;

struct Point {
    float x,y ;
    Point(float x ,float y) x{x} , y{y} {

    }
    //now constructor with same signature can't be made so this is a problem 
    //Plus the object doesn't provide clarity to the user if it is using cartersian or polar coordinate 
    // So how to solve it ? Duh use Factory 
    Point( float rho , float thetha) x{rho} , y{theta}{

    }
}