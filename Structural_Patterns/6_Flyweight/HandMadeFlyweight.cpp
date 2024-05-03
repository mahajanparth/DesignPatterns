#include <map>
#include <string>
#include <vector>

using namespace std;

struct User
{
    string name;
};

struct User1
{
    string first_name, last_name;
};

typedef int Key;

struct User2
{
    User2(const string &first_name, const string &last_name) : first_name{User2::add(first_name)}, last_name{User2::add(last_name)}
    {
    }

    const string &get_first_name()
    {
        return names.left.find(first_name)->second;
    }

    const string &get_last_name()
    {
        return names.left.find(last_name)->second;
    }

protected:
    static Key seed;
    Key first_name, last_name;

    static bimap<Key, string> names;

    static Key add(const string &s)
    {
        auto it = names.right.find(s);

        if (it == names.right.end())
        {
            Key id = ++seed;
            names.insert({seed, s});
            return id;
        }
        return it->second;
    }
};

Key User2::seed{0};
bimap<Key, string> User2::names;

int main()
{

    User user1{"John Doe"};
    User user2{"John Smith"};

    User1 user11{"John", " Doe"};
    User1 user21{"John", " Smith"}; // waste of storage space
}