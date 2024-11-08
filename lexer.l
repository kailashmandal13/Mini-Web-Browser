%{
#include "AST.h"
#include "parser.tab.h"
#include <string.h>
#include <cstdlib>
#include <cstdio>

char* strdup(const char* str) {
    size_t len = strlen(str) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        memcpy(copy, str, len);
    }
    return copy;
}
%}

DOCTYPE           "<!DOCTYPE"[^>]*">"
COMMENT           "<!--".*?"-->"
OPEN_TAG          "<"[a-zA-Z][^>]*">"
CLOSE_TAG         "</"[a-zA-Z][^>]*">"
TEXT              [^<]+

%%

{DOCTYPE}          { /* Ignore DOCTYPE */ }
[ \t\n]+           { /* Ignore whitespace */ }
{COMMENT}          { /* Ignore comments */ }
{OPEN_TAG}         { yylval.str = strdup(yytext);   return OPEN_TAG;  }
{CLOSE_TAG}        { yylval.str = strdup(yytext);   return CLOSE_TAG; }
{TEXT}             { yylval.str = strdup(yytext);   return TEXT; }

%%

int yywrap() {
    return 1;
}
