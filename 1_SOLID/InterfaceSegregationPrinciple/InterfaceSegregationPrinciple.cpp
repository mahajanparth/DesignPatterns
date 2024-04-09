//Interface Segregation Principle 
//Tis says that there is a need for segregation of interfaces and no long/complex interface should be implemented or made 
// Faltu stuff nhi hona chaiye interface meh jisko baar baar implement karna pade 

//Principle Statement: "Clients should not be forced to depend on methods they do not use."
/*
Explanation:

    Fat Interfaces vs. Thin Interfaces: The principle highlights the distinction between "fat" interfaces (interfaces that contain many methods) and "thin" interfaces (interfaces with fewer methods).

    Avoiding Interface Pollution: When a single interface contains multiple methods, it's likely that not all classes implementing the interface will need to use all those methods. This leads to "interface pollution," where classes are forced to implement methods they don't need.

    Client-Specific Interfaces: Instead of having one large interface, it's better to have smaller, more focused interfaces that cater to specific clients or groups of clients. This allows clients to depend only on the methods they require, reducing coupling and promoting cohesion.

    Benefits of ISP: Following ISP leads to cleaner, more maintainable code. It reduces the risk of unintended consequences when modifying interfaces or implementing classes. It also encourages better design practices, such as favoring composition over inheritance.
*/

//YAGNI - You ain't gonna need it 


#include <iostream>
using namespace std;
//BAD CODE Example 

struct Document{
    string name;
    string data;
};

class MFP
{
protected:
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

//Here if we have to only want to implement printer, we still are supplying the functionality  of scanner and faxxer to the user 
// the user of the api might get a wrong sense that the printer might have this functionality 

class IPrinter: public MFP {
    void print(Document& doc) override {

    }
    void scan(Document& doc) override {

    }
    void fax(Document& doc) override {

    }


};

//Clean Code and the correct way 

class Iprinter{
    protected:

    virtual void print(Document& doc) = 0;
};

class IScanner{
    protected:
    
    virtual void scan(Document& doc) = 0;
};
class IFaxer{
    protected:
    
    virtual void fax(Document& doc) = 0;
};

//Implement Interface of Printer Scanner
class IPrinterScanner : protected Iprinter , protected IScanner {

};

//Concrete Implementation 

class PrinterScanner : IPrinterScanner {
    IPrinter& printer;
    IScanner& scanner;

    PrinterScanner(IPrinter& printer, IScanner& scanner)
        : printer{printer},
        scanner{scanner}
    {
    }

    void print(Document& doc) override {

    }

    void scan(Document& doc) override {
        
    }
};

