#include <iostream>
#include "AST.h"
#include "parser.tab.h"  // Bison-generated header
extern int yyparse();     // Declaration of Bison's parsing function
extern std::shared_ptr<HTMLNode> root; // Root node from parser

int main() {
    // Start parsing the input HTML
    if (yyparse() == 0) {  // yyparse() returns 0 on success
        std::cout << "Parsed HTML DOM Tree:" << std::endl;
        root->print();  // Print the parsed DOM structure
    } else {
        std::cerr << "Failed to parse HTML." << std::endl;
    }
    return 0;
}
