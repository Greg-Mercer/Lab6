//
// Created by Greg on 2018-11-01.
//

#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Dictionary.hpp"

Dictionary::Dictionary(string s) {
    ifstream file;
    file.open(s);
    string word;
    map<string, string> list;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string curr, word, def;
        while(iss >> curr) {
            if(word.empty()) {
                word = curr;
            } else if (curr == "-") {
                // ignore
            } else {
                def += curr + " ";
            }
        }
        list.insert(make_pair(word, def));
    }
    this->dictionary = list;
}

void Dictionary::userMenu() {
    cout << "C++ Dictionary" << endl;
    bool finished = false;
    while(!finished) {
        cout << endl;
        cout << "1 - Print dictionary" << endl;
        cout << "2 - Find word definition" << endl;
        cout << "3 - Enter new word and definition" << endl;
        cout << "4 - Exit" << endl;

        string line;
        getline(cin, line);

        char input = line[0];

        switch(input) {
            case '1':
                printAll();
                break;
            case '2':
                findWord();
                break;
            case '3':
                insertWord();
                break;
            case '4':
                finished = true;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    }
}

void Dictionary::printAll() {
    typedef map<string, string>::iterator ssIter;
    cout << endl;

    for (ssIter values = dictionary.begin();
         values != dictionary.end(); ++values) {
        cout << values->first << " - " << values->second << endl;
    }
}

void Dictionary::findWord() {
    cout << "Enter a word." << endl;
    string line, word;
    getline(cin, line);
    istringstream iss(line);
    iss >> word;

    bool e = this->exists(word);

    if(!e) {
        cout << "This word does not exist in the dictionary." << endl;
    } else {
        map<string, string>::iterator def = dictionary.find(word);
        cout << def->second << endl;
    }
}

bool Dictionary::exists(string s) {
    map<string, string>::iterator def = dictionary.find(s);

    if(def == dictionary.end()) {
        return false;
    } else {
        return true;
    }
}

void Dictionary::insertWord() {
    bool exists = true;
    while(exists) {
        cout << "Enter a word." << endl;
        string line, word;
        getline(cin, line);
        istringstream iss(line);
        iss >> word;

        bool e = this->exists(word);

        if(e) {
            cout << "This word already exists in the dictionary. Try again." << endl;
        } else {
            exists = false;
            string def, curr;
            cout << "Please enter a definition for this word." << endl;
            getline(cin, line);
            istringstream iss(line);
            while(iss >> curr) {
                def += curr + " ";
            }
            dictionary.insert(make_pair(word, def));
        }
    }


}