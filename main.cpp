#include <iostream>

#include <string>

#include <list>

#include "vocabTranslator.h"

using namespace std;

void AddWords(VocabTranslator &v);
void AddConj(VocabTranslator &v);
void Translate(VocabTranslator &v);

int main()
{
    bool MainMenu = true;
    char input;
    VocabTranslator v;
    cout << "Welcome to the German & English Translator by Nick Zimmermann." << endl;
    cout << "Please start by making a selection below." << endl;
    cout << "==============================================================" << endl;
    while(MainMenu)
    {
        cout << endl;
        cout << "1. Add vocabulary (wortschatz) to this Dictionary." << endl;
        cout << "2. Add a verb to this Dictionary." << endl;
        cout << "3. Translate a word" << endl;
        cout << "Q. Quit" << endl;
        cout << "Please make your selection by typing the corresponding number: " << endl;
        cout << "==> ";
        cin >> input;
        switch(input)
        {
            case '1':
                AddWords(v);
                break;
            case '2':
                AddConj(v);
                break;
            case '3':
                Translate(v);
                break;
            case 'Q':
                MainMenu = false;
                break;
            case 'q':
                MainMenu = false;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
    cout << endl;
    cout << "Thanks for using this program!" << endl;
    cout << endl;
    return 0;   
}

void AddWords(VocabTranslator &v)
{
    bool AddAWord = true;
    string EnglishWord;
    string GermanWord;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while(AddAWord)
    {

        cout << "Enter an English word: ";
        cin >> EnglishWord;
        if(EnglishWord.at(0) == 'q' && EnglishWord.size() == 1)
        {
            return;
        }
        cout << "Enter the German Word Equivalent: ";
        cin >> GermanWord;
        if(GermanWord.at(0) == 'q')
        {
            return;
        }
        v.addWord(EnglishWord, GermanWord);
    }
}

void AddConj(VocabTranslator &v)
{
    bool conj = true;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while(conj)
    {
        string EnglishVerb;
        string GermanInput;
        vector <string> GermanConjugations;
        cout << "Enter an english verb: ";
        cin >> EnglishVerb;
        if(EnglishVerb.at(0) == 'q')
        {
            return;
        }
        cout << "Enter the German Verb Equivalent: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for Ich: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for Du: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for er,sie,es: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for Wir: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for Ihr: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        cout << "Enter the Conjugation for Sie: ";
        cin >> GermanInput;
        if(GermanInput.at(0) == 'q')
        {
            return;
        }
        GermanConjugations.push_back(GermanInput);
        GermanInput = "";
        v.addConjugation(EnglishVerb, GermanConjugations);
    }
}


void Translate(VocabTranslator &v)
{
    bool trans = true;
    string WordToTranslate;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while (trans)
    {
        cout << "Enter a word to translate: ";
        cin >> WordToTranslate;
        if(WordToTranslate.at(0) == 'q')
        {
            return;
        }
        v.translate(WordToTranslate);
    }
}