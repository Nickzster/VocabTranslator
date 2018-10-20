#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

#ifndef DICTIONARY

#define DICTIONARY

const int MAXWORDSIZE = 501;
struct WORDS
{
    string word; //Contains the word as a string.
    vector <string> conjugation;
    int indexToTranslation; //Contains the index to its counterpart / translation.
    int offset; //The method of implementation uses a hashing function. This handles collisions.
    string type; //Type of word. 
    bool found;
};

class dictionary
{
    private:
        string germanWords[MAXWORDSIZE];
        string englishWords[MAXWORDSIZE];
        vector <int> germanWordIndicies; //used for i/o
        vector <int> englishWordIndicies; //used for i/o
        int quickIndex; //used by look-up

        void read();
        void write();
    protected: 
    public:
        //constructors
        dictionary();
        ~dictionary();

        bool lookUp(string);
        void addToDictionary(WORDS, WORDS);
        bool removeFromDictionary(string);
        bool fixAWord(WORDS, WORDS);
};

#endif