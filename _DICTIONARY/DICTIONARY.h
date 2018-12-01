#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::string;
using std::vector;

#ifndef DICTIONARY

#define DICTIONARY

struct WORDS
{
    string word; //Contains the word as a string.
    vector <string> conjugation;
    string indexToTranslation; //Contains the index to its counterpart / translation.
    string type; //Type of word. 
};

class Dictionary
{
    private:
        map <string, WORDS> englishWords;
        map <string, WORDS> germanWords;

        void read();
        void write();
    protected: 
    public:
        //constructors
        Dictionary();
        ~Dictionary();

        bool lookUp(string);
        void addToDictionary(WORDS, WORDS);
        bool removeFromDictionary(string);
        bool fixAWord(WORDS, WORDS);
};

#endif