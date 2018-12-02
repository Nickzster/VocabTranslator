#include <iostream>
#include <string>
#include "DICTIONARY.h"

using namespace std;

void helpFunction();
void addWordsFunction();
void translateFunction(string);
void fixMistakeFunction(string);
void printWord(WORDS);

int main(int argc, char* argv[])
{
    //List of args
    //--help -> lists all args
    //--addwords -> opens a looping function that lets the user enter words to the dictionary
    //--translate <wordtotranslate> -> translates the given word. Will give all the information about the translated word.
    //--fixmistake <mistaketofix> -> searches for the given mistake input. If it is found, the program will prompt the user for the replacement string.
    string command = string(argv[1]);
    if(argc == 1)
    {
        helpFunction();
    }
    if(command == "--help")
    {
        helpFunction();
    }
    else if(command == "--addwords")
    {
        addWordsFunction();
    }
    else if(command == "--translate")
    {
        if(argc < 3)
        {
            cout << "Not enough parameters supplied for translate function" << endl;
        }
        else
        {
            for(int i = 2; i < argc; i++)
            {
                string wordToTranslate = string(argv[i]);
                translateFunction(wordToTranslate);
            }
        }
    }
    else if(command == "--fixmistake")
    {
        if(argc < 3)
        {
            cout << "Not enough parameters supplied for fix-mistake function" << endl;
        }
        else
        {
            for(int i = 2; i < argc; i++)
            {
                string wordToFix = argv[i];
                fixMistakeFunction(wordToFix);
            }
        }
    }
    else
    {
        helpFunction();
    }
    return 0;
}

void helpFunction()
{
    cout << "====================================================" << endl;
    cout << endl << "Here are your options:" << endl;
    cout << "--help -> lists all possible arguments" << endl;
    cout << "--addwords -> Lets you add words to the dictionary" << endl;
    cout << "--translate <wordtotranslate> <anotherwordtotranslate> ... -> translates given word(s). All available information is given about translated word." << endl;
    cout << "--fixmistake <wordtofix> <anotherwordtofix> ... -> fixes given words. If they are found, program will prompt you for replacement word." << endl << endl;

    cout << "====================================================" << endl;
}
void addWordsFunction()
{
    while(true)
    {
        string input;
        WORDS gword;
        WORDS eword;
        cout << "Now adding a word...." << endl;
            // $EWORD
        cout << "Enter the word in english: ";
        cin >> input;
        eword.word = input;
        gword.indexToTranslation = input;
            // $INDEXTRANSLATION
        cout << "Enter the german equivalent: ";
        cin >> input;
        eword.indexToTranslation = input;
        gword.word = input;
            // $TYPE
        cout << "Enter the type of word ";
        cin >> input;
        gword.type = input;
        eword.type = input;
        if(input == "VERB")
        {
            cout << "***You have entered a verb. Starting with PRESENT CASE:" << endl;
            eword.conjugation.push_back("@PRESENT");
            cout << "Enter the english conjugation for I: ";
            cin >> input;
            eword.conjugation.push_back(input);
            cout << "Enter the english conjugation for You: ";
            cin >> input;
            cout << "Enter the english conjugation for he/she/it: ";
            cin >> input;
            for(i = 0; i < 3; i++)
                eword.conjugation.push_back(eword.conjugation.at(2)); //since conjugation for plural cases are the same for "You".
            cout << "***Now, enter the german equivalent, Starting with PRESENT CASE:" << endl;
            cout << "Enter the german conjugation for ich: ";
            cin >> input;
        else
        {

        }
            // $CASE
            // $EC 
            //prompt for present and past if type == verb
            // $EOEC
            // $ENDOFEWORD
            // $GWORD
            // $INDEXTRANSLATION
            // $GC
            // $EOGC
            // $ENDOFGWORD
            // $EOWORD 
    }
}
void translateFunction(string wordToTranslate)
{
    WORDS translatedWord;
    DICTIONARY d;
    translatedWord = d.lookUp(wordToTranslate);
    printWord();

}
void fixMistakeFunction(string wordToFix)
{
    cout << "called fix mistake" << endl;
}

void printWord(WORDS wordToPrint)
{
    cout << "Word to be Translated: " << wordToPrint.indexToTranslation << endl;
    cout << ""
}