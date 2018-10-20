#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef VOCAB
#define VOCAB

const int SIZE = 58211;

struct WORD
{
    string word; //stores the word (english or german)
    vector <string> conjugations; //stores conjugations
    int index; //stores the index to the other language's array spot.
    int offset; //if a collision occurs, move to the next available array slot. store the offset here.
};

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
        //Old
        vector <WORDS> Words;
        vector <VERBS> Verbs;
        //New
        WORD GermanWords[SIZE];
        WORD EnglishWords[SIZE];
        vector<int> GermanWordsIndicies;
        vector<int> EnglishWordsIndicies;
        //vector <string list> germanVerbs;

        int searchForAWord(string);
        int searchForAVerb(string);
        int searchForASpecificConjugation(string, vector <string> &GermanConjugations);
        void displayConjugations(VERBS);
        int VocabHash(string); //To generate indicies
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