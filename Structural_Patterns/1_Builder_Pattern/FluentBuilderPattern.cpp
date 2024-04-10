#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// the element we will be using 
struct HtmlElement
{
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 4;

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
        oss << i << "<\\" << name << ">" << endl;

        return oss.str();
    }
};

// builder of the object for piece wise building 
struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(const string &name)
    {
        root.name = name;
    }
    HtmlBuilder& add_child(const string &child_name, const string &child_text)
    {
        root.elements.emplace_back(HtmlElement(child_name, child_text));
        return *this;
    }
    string str() const { return root.str(); }
};

int main(){
   HtmlBuilder builder{"ul"};
   builder.add_child("li","hello").add_child("li","world"); // look at this line , we can chain the commands using a fluent builder // we can have many add child call in chain
   cout<< builder.str();
   getchar();
   return 0;
}


// Here still the builder is a seperate class // can we provide the builder class in the elment itself ?
//checkc fluent builder2 for usage