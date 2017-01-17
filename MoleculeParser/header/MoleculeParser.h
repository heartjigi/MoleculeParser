#include <map>
#include <vector>
#include <string>

class MoleculeParser {
private:
    //member variable
    string mMoleculeName;
public:
    //initializer
    MoleculeParser();
    MoleculeParser(string);
    
    //method
    map<string, int> parse();
    void getAST();
};
