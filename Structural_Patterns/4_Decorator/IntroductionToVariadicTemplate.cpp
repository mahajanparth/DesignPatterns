#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// template <typename T>
// string to_string_impl(T &param)
// {

//     ostringstream os;
//     os << param;
//     return os.str();
// }

// // variadic templates are templates with list of params converted into 1 param

// // eg1

// // default case to be made else error will be thrown
// vector<string> to_string()
// {
//     return vector<string>();
// }

// template <typename P1, typename... Params>
// vector<string> to_string(P1 &param, Params &...params)
// {
//     vector<string> vec;
//     vec.push_back(to_string(param));

//     vec.insert(vec.end, to_string(param...));
//     return vec; // initilizer list of params
// }

// // eg2 better example
// template <typename... Params>
// vector<string> to_string(Params &...params)
// {
//     return {to_string_impl(params)...}; // initilizer list of params
// }

// // best example wrap the implementation inside the varadic template

template <typename... Params>
vector<string> to_string(const Params &...params)
{

    const auto to_string_impl = [](const auto &param)
    {
        ostringstream os;
        os << param;
        return os.str();
    };

    return {to_string_impl(params)...}; // initilizer list of params
}

int main()
{
    const auto vec = to_string("hello", 1.0, "float", 2, "integer", "whattttttt", "this", "is ", "power of varadic template");

    for (auto &p : vec)
    {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}