

struct User2
{

    flyweight<string> first_name, last_name;

    User2(const string &first_name, const string &second_name) : first_name{first_name}, second_name{second_name} {}
};

int main()
{

    User2 john{"john ", "nash"};
    User2 jane{"jane", "nash"};
}