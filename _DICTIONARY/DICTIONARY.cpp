#include <vector>
#include <string>
#include "DICTIONARY.h"
using namespace std;

int generateIndex(string word) //generates an index
{
    int sum = 0;
    char selectedCharacter; //holds an individual character
    int index;
    for(int i = 0; i < word.size(); i++) //step 1 - add the ascii values together
    {
        selectedCharacter = word.at(i); //pull the character at slot i
        sum += (int)selectedCharacter; //and add its ascii value to sum
    }
    index = sum % MAXWORDSIZE; //then take the modulus of the array size to create the index.
    return index;
}
void read() //reads to a file
{
    cout << "Reading input files..." << endl;
    //read
    cout << "Done." << endl;
}
void write() //writes to a file
{
    cout << "Writing to output files..." << endl;
    //write
    cout << "Done." << endl;
}
void resetQuickIndex() //resets quick index. Used by the translator.
{
    this->quickIndex = -1;
}
dictionary() //constructor
{
    cout << "********** ...calling dictionary constructor **********" << endl;
    void resetQuickIndex(); //initalize the quickIndex to invalid(-1).
    read();
}
~dictionary() //destructor
{
    cout << "********** ...calling dictionary destructor **********" << endl;
    write();
}
bool lookUp(string word) //Checks to see if the given word is in the dictionary. If true, stores its index in "quickIndex"
{
    
}
/*
    A set of words: An english word and it's translation in german.
*/

void addToDictionary(WORDS G, WORDS E) //Adds a set of words to the dictionary.
{
    
}
bool removeFromDictionary(string) //Removes a set of words from the dictionary.
{

}
bool fixAWord(WORDS, WORDS) //Reinitalizes a set of words in the dictionary.
{

}
