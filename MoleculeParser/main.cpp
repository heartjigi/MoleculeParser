/**
 * Requirement
 * - use git
 * - write tests
 * - language-agnostic


 1. Molecule Parser
    new MoleculeParser("H2O").parse() 			// { H: 2, O: 1 }
    new MoleculeParser("Mg(OH)2").parse() 		// { Mg: 1, O: 2, H: 2 }
    new MoleculeParser("K4[ON(SO3)2]2").parse() // { K: 4, O: 14, N: 2, S: 4 }
    // Maximum depth levle: 2
*/
#include <iostream>
#include "./header/MoleculeParser.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // test code
    MoleculeParser* MP1 = new MoleculeParser("H2O"); 			// { H: 2, O: 1 }
    MoleculeParser* MP2 = new MoleculeParser("Mg(OH)2"); 		// { Mg: 1, O: 2, H: 2 }
    MoleculeParser* MP3 = new MoleculeParser("K4[ON(SO3)2]2");  // { K: 4, O: 14, N: 2, S: 4 }
    
    MP1->parse();
    MP2->parse();
    MP3->parse();
    
    return 0;
}










