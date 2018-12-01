#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

#ifndef DICTIONARY

#define DICTIONARY

const int MAXWORDSIZE = 58211;

enum TYPE = {ADJECTIVE, NOUN, ADVERB, PRONOUN, PREPOSITION, CONJUNCTION, DETERMINER, EXCLAMANTION, VERB, SEPREFIXVERB};

struct WORDS
{
    TYPE type; //Type of word. 
    vector <string> word; //Contains the word as a string. Vector represents a word with separate parts.
    vector <string> conjugation;
    int indexToTranslation; //Contains the index to its counterpart / translation.
    int offset; //The method of implementation uses a hashing function. This handles collisions.
    bool found;
};

class dictionary
{
    private:
        int generateIndex(string); //generates an index
        void read(); //reads to a file
        void write(); //writes to a file
        void resetQuickIndex();
    protected: 
        WORDS englishWords[MAXWORDSIZE]; //Stores all english words in the dictionary.
        WORDS germanWords[MAXWORDSIZE]; //stores all german words in the dictionary.
        vector <int> germanWordIndicies; //used for i/o
        vector <int> englishWordIndicies; //used for i/o

        int quickIndex; //used by look-up

        bool quickSearch();
        bool nSearch();
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