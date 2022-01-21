
#ifndef SpellCheck_hpp
#define SpellCheck_hpp

#include <stdio.h>
#include<fstream>
#include<unordered_set>

/**
 @class SpellCheck stores a set of uordered dictionary words , it can reads all the words
 in the dictionary and sore them in the set. it can also check if a word is valid in the input file.
 it will process the input file for the user.
 */
class SpellCheck{
    
private:
    
    std::unordered_set<std::string> dicSet;//dictonary member variable that store dictionary words
    std::string currentWord;//current 
    std::fstream dictionary;//dictionary file
    std::string dicWord;//words in the dictionary
    std::string fileWord;//words in the input file
    std::string realOutPut;//contents that will display in the end
    
    
public:
    
    /**
     This is a defualt constructer
     */
    SpellCheck();
    
    /**
     Function that reads all the words from that inputfile into its dictionary of words.
     @param dictionaryName input file which should be the name of the dictionary file
     */
    void read_dictionary(const std::string& dictionaryName);
    
    /**
     function that determine whether the word is correct
     @param currentWord is the word that needs to be checked in the input file
     @return true if the current word is valid
     */
    bool is_valid (std::string& currentWord)const;
    
    /**
     function that reads through a text file that needs to be spellchecked and prints the checked file to the console window
     @param inputFile the file that needs to be spellchecked
     */
    void  process_file(std::string& inputFile);
    
};

/**
 function that determine whether the letter is a white space
 @param letter is the letter that needs to be check
 @return true if the letter is a white sapce
 */
bool is_white_space(const char letter);

/**
 function that determine whether the final character is a punctuation mark
 @param curWord is the word that needs to be checked in the input file
 @return true if the current word a final punctuation
 */
bool final_punctuation (const std::string curWord);

/**
 function that mutates a string input making its first character lowercase and removing its final punctation mark if ther is one
 @param upper is the word that needs to be checked in the input file
 */
void depunctuate(std::string& upper);



#endif
