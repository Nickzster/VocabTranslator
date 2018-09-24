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
        cout << "Closing the file by outputting the files..." << endl;
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w = Words.at(i);
            EnglishOut << w.EnglishWord;
            EnglishOut << endl;
            GermanOut << w.GermanWord;
            GermanOut << endl;
        }
        cout << "Done." << endl;
        GermanOut.close();
        EnglishOut.close();
    }

    void VocabTranslator::read()
    {
        ifstream germanFile("german.txt"); //german file to read
        ifstream englishFile("english.txt"); //english file to read
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
    }
    
    void VocabTranslator::addWord(string englishWordToAdd, string germanWordToAdd)
    {
        WORDS w;
        w.GermanWord = germanWordToAdd;
        w.EnglishWord = englishWordToAdd;
        this->Words.push_back(w);
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

    //void addWord(string, list);
    string VocabTranslator::translateToEnglish(string germanWordToTranslate)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(germanWordToTranslate == w.GermanWord)
            {
                return w.EnglishWord;
            }
        }
        return "That word is not in this dictionary!";
    }
    string VocabTranslator::translateToGerman(string englishWordToTranslate)
    {
        for(int i = 0; i < this->Words.size(); i++)
        {
            WORDS w;
            w = Words.at(i);
            if(englishWordToTranslate == w.EnglishWord)
            {
                return w.GermanWord;
            }
        }
        return "That word is not in this dictionary!";
    }