//
// Created by Greg on 2018-11-01.
//

#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include "Dictionary.hpp"

Dictionary::Dictionary(string s) {
    ifstream file;
    file.open("dictionary.txt");
    string word;
    map<string, string> list;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string curr, word, def;
        while(iss >> curr) {
            if(word.empty()) {
                word = curr;
            } else {
                file.ignore(512, '-');
                def = curr;
            }
        }
        list.insert(word, def);
    }
    this->dictionary = list;
}