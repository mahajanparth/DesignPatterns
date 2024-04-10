// Builder Pattern : When the construction of the object is complex or piecewise ,
// we rather provide apis for construction of the object rather than a single/ multiple constructor handeling everything

#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

using namespace std;

// It is just the utility class for modelling
struct HtmlElement
{

    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() = default;
    HtmlElement(const string &name, const string &text) : name{name}, text{text} {}
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text << endl;

        for (auto &ele : elements)
        {
            oss << ele.str(indent + 1);
        }

        oss <<  i << "<\\" << name << ">" << endl;

        return oss.str();
    }
};

struct HtmlBuilder
{
    HtmlElement root;
    HtmlBuilder(string root_name)
    {
        root.name = root_name;
    }

    void add_child(string child_name, string child_text)
    {
        root.elements.emplace_back(HtmlElement(child_name, child_text));
    }

    string str(int indent = 0) const
    {
       return root.str(indent);
    }
};

int main()
{
    HtmlBuilder builder{"/ul"};
    builder.add_child("li","Hello");
    builder.add_child("li","world");
    cout << builder.str();
    getchar();
    return 0;


}