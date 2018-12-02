#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::string;
using std::vector;
using std::map;

#ifndef DICTIONARY

#define DICTIONARY

//NEED TO ADD ANOTHER ENTRY THAT TELLS WHETHER THE WORD IS GERMAN OR ENGLISH.
//NEED TO CHANGE I/O TO REFELCT THIS CHANGE.
struct WORDS
{ 
    string word; //Contains the word as a string. Vector represents a word with separate parts.
    vector <string> conjugation;
    string indexToTranslation; //Contains the index to its counterpart / translation.
    string type; //Type of word.
    enum wordCase {NOMINATIVE, ACCUSATIVE, DATIVE}; //case of the word
    bool active; 
};

class Dictionary
{
    private:
        map <string, WORDS> englishWords;
        map <string, WORDS> germanWords;
        string[3] wordCaseStrings;
        bool quickSearch();
        bool nSearch();
        void read();
        void write();
    public:
        //constructors
        Dictionary();
        ~Dictionary();

        string lookUp(string);
};

#endif