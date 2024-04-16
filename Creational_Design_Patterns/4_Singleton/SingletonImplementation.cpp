#include <iostream>
#include <boost/lexical_cast.hpp>
#include <map>
#include <stdio.h>
#include <fstream>

using namespace std;

class SingletonDatabase
{
    // move the constructor in the private variable
    SingletonDatabase()
    {
        cout << "Initialize Database\n";
        ifstream ifs("capitals.txt");
        string s, s2;

        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;

public:
    // Delete the copy constructor and  assignment operator so no more copy is made
    SingletonDatabase(SingletonDatabase const &) = delete;
    void operator=(SingletonDatabase const &) = delete;
    // through this static function the 
    static SingletonDatabase &get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string &name)
    {
        return capitals[name];
    }
};

int main()
{
    string city = "Tokyo";
    cout << city << " has population" << SingletonDatabase::get().get_population(city) << std::endl;
}