#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tag
{
    public:
    string name, text;
    vector<Tag> children;

    vector<pair<string, string>> attributes;

    friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
    {
        os << "<" << tag.name;

        for (const auto &att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        if (tag.children.size() == 0 && tag.text.length() == 0)
        {
            os << "/>" << std::endl;
        }
        else
        {
            os << ">" << std::endl;

            if (tag.text.length())
                os << tag.text << std::endl;

            for (const auto &child : tag.children)
                os << child;

            os << "</" << tag.name << ">" << std::endl;
        }

        return os;
    }

protected:
    Tag(const string &name, const string &text) : name{name}, text{text} {}
    Tag( const string& name , const vector<Tag> & children){
        this->name=name;
        this->children =children;
    }

};


struct P : Tag {
    P(const string& text) : Tag( "P", text){}
    P(initializer_list<Tag> children):  Tag{"P", children} {}
};

struct Img : Tag {
    Img( const string& url ) : Tag{"img",url} {
        attributes.emplace_back(make_pair("src",url));
    }
};

int main(){
    cout<< P{Img{ "Http//hellopacman.com"}};

    return 0;

}