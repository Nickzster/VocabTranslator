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
        for(int i = 0; i < this->englishWords.size(); i++)
        {
            EnglishOut << this->englishWords.at(i);
            EnglishOut << endl;
            GermanOut << this->germanWords.at(i);
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
        if(!germanFile.is_open()) //if the german file does not exist
        {
            cout << "German.txt: DOES NOT EXIST!" << endl;
        }
        else //if the german file exists
        {
            //then read it
            cout << "Reading German.txt..." << endl;
            char input[100];
            while(germanFile>>input)
            {
                string word = input;
                this->germanWords.push_back(word); //Fill the german array.
                germanCount++;
            }
            cout << "Done reading German.txt" << endl;
        }
        germanFile.close();
        //Read the english file next.
        if(!englishFile.is_open()) //if the german file does not exist
        {
            cout << "English.txt: DOES NOT EXIST!" << endl;
        }
        else //if the german file exists
        {
            //then read it
            cout << "Reading English.txt..." << endl;
            char input[100];
            while(englishFile>>input)
            {
                string word = input;
                this->englishWords.push_back(word); //Fill the german array.
                englishCount++;
            }
            cout << "Done reading English.txt" << endl;
        }
        englishFile.close();
    }
    
    void VocabTranslator::addWord(string englishWordToAdd, string germanWordToAdd)
    {
        this->englishWords.push_back(englishWordToAdd);
        this->germanWords.push_back(germanWordToAdd);
    }

    void VocabTranslator::printAll()
    {
        for(int i = 0; i < germanWords.size(); i++)
        {
            cout << germanWords.at(i);
            cout << " - " << endl;
            cout << englishWords.at(i) << endl;
        }
    }

    //void addWord(string, list);
    string VocabTranslator::translateToEnglish(string germanWordToTranslate)
    {
        for(int i = 0; i < this->germanWords.size(); i++)
        {
            if(germanWordToTranslate == this->germanWords.at(i))
            {
                return this->englishWords.at(i);
            }
        }
        return "INVALID";
    }
    string VocabTranslator::translateToGerman(string englishWordToTranslate)
    {
        for(int i = 0; i < this->englishWords.size(); i++)
        {
            if(englishWordToTranslate == this->englishWords.at(i))
            {
                return this->germanWords.at(i);
            }
        }
        return "INVALID";
    }