#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef VOCAB
#define VOCAB

struct WORDS
{
    string EnglishWord;
    string GermanWord;
};
class VocabTranslator
{
    private:
        vector <WORDS> Words;
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