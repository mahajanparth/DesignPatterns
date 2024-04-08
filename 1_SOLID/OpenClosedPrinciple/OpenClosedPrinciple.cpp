// Open CLosed Principle
// It says that code should be written in a way that it should be open for extension ( inheritence) but closed for mutation/modification

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

// Here if you see the class ProductFilter is modified at each step of the way
// rather than doing this we have to build this class again and again in binary and it would be hell
// if two filter were made at point A in time and something is added after, it should be send in extension so that only that extension is build
struct ProductFilter
{
    typedef vector<Product *> Items;

    Items by_size(Items items, const Size size)
    {
        Items results;
        for (auto &ele : items)
        {
            if (ele->size == size)
            {
                results.push_back(ele);
            }
        }
        return results;
    }

    Items by_color(Items items, const Color color)
    {
        Items results;
        for (auto &ele : items)
        {
            if (ele->color == color)
            {
                results.push_back(ele);
            }
        }
        return results;
    }

    Items by_size_and_color(Items items, const Size size, const Color color)
    {
        Items result;
        for (auto &i : items)
            if (i->size == size && i->color == color)
                result.push_back(i);
        return result;
    }
};

// A better execution would be like this
// we create two interfaces
// one interface is the condition interface which is generic using templates
// second is the filter interface which uses the first interface to see if the condition is met
template <typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

// Now the base interfaces are defined we can build some concerate implementations

// Lets Build Color Specifications

struct ColorSpecifiaction : Specification<Product>
{
    Color color;
    ColorSpecifiaction(Color color) : color{color} {}
    bool is_satisfied(Product *item) const override
    {
        return item->color == color;
    }
};

// add another specification at a later time without modifying already written code
struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size size) : size{size} {}
    bool is_satisfied(Product *item) const override
    {
        return item->size == size;
    }
};
template <typename T>
struct AndSpecification : Specification<T>
{

    const Specification<T> &first;
    const Specification<T> &second;
    AndSpecification(const Specification<T>& spec1, const Specification<T>& spec2) : first{spec1}, second{spec2} {}
    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

// Lets make a Better Filter
// This is a concrete implementation of filter

struct betterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product *> results;
        for (auto &ele : items)
        {
            if (spec.is_satisfied(ele))
            {
                results.push_back(ele);
            }
        }
        return results;
    }
};

int main()
{

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    const vector<Product *> all{&apple, &tree, &house};

    betterFilter bf;
    ColorSpecifiaction green(Color::green);
    auto green_things = bf.filter(all, green);
    for (auto &x : green_things)
        cout << x->name << " is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    // auto big_green_things = bf.filter(all, green_and_large);

    // use the operator instead (same for || etc.)
    // auto spec = green && large;
    for (auto &x : bf.filter(all, green_and_large))
        cout << x->name << " is green and large\n";

    // warning: the following will compile but will NOT work
    // auto spec2 = SizeSpecification{Size::large} &&
    //              ColorSpecification{Color::blue};

    getchar();
    return 0;
}
