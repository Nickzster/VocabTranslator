#include <iostream>
#include <string> 
#include "DICTIONARY.h"
#include <fstream>

using namespace std;

bool Dictionary::lookUp(string)
{

}
void Dictionary::addToDictionary(WORDS, WORDS)
{

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
    if(dictionaryFile.is_open())
    {
        cout << "Dictionary file does not exist." << endl;
    }
    else
    {   bool readingEnglishWord = true;
        while(dictionaryFile >> input)
        {
            //First file marker: $EWORD
            if(input == "$EWORD")
            {
                dictionaryFile >> input;
                englishWord.word = input;
            }
            else if(input == "$INDEXTRANSLATION")
            {
                dictionaryFile >> input;
                //use readingEnglishWord to distinguish GermanIndex and EnglishIndex
                if (readingEnglishWord)
                    englishWord.indexToTranslation = input;
                else
                    germanWord.indexToTranslation = input;
            }
            else if(input == "$TYPE")
            {
                dictionaryFile >> input;
                germanWord.type = input;
                englishWord.type = input;
            }
            else if(input == "$EC")
            {
                while(input != "EOEC")
                {
                    dictionaryFile >> input;
                    englishWord.conjugation.push_back(input);
                }
                //use $EOEC to stop loop
            }
            else if(input == "$EOFEWORD")
            {
                //END OF ENGLISH WORD  
                readingEnglishWord = false; 
            }
            else if(input == "$GWORD")
            {

            }
            else if(input == "$GC")
            {
                //use $EOGC to stop loop
            }
            else if(input == "$EOFGWORD")
            {
                readingEnglishWord = true;
            }
            else
            {
                cout << "ERROR: I DONT KNOW WHAT HAPPENED! (called from constructor)" << endl;
            }
        }
    }
    
    //englishWords.insert(pair<string, WORDS>(w.name, w));

}
void Dictionary::write()
{
    ofstream dictionaryFile("../_IOFILES/dictionary.txt");
    // cout << "Closing the file by outputting the files..." << endl;
    // for(int i = 0; i < this->Words.size(); i++)
    // {
    //     WORDS w = Words.at(i);
    //     EnglishOut << w.EnglishWord;
    //     EnglishOut << endl;
    //     GermanOut << w.GermanWord;
    //     GermanOut << endl;
    // }
    // for(int i = 0; i < this->Verbs.size(); i++)
    // {
    //     VERBS v = Verbs.at(i);
    //     EnglishVerbsOut << v.EnglishVerb;
    //     EnglishVerbsOut << endl;
    //     vector <string> gc;
    //     gc = v.GermanConjugations;
    //     for(int i = 0; i < gc.size(); i++) //usually, there is the vocabulary word + the conjugations, making 7 total elements.
    //     {
    //         GermanVerbsOut << gc.at(i);
    //         GermanVerbsOut << endl;
    //     }
    // }
    // cout << "Done." << endl;
    dictionaryFile.close();
}

Dictionary::Dictionary()
{
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