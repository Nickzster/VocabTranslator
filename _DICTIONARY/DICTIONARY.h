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
    TYPE type; //Type of word. 
    vector <string> word; //Contains the word as a string. Vector represents a word with separate parts.
    vector <string> conjugation;
    string indexToTranslation; //Contains the index to its counterpart / translation.
    string type; //Type of word. 
};

class Dictionary
{
    private:
        map <string, WORDS> englishWords;
        map <string, WORDS> germanWords;

        bool quickSearch();
        bool nSearch();
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