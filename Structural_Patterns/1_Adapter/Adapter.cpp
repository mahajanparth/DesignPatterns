#include <iostream>
using namespace std;

//Link : https://www.geeksforgeeks.org/adapter-pattern/

// Target Base interface
class Printer
{
public:
    Printer() = default;
    virtual void print() = 0;
};

// adaptee
class LegacyPrinter
{
public:
    virtual void printDocument()
    {
        cout << "Printing from legacy printer\n";
    }
};

// adapter

class PrinterAdapter : public Printer
{
    LegacyPrinter lgp;

public:
    PrinterAdapter() = default;

    void print() override
    {
        lgp.printDocument();
    }
};

// client code
int main()
{
    PrinterAdapter P = PrinterAdapter();
    P.print();
}
