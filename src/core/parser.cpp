#include "parser.hpp"
#include <cstdio>
#include <iostream>

extern FILE* yyin;
extern int yyparse(void);
extern ASTNode* root;

ASTNode* parse_html_file(const char* filename) {
    yyin = fopen(filename, "r");
    if (!yyin) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return nullptr;
    }
    
    root = nullptr;
    if (yyparse() == 0) {
        fclose(yyin);
        return root;
    }
    
    fclose(yyin);
    return nullptr;
} 