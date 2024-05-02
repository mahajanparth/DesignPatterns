#include <string>
#include <iostream>
#include <sstream>
#include <functional>

using namespace std;

struct Logger
{
    // void(*func_name)(args); same as line below
    function<void()> func;
    string name;
    Logger(const function<void()> &func, const string &name) : func{func}, name{name} {}

    void operator()() const
    {
        cout << "\nEntering " << name << endl;
        func();
        cout << "\nExisting " << name << endl;
    }
};

template <typename Func>
struct Logger2
{
    // void(*func_name)(args); same as line below
    function<void()> func;
    string name;
    Logger2(const Func &func, const string &name) : func{func}, name{name} {}

    void operator()() const
    {
        cout << "\nEntering " << name << endl;
        func();
        cout << "\nExisting " << name << endl;
    }
};

double add(double a, double b)
{
    cout << a << " + " << b << " = " << (a + b) << endl;
    return a + b;
}

template <typename Func>
auto make_logger2(Func func, const string &name)
{
    return Logger2<Func>{func, name};
}

template <typename>
struct Logger3; // why is this line required (TODO:PARTH find out ) very interesting ( Done : Answer Below)
template <typename R, typename... Args>
struct Logger3<R(Args...)> // This is a Specialization rather than a normal template hence we use the above forward declararion
{

    function<R(Args...)> func;

    string name;
    Logger3(const function<R(Args...)> &func, const string &name) : func{func}, name{name}
    {
    };

    R operator()(Args... args)
    {
        cout << "Entering " << name << endl;
        R result = func(args...);
        cout << "Exiting " << name << endl;
        return result;
    };
};

template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...), const string &name)
{
    return Logger3<R(Args...)>(function<R(Args...)>(func), name);
};

int main()
{
    cout << "Hello" << endl;

    Logger([]()
           { cout << "Hello lambada func"; },
           "Hello Function")();
    make_logger2([]()
                 { cout << "Hello lambada func"; },
                 "Hello Function2")(); // this function doesn't have any arguments then what do we do ?

    auto logged = make_logger3(add, "Add");
    auto result = logged(2,3);


    return 0;
}