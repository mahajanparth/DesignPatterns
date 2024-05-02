#include <iostream>
#include <functional>
using namespace std;

void HelloWorld(int temp)
{

    std::cout << "Hello world " << temp << std::endl;
}

int main()
{
    auto func = &HelloWorld;
    auto func2 = HelloWorld;

    // return_type(*function_ptr_name)(arguments_type ...) = &functionname;
    // void foo(int a){ cout<<a<<std::endl}
    //  eg void(*foo_ptr)(int) = & foo
    //  (*foo_ptr)(10);
    // invoking function ptr (*function_ptr_name)(arguments)

    void (*function_name)(int) = HelloWorld;
    function<void(int)> func_name = HelloWorld;

    func_name(10);
    function_name(11);

    return 0;
}