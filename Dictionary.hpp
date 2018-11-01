//
// Created by Greg on 2018-11-01.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP

#include <map>
#include <iostream>

using namespace std;

/*
 * A dictionary. Stores words and their definitions in format "word - definition \n".
 * Has functions for reading from and writing to the dictionary, using a text file resource.
 */
class Dictionary {
private:
    /* A dictionary. Stores words and their definitions. */
    map<string, string> dictionary;
    /* The filename this dictionary uses as a resource. */
    string resource;

public:
    /*
     * Constructs a dictionary using an existing text file.
     * @param s the name of the text file
     */
    Dictionary(string s);
    /*
     * Destroys a dictionary.
     */
    ~Dictionary() = default;
    /*
     * Displays a menu for the user. Reads user input to determine what actions to perform.
     */
    void userMenu();
    /*
     * Prints the dictionary's contents to cout in an easily readable format.
     */
    void printAll();
    /*
     * Prompts the user to search for a word in the dictionary. Prints results of search to cout.
     */
    void findWord();
    /*
     * Prompts the user to enter a word into the dictionary. If the word does not already exist,
     * the user enters a definition and their input is saved to the dictionary and its text file
     * resource.
     */
    void insertWord();
    /*
     * Checks if a given string is a word in the dictionary.
     * @param s the word to check
     * @return true if the word exists in the dictionary, else false
     */
    bool exists(string s);
};


#endif //LAB6_DICTIONARY_HPP
