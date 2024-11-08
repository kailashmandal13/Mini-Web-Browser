#include "AST.h"
#include <iostream>
#include <cstdlib>

// extern "C" {
//     int yylex();      // Lexical analyzer function
//     int yyparse();    // Parser function
//     void yyerror(const char *s); // Error handling function
// }

// extern int yylex();

ASTNode* root; // Define the global root node for the AST

// int main() {
//     yyparse(); // Start parsing
//     printAST(root, 0); // Print the AST
//     return 0;
// }
