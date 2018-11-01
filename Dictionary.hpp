//
// Created by Greg on 2018-11-01.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP

#include <map>
#include <iostream>

using namespace std;

class Dictionary {
private:
    /* A dictionary. Stores words and their definitions. */
    map<string, string> dictionary;

public:
    /*
     * Constructs a dictionary using an existing text file.
     * @param s the name of the text file
     */
    Dictionary(string s);
    /*
     * Puts the dictionary into an output stream in an easily readable format.
     * @param os the stream to put the matrix into
     * @param d the dictionary to put into the stream
     * @return the output stream with the dictionary
     */
    friend ostream& operator<<(ostream& os, const Dictionary& d);
    /*
     * Destroys a dictionary.
     */
    ~Dictionary() = default;
    void userMenu();
    void printAll();
    void findWord();
    void insertWord();
    bool exists(string s);
};


#endif //LAB6_DICTIONARY_HPP
