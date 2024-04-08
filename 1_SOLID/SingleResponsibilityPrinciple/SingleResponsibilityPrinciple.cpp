#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

/* Single Responsibiity Principle :
    Each class should be responsible for a specific responsibility 
    One should identify the seperation of Concerns and assign one responsibility per say 
*/
class Journal
{
    public:
    string title;
    vector<string> entries;
    explicit Journal(const string &title) : title{title} {}
    void add(const string &entry);
    // persistence is a seperate concern
    void save(const string &filename);
};

void Journal::add(const string &entry)
{
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry);
}

//Journal should not be responsible for saving process 
// as saving can happen in multiple ways eg databases , files , etc 
//so providing save function for every diff way is not recommeneded 
void Journal::save(const string &filename)
{
    ofstream ofs(filename);
    for (auto &item : entries)
    {
        ofs << item << endl;
    }
}

//Rather we make a 

class persistenceManager{
    public:
    static void save(const Journal& j, const string& filename){
        
        ofstream ofs(filename);
        for (auto& s : j.entries)
            ofs << s << endl;
        
    }
};


int main(){
    Journal journal("Dear Diary");
    journal.add(" I had a good day on 8 april\n");
    journal.add(" I finished wings of fire book and started with modern design pattern\n");

    //journal.save("diary.txt");

    persistenceManager pm;

    pm.save(journal,"diary.txt");
    
    return 0;
}