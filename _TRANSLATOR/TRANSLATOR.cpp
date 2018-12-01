    #include <iostream>
    #include <list>
    #include <string>
    #include <fstream>
    #include <ostream>
    #include <istream>
    #include "TRANSLATOR.h"
    using namespace std;

    VocabTranslator::VocabTranslator()
    {
        cout << "INITALIZING======================" << endl;
        cout << "calling constructor" << endl;
        read();
        cout << "=================================" << endl;
        cout << endl;
    }
    VocabTranslator::~VocabTranslator()
    {   
        cout << endl;
        cout << "INITALIZING======================" << endl;
        cout << "calling destructor" << endl;
        write();
        cout << "=================================" << endl;
    }

   


    
    void VocabTranslator::addWord(string englishWordToAdd, string germanWordToAdd)
    {
        WORDS w;
        w.GermanWord = germanWordToAdd;
        w.EnglishWord = englishWordToAdd;
        this->Words.push_back(w);
    }

    void VocabTranslator::addConjugation(string englishVerb, vector <string> &GermanConjugations)
    {
        VERBS v;
        v.EnglishVerb = englishVerb;
        v.GermanConjugations = GermanConjugations;
        this->Verbs.push_back(v);
    }

    void VocabTranslator::printAll()
    {
        for(int i = 0; i < Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            cout << w.EnglishWord;
            cout << " - " << endl;
            cout << w.GermanWord << endl;
        }
    }


    int VocabTranslator::searchForAWord(string word)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(word == w.GermanWord || word == w.EnglishWord)
            {
                return i;
            }
        }
        return -1;
    }

    int VocabTranslator::searchForAVerb(string verb)
    {
        for(int i = 0; i < this->Verbs.size(); i++) //Search the verbs vector for what we are looking for.
        {
            VERBS v;
            v = Verbs.at(i);
            if(verb == v.EnglishVerb) //If the english verb matches, 
            {
                return i; //Then we have what we are looking for.
            }
            else //If it does not, we need to check all of the german conjugations.
            {
                vector <string> gc = v.GermanConjugations;
                int conjIndex = searchForASpecificConjugation(verb, gc);
                if(conjIndex != -1 && conjIndex >= 0) //we found it!
                {
                    return i;
                }
            }
        } //If the loop breaks, then it is not in the verb dictionary.
        return -1; //so return an empty verbs list.
    }

    int VocabTranslator::searchForASpecificConjugation(string verb, vector <string> &GermanConjugations)
    {
        for(int i = 0; i < GermanConjugations.size(); i++)
        {
            if(GermanConjugations.at(i) == verb)
            {
                return i;
            }
        }
        return -1;
    }

    void VocabTranslator::displayConjugations(VERBS v)
    {
        cout << endl;
        vector <string> gc = v.GermanConjugations;
        cout << "The word you have typed in is a verb!" << endl;
        cout << "=========CONJUGATION DISPLAY========" << endl;
        cout << "English: " << v.EnglishVerb << endl;
        cout << "===== CONJUGATION: " << gc.at(0) << " =====" << endl;
        cout << "Ich: " << gc.at(1) << endl;
        cout << "Du: " << gc.at(2) << endl;
        cout << "er, sie, es: " << gc.at(3) << endl;
        cout << "Wir: " << gc.at(4) << endl;
        cout << "Ihr: " << gc.at(5) << endl;
        cout << "Sie: " << gc.at(6) << endl;
        cout << "====================================" << endl;
        cout << endl;
    }

    void VocabTranslator::translate(string wordToTranslate)
    {
        //First, we search for a vocab word.
        int index = searchForAWord(wordToTranslate);
        WORDS w;
        bool validReturn = false;
        if(!(index == -1))
        {
            w = this->Words.at(index);
            validReturn = true;
        }
        if(validReturn && w.EnglishWord == wordToTranslate) //If the word is an english word
        {
            cout << wordToTranslate << " auf deutsch ist " << w.GermanWord << endl; //Translate it to its german counterpart, and display it.
            return;
        }
        else if(validReturn && w.GermanWord == wordToTranslate) //If the word is a german word
        {
            cout << wordToTranslate << " in english is " << w.EnglishWord << endl; //Translate it to its english counterpart, and display it.
            return;
        }
        else
        {
            //cout << wordToTranslate << " isn't in the dictionary... let's check the conjugations..." << endl;
        }
        //If we can't find the vocab word, then we need to search the conjugations.
        validReturn = false;
        index = searchForAVerb(wordToTranslate);
        VERBS v;
        if(!(index == -1))
        {
            v = this->Verbs.at(index);
            validReturn = true;
            cout << "***valid return is true ***" << endl;
        }
        if(validReturn && v.EnglishVerb == wordToTranslate || v.GermanConjugations.size() > 1) //Regardless if we find it, we will display the entire conjugations table.
        {
            displayConjugations(v);
            return;
        }
        else
        {
            cout << "This word is not in the dictionary nor is it in the verb dictionary." << endl;
        }

    }

    void VocabTranslator::correction(string wordThatIsCorrect, string wordToBeFixed)
    {
        int index = searchForAWord(wordToBeFixed); //First, we find the incorrect word in the dictionary.
        if(!(index == -1)) //If we find the word, replace it.
        {
            WORDS w = this->Words.at(index);
            if(w.EnglishWord == wordToBeFixed)
            {
                w.EnglishWord = wordThatIsCorrect;
                //cout << "**A English word!" << endl;
            }
            else if(w.GermanWord == wordToBeFixed)
            {
                w.GermanWord = wordThatIsCorrect;
                //cout << "**A German word!" << endl;
            }
            this->Words.at(index) = w; //then update it.
            cout << "A word was fixed in the dictionary!" << endl;
        }
        //If we don't find the word, then we need to check the verbs.
        index = searchForAVerb(wordToBeFixed);
        if(!(index == -1)) //If we find the word, we need to replace it.
        {
            VERBS v = this->Verbs.at(index);
            if(v.EnglishVerb == wordToBeFixed) //IF the english part needs to be fixed.
            {
                v.EnglishVerb = wordThatIsCorrect;
            }
            else if(searchForASpecificConjugation(wordToBeFixed, v.GermanConjugations) != -1) //If we find it in the conjugations
            {   
                v.GermanConjugations.at(searchForASpecificConjugation(wordToBeFixed, v.GermanConjugations)) = wordThatIsCorrect; 
            }
            this->Verbs.at(index) = v; //then update it.
            cout << "A word was fixed in the VERB dictionary!" << endl;
        }

    }