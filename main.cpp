#include <iostream>

#include <string>

#include <list>

#include "TRANSLATOR.h"

using namespace std;

void AddWords(VocabTranslator &v);
void AddConj(VocabTranslator &v);
void Translate(VocabTranslator &v);
void fix(VocabTranslator &v);

int main()
{
    bool MainMenu = true;
    char input;
    VocabTranslator v;
    cout << "Welcome to the German & English Translator by Nick Zimmermann." << endl;
    cout << "Please start by making a selection below." << endl;
    cout << "==============================================================" << endl << endl;
    while(MainMenu)
    {
        cout << "MAIN MENU =================================================================" << endl;
        cout << endl;
        cout << "1. Add vocabulary (wortschatz) to this Dictionary." << endl;
        cout << "2. Add a verb to this Dictionary." << endl;
        cout << "3. Translate a word" << endl;
        cout << "4. Make a correction" << endl;
        cout << "Q. Quit" << endl;
        cout << "Please make your selection by typing the corresponding number: " << endl;
        cout << "==> ";
        cin >> input;
        cout << "===========================================================================" << endl << endl;
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
            case '4':
                fix(v);
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
    cout << "ADD A WORD MENU ===========================================================" << endl;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while(AddAWord)
    {
        cout << "Enter an English word: ";
        cin >> EnglishWord;
        if(EnglishWord.at(0) == 'q' && EnglishWord.size() == 1) return;
        cout << "Enter the German Word Equivalent: ";
        cin >> GermanWord;
        if(GermanWord.at(0) == 'q' && GermanWord.size() == 1) return;
        v.addWord(EnglishWord, GermanWord);
    }
}

void AddConj(VocabTranslator &v)
{
    bool conj = true;
    cout << "ADD A CONJUGATION MENU ===============================================" << endl;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while(conj)
    {
        
    }
}

void Translate(VocabTranslator &v)
{
    bool trans = true;
    string WordToTranslate;
    cout << "TRANSLATE MENU ============================================================" << endl;
    cout << "===> To return to the menu, type in Q at any time." << endl;
    while (trans)
    {
        cout << "Enter a word to translate: ";
        cin >> WordToTranslate;
        if(WordToTranslate.at(0) == 'q' && WordToTranslate.size() == 1) return;
        v.translate(WordToTranslate);
    }
}

void fix(VocabTranslator &v)
{
    cout << "CORRECTION MENU ===========================================================" << endl;
    string wordToBeFixed;
    string correctWord;
    cout << "Enter the incorrect word that needs to be fixed: ";
    cin >> wordToBeFixed;
    if(wordToBeFixed.at(0) == 'q' && wordToBeFixed.size() == 1) return;
    cout << "Enter the correct word: ";
    cin >> correctWord;
    if(correctWord.at(0) == 'q' && correctWord.size() == 1) return;
    v.correction(correctWord, wordToBeFixed);
}