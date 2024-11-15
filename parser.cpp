#include "parser.hpp"
#include <iostream>

extern FILE* yyin;
extern int yyparse(void);
extern ASTNode* root;

ASTNode* parse_html_file(const char* filename) {
    std::cout << "Attempting to parse file: " << filename << std::endl;
    
    if (!(yyin = fopen(filename, "r"))) {
        perror(filename);
        return nullptr;
    }
    
    std::cout << "File opened successfully\n";
    
    int result = yyparse();
    std::cout << "Parse result: " << result << " (0 means success)\n";
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    if (root) {
        std::cout << "AST created successfully\n";
        root->print_ast();
    } else {
        std::cout << "Failed to create AST\n";
    }
    
    return root;
} 