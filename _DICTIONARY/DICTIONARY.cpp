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
void Dictionary::addToDictionary(WORDS englishWord, WORDS germanWord)
{
    this->englishWords.insert(pair<string, WORDS>(englishWord.word, englishWord));
    this->germanWords.insert(pair<string, WORDS>(germanWord.word, germanWord));
}
bool Dictionary::removeFromDictionary(string)
{

}
bool Dictionary::fixAWord(WORDS, WORDS)
{

}
void Dictionary::read()
{
    ifstream dictionaryFile("../_IOFILES/dictionary.txt");
    string input;
    WORDS germanWord; //words to read into
    WORDS englishWord;
    WORDS empty;
    if(!dictionaryFile.is_open())
    {
        cout << "Dictionary file does not exist." << endl;
    }
    else
    {   bool readingEnglishWord = true;
        while(dictionaryFile >> input)
        {
            cout << "Starting with a word..." << endl;
            //First file marker: $EWORD
            if(input == "$EWORD")
            {
                cout << "Matched the name of an english word..." << endl;
                dictionaryFile >> input;
                englishWord.word = input;
            }
            else if(input == "$INDEXTRANSLATION")
            {
                cout << "Matched the " << "READINGANENGLISHWORD(" << readingEnglishWord << ") word's translation..." << endl;
                dictionaryFile >> input;
                //use readingEnglishWord to distinguish GermanIndex and EnglishIndex
                if (readingEnglishWord)
                    englishWord.indexToTranslation = input;
                else
                    germanWord.indexToTranslation = input;
            }
            else if(input == "$TYPE")
            {
                cout << "Matched the english word's type..." << endl;
                dictionaryFile >> input;
                germanWord.type = input;
                englishWord.type = input;
            }
            else if(input == "$CASE")
            {
                dictionaryFile >> input;
                if(input == "NOMINATIVE")
                {
                    germanWord.wordCase = NOMINATIVE;
                    englishWord.wordCase = NOMINATIVE;
                }
                else if(input == "ACCUSATIVE")
                {
                    germanWord.wordCase = NOMINATIVE;
                    englishWord.wordCase = NOMINATIVE;
                }
                else if(input == "DATIVE")
                {
                    germanWord.wordCase = DATIVE;
                    englishWord.wordCase = DATIVE;
                }
                else
                {
                    cout << "##WARNING: CASE NOT FOUND. DEFAULTING TO NOMINATIVE##" << endl;
                    germanWord.wordCase = NOMINATIVE;
                    englishWord.wordCase = NOMINATIVE;
                }
            }
            else if(input == "$EC")
            {
                cout << "Matched conjugation flag... reading english conjugation now..." << endl;
                while(true)
                {
                    dictionaryFile >> input;
                    if(input != "$EOEC")
                        englishWord.conjugation.push_back(input);
                    else
                        break;
                }
                cout << "...Done w/ english conjugation" << endl;
                //use $EOEC to stop loop
            }
            else if(input == "$ENDOFEWORD")
            {
                cout << "End of english word." << endl;
                //END OF ENGLISH WORD  
                readingEnglishWord = false; 
            }
            else if(input == "$GWORD")
            {
                dictionaryFile >> input;
                cout << "Matched the name of an german word..." << endl;
                germanWord.word = input;
            }
            else if(input == "$GC")
            {
                cout << "Matched conjugation flag... reading german conjugation now..." << endl;
                while(true)
                {
                    dictionaryFile >> input;
                    if(input != "$EOGC")
                        germanWord.conjugation.push_back(input);
                    else
                        break;
                }
                cout << "...Done w/ german conjugation" << endl;
                //use $EOGC to stop loop
            }
            else if(input == "$ENDOFGWORD")
            {
                cout << "Matched the end of a german word." << endl;
                readingEnglishWord = true;
            }
            else if(input == "$EOWORD")
            {
                cout << "Matched the end of a word. Adding it to the map now..." << endl;
                germanWord.active = true;
                englishWord.active = true;
                germanWords.insert(pair<string, WORDS>(germanWord.word, germanWord));
                englishWords.insert(pair<string, WORDS>(englishWord.word, englishWord));
                englishWord = empty;
                germanWord = empty;
                cout << "Done writing to map." << endl;
            }
            else if(input == "$EOD")
            {
                cout << "DONE READING dictionary.txt" << endl;
                dictionaryFile >> input;
            }
            else
            {
                cout << "*****************************INPUT IS: " << input << endl;
                cout << "ERROR: I DONT KNOW WHAT HAPPENED! (called from constructor)" << endl;
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


        // int englishCount = 0;
        // int germanCount = 0;
        // if(englishFile.is_open() && germanFile.is_open()) //if both files exist
        // {
        //     //then read it
        //     cout << "Reading German.txt & English.txt..." << endl;
        //     char germanInput[100];
        //     char englishInput[100];
        //     while(germanFile>>germanInput)
        //     {
        //         englishFile >> englishInput;
        //         string gword = germanInput;
        //         string eword = englishInput;
        //         WORDS w;
        //         w.GermanWord = gword;
        //         w.EnglishWord = eword;
        //         this->Words.push_back(w); //Fill the Words array.
        //         germanCount++;
        //     }
        //     cout << "Done reading German.txt & English.txt." << endl;
        // }
        // else if(!germanFile.is_open() || !englishFile.is_open())
        // {
        //     cout << "SOMETHING IS MISSING!!!" << endl;
        // }
        // germanFile.close();
        // englishFile.close();
        // if(englishVerbFile.is_open() && germanVerbFile.is_open())
        // {
        //     cout << "Reading german-verbs.txt & english-verbs.txt..." << endl;
        //     char germanInput[100];
        //     char englishInput[100];
        //     while(englishVerbFile>>englishInput)
        //     {
        //         string everb = englishInput;
        //         //cout << "reading " << everb << endl;
        //         vector <string> gvverb;
        //         for(int i = 0; i < 7; i++) //since the conjugations have 7 different verbs.
        //         {
        //             germanVerbFile >> germanInput;
        //             string gverb = germanInput;
        //             //cout << "reading " << gverb << endl;
        //             gvverb.push_back(gverb);
        //         }
        //         VERBS v;
        //         v.EnglishVerb = everb;
        //         v.GermanConjugations = gvverb;
        //         this->Verbs.push_back(v);
        //     }
        //     cout << "Done reading german-verbs.txt & english-verbs.txt" << endl;
        // }
        // else
        // {
        //     cout << "THE VERBS ARE MISSING!" << endl;
        // }
