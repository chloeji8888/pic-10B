#include <iostream>
#include<fstream>
#include<string>
#include<unordered_set>
#include "SpellCheck.hpp"
using namespace std;

int main() {
    
    SpellCheck check;
    
    // the dictionary will be read
    check.read_dictionary("dictionary (1).txt");
    
    //get the name of the file that needs to be checked
    string inputName;
    cout << "filename for spellcheck?";
    getline(cin, inputName);
    
    //process the file and print out the result.
    check.process_file(inputName);
    
    return 0;
}
