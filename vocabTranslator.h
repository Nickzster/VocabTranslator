#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef VOCAB
#define VOCAB
const int SIZE = 100000;

class VocabTranslator
{
    private:
        int maxSize;
        vector <string> englishWords;
        vector <string> germanWords;
        //vector <string list> germanVerbs;
    public:

    VocabTranslator();
    ~VocabTranslator();
    void write();
    void read();
    void addWord(string, string);
    //void addWord(string, list);
    void printAll();
    string translateToEnglish(string);
    string translateToGerman(string);
};

#endif