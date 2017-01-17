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

 2. Print AST
    new MoleculeParser("H2O").getAST()		// { [{atom: 'H', num: 2}, {atom: 'O', num: 1}] }
    new MoleculeParser("Mg(OH)2").getAST()  // { [{atom: 'Mg', num: 1}, {atom: [{atom: 'O', num: 1}, {atom: 'H', num: 1}], num: 2}] }
*/
#pragma once
#include <iostream>
#include "../header/MoleculeParser.h"

int main(int argc, const char * argv[]) {

    return 0;
}
