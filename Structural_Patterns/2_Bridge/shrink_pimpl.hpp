#include "pimple.h"

// in pimple we make the forward decelaration and a pointer to the forward declared type 

// implement the implementation in cPP


class Foo{
    class secret;
    pimpl<secret> impl; // this pimpl generic class is responsible to delte, generate, operate on the pimple implementation

}

int main(){

}