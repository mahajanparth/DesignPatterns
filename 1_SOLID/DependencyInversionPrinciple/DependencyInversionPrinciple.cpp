#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A. High level modules should not be dependent on low level modules.
// Both  should depend on abstraction

// B. Abstraction should not depend on details.
// Details should depend on abstraction

/*The Dependency Inversion Principle (DIP) is one of the SOLID principles of object-oriented design, introduced by Robert C. Martin. It emphasizes two main concepts: dependency inversion and decoupling. Let's delve into a detailed explanation of the Dependency Inversion Principle:
Principle Statement:

    High-level modules should not depend on low-level modules. Both should depend on abstractions.
    Abstractions should not depend on details. Details should depend on abstractions.

Explanation:

    Dependency Inversion:
        Traditional software design often involves high-level modules depending on low-level modules. For instance, in a typical scenario, a higher-level module (such as business logic) might directly depend on a lower-level module (such as database access).
        The Dependency Inversion Principle suggests that this dependency should be inverted. Instead of the high-level module depending on the low-level module, both should depend on abstractions. This means that classes should depend on interfaces or abstract classes rather than concrete implementations.

    Decoupling:
        By depending on abstractions, rather than concrete implementations, classes become decoupled from each other. This reduces the interdependence between classes, making the system easier to maintain, extend, and test.
        Decoupling also promotes flexibility, as it allows components to be replaced or modified without affecting other parts of the system. This is particularly useful in large, complex applications where changes are frequent.
*/

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

//Interface 
struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

//Inherited this interface 
struct Relationship : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override
    {
        vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research // high-level
{
  Research(RelationshipBrowser& browser)
  {
    for (auto& child : browser.find_all_children_of("John"))
    {
      cout << "John has a child called " << child.name << endl;
    }
  }
//  Research(const Relationships& relationships)
//  {
//    auto& relations = relationships.relations;
//    for (auto&& [first, rel, second] : relations)
//    {
//      if (first.name == "John" && rel == Relationship::parent)
//      {
//        cout << "John has a child called " << second.name << endl;
//      }
//    }
//  }
};

int main()
{
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);

  return 0;
}