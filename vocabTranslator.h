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

struct VERBS
{
    string EnglishVerb;
    vector <string> GermanConjugations;
};
class VocabTranslator
{
    private:
        vector <WORDS> Words;
        vector <VERBS> Verbs;
        //vector <string list> germanVerbs;

        int searchForAWord(string);
        int searchForAVerb(string);
        int searchForASpecificConjugation(string, vector <string> &GermanConjugations);
        void displayConjugations(VERBS);
    public:

    VocabTranslator();
    ~VocabTranslator();
    void write();
    void read();
    void addWord(string, string);
    void addConjugation(string, vector <string> &GermanConjugations);
    //void addWord(string, list);
    void printAll();
    void translate(string);
    void correction(string,string);
};

#endif