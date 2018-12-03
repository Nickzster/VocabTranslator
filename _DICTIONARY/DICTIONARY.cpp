#include <iostream>
#include <string> 
#include <iterator>
#include <fstream>
#include <map>

#include "DICTIONARY.h"

using namespace std;

string Dictionary::lookUp(string word)
{
    WORDS gw = germanWords[word];
    WORDS ew = englishWords[word];
    if(ew.word.active)
    {
        return germanWords[ew.indexToTranslation];
    }
    else if(gw.word.active)
    {
        return englishWords[gw.indexToTranslation];
    }
    else
    {
        cout << "Not in dictionary" << endl;
        return "";
    }
}
void Dictionary::read()
{
    ifstream dictionaryFile("../_IOFILES/dictionary.txt");
    string input;
    WORDS germanWord; //words to read into
    WORDS englishWord;
    WORDS empty;
    dictionaryFile >> input;
    while(true)
    {
        if(input == "$word")
        {
            while(true)
            {
                dictionaryFile >> input;
                
            }
        }
    }
    //englishWords.insert(pair<string, WORDS>(w.name, w));
}
void Dictionary::write()
{
    ofstream dictionaryFile("../_IOFILES/dictionary.txt");
    map<string, WORDS>::iterator gMapItr, eMapItr;
    eMapItr = englishWords.begin();
    for(gMapItr = germanWords.begin(); gMapItr != germanWords.end(); ++gMapItr)
    {
        eMapItr++;
        WORDS germanWord = gMapItr->second;
        WORDS englishWord = eMapItr->second;
        // $EWORD
        dictionaryFile << "$EWORD" << endl;
        dictionaryFile << englishWord.word << endl;
        // $INDEXTRANSLATION
        dictionaryFile << "$INDEXTRANSLATION" << endl;
        dictionaryFile << englishWord.indexToTranslation << endl;
        // $EC 
        dictionaryFile << "$EC" << endl;
        for(int i = 0; i < englishWord.conjugation.size(); i++)
        {
            dictionaryFile << englishWord.conjugation.at(i) << endl;
        }
        // $EOEC
        dictionaryFile << "$EOEC" << endl;
        // $ENDOFEWORD
        dictionaryFile << "$ENDOFEWORD" << endl;

        // $GWORD
        dictionaryFile << "$GWORD" << endl;
        dictionaryFile << germanWord.word << endl;
        // $INDEXTRANSLATION
        dictionaryFile << "$INDEXTRANSLATION" << endl;
        dictionaryFile << germanWord.indexToTranslation << endl;
        // $GC
        dictionaryFile << "$GC" << endl;
        for(int i = 0; i < germanWord.conjugation.size(); i++)
        {
            dictionaryFile << germanWord.conjugation.at(i) << endl;
        }
        // $EOGC
        dictionaryFile << "$EOGC" << endl;
        // $ENDOFGWORD
        dictionaryFile << "$ENDOFGWORD" << endl;

        // $TYPE
        dictionaryFile << "$TYPE" << endl;
        // VERB
        dictionaryFile << germanWord.type << endl;

        //$CASE
        dictionaryFile << "$CASE" << endl;
        //CASE
        dictionaryFile << this->wordCaseStrings[germanWord.wordCase] << endl;

        // $EOWORD 
        dictionaryFile << "$EOWORD" << endl;


    }
    // $EOD 
    dictionaryFile << "$EOD" << endl;
    dictionaryFile.close();
}

Dictionary::Dictionary()
{
    this->wordCaseStrings[0] = "NOMINATIVE";
    this->wordCaseStrings[1] = "ACCUSATIVE";
    this->wordCaseStrings[2] = "DATIVE";
    read();
}
Dictionary::~Dictionary()
{
    write();
}
