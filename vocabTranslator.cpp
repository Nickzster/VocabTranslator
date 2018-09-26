    #include <iostream>
    #include <list>
    #include <string>
    #include <fstream>
    #include <ostream>
    #include <istream>
    #include "vocabTranslator.h"
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

    void VocabTranslator::write()
    {
        ofstream GermanOut("german.txt");
        ofstream EnglishOut("english.txt");
        ofstream GermanVerbsOut("german-verbs.txt");
        ofstream EnglishVerbsOut("english-verbs.txt");
        cout << "Closing the file by outputting the files..." << endl;
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w = Words.at(i);
            EnglishOut << w.EnglishWord;
            EnglishOut << endl;
            GermanOut << w.GermanWord;
            GermanOut << endl;
        }
        for(int i = 0; i < this->Verbs.size(); i++)
        {
            VERBS v = Verbs.at(i);
            EnglishVerbsOut << v.EnglishVerb;
            EnglishVerbsOut << endl;
            vector <string> gc;
            gc = v.GermanConjugations;
            for(int i = 0; i < gc.size(); i++) //usually, there is the vocabulary word + the conjugations, making 7 total elements.
            {
                GermanVerbsOut << gc.at(i);
                GermanVerbsOut << endl;
            }
        }
        cout << "Done." << endl;
        GermanOut.close();
        EnglishOut.close();
        GermanVerbsOut.close();
        EnglishVerbsOut.close();
    }

    void VocabTranslator::read()
    {
        ifstream germanFile("german.txt"); //german file to read
        ifstream englishFile("english.txt"); //english file to read
        ifstream englishVerbFile("english-verbs.txt");
        ifstream germanVerbFile("german-verbs.txt");
        //Read the german file first.
        int englishCount = 0;
        int germanCount = 0;
        if(englishFile.is_open() && germanFile.is_open()) //if both files exist
        {
            //then read it
            cout << "Reading German.txt & English.txt..." << endl;
            char germanInput[100];
            char englishInput[100];
            while(germanFile>>germanInput)
            {
                englishFile >> englishInput;
                string gword = germanInput;
                string eword = englishInput;
                WORDS w;
                w.GermanWord = gword;
                w.EnglishWord = eword;
                this->Words.push_back(w); //Fill the Words array.
                germanCount++;
            }
            cout << "Done reading German.txt & English.txt." << endl;
        }
        else if(!germanFile.is_open() || !englishFile.is_open())
        {
            cout << "SOMETHING IS MISSING!!!" << endl;
        }
        germanFile.close();
        englishFile.close();
        if(englishVerbFile.is_open() && germanVerbFile.is_open())
        {
            cout << "Reading german-verbs.txt & english-verbs.txt..." << endl;
            char germanInput[100];
            char englishInput[100];
            while(englishVerbFile>>englishInput)
            {
                string everb = englishInput;
                //cout << "reading " << everb << endl;
                vector <string> gvverb;
                for(int i = 0; i < 7; i++) //since the conjugations have 7 different verbs.
                {
                    germanVerbFile >> germanInput;
                    string gverb = germanInput;
                    //cout << "reading " << gverb << endl;
                    gvverb.push_back(gverb);
                }
                VERBS v;
                v.EnglishVerb = everb;
                v.GermanConjugations = gvverb;
                this->Verbs.push_back(v);
            }
            cout << "Done reading german-verbs.txt & english-verbs.txt" << endl;
        }
        else
        {
            cout << "THE VERBS ARE MISSING!" << endl;
        }
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


    WORDS VocabTranslator::searchForAWord(string word)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(word == w.GermanWord || word == w.EnglishWord)
            {
                return w;
            }
        }
        WORDS w;
        w.EnglishWord = "-1";
        w.GermanWord = "-1";
        return w;
    }

    VERBS VocabTranslator::searchForAVerb(string verb)
    {
        for(int i = 0; i < this->Verbs.size(); i++) //Search the verbs vector for what we are looking for.
        {
            VERBS v;
            v = Verbs.at(i);
            if(verb == v.EnglishVerb) //If the english verb matches, 
            {
                return v; //Then we have what we are looking for.
            }
            else //If it does not, we need to check all of the german conjugations.
            {
                vector <string> gc = v.GermanConjugations;
                for(int i = 0; i < gc.size(); i++) //If one of the german conjugations matches,
                {
                    if(gc.at(i) == verb)
                    {
                        return v; //Then we have what we are looking for.
                    }
                }
            }
        } //If the loop breaks, then it is not in the verb dictionary.
        VERBS v;
        v.EnglishVerb = "-1";
        vector <string> gc;
        gc.push_back("-1");
        v.GermanConjugations = gc;
        return v; //so return an empty verbs list.
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
        WORDS w = searchForAWord(wordToTranslate);
        if(w.EnglishWord == wordToTranslate) //If the word is an english word
        {
            cout << wordToTranslate << " auf deutsch ist " << w.GermanWord << endl; //Translate it to its german counterpart, and display it.
            return;
        }
        else if(w.GermanWord == wordToTranslate) //If the word is a german word
        {
            cout << wordToTranslate << " in english is " << w.EnglishWord << endl; //Translate it to its english counterpart, and display it.
            return;
        }
        else
        {
            //cout << wordToTranslate << " isn't in the dictionary... let's check the conjugations..." << endl;
        }
        //If we can't find the vocab word, then we need to search the conjugations.
        VERBS v = searchForAVerb(wordToTranslate);
        if(v.EnglishVerb == wordToTranslate || v.GermanConjugations.size() > 1) //Regardless if we find it, we will display the entire conjugations table.
        {
            displayConjugations(v);
            return;
        }
        else
        {
            cout << "This word is not in the dictionary nor is it in the verb dictionary." << endl;
        }

    }

    void VocabTranslator::correction()
    {
        string input;
        cout << "Please enter the word that needs to be corrected: ";
        cin >> input;
    }