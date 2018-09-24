#include <iostream>

#include <string>

#include <list>

#include "vocabTranslator.h"

using namespace std;

void AddWords(VocabTranslator &v);
void TransToGerman(VocabTranslator &v);
void TransToEnglish(VocabTranslator &v);


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
        cout << "1. Add Words to this Dictionary." << endl;
        cout << "2. Translate: English -> German" << endl;
        cout << "3. Translate: German -> English" << endl;
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
                TransToGerman(v);
                break;
            case '3':
                TransToEnglish(v);
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
        if(EnglishWord.at(0) == 'q')
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
void TransToGerman(VocabTranslator &v)
{
    bool Translate = true;
    string EnglishWord;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while (Translate)
    {
        cout << "Vocab Word: ";
        cin >> EnglishWord;
        if(EnglishWord.at(0) == 'q')
        {
            return;
        }
        cout << EnglishWord << " auf deutsch ist " << v.translateToGerman(EnglishWord) << endl;
    }
}
void TransToEnglish(VocabTranslator &v)
{
    bool Translate = true;
    string GermanWord;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while (Translate)
    {
        cout << "Wortschatz: ";
        cin >> GermanWord;
        if(GermanWord.at(0) == 'q')
        {
            return;
        }
        cout << GermanWord << " in english is " << v.translateToEnglish(GermanWord) << endl;
    }
}