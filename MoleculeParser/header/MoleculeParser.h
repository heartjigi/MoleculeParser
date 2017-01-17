#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class MoleculeParser {
private:
    //member variable
    string mName;
public:
    //initializer
    MoleculeParser();
    MoleculeParser(string);
    
    //method
    map<string, int> parse();
};
