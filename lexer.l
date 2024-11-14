%{
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

#define YY_NO_UNPUT
#define YY_NO_INPUT

// Debug function
void print_token(const char* token_name) {
    printf("TOKEN: %s -> '%s'\n", token_name, yytext);
}
%}

%option yylineno
%option debug

%%

"<!DOCTYPE"[^>]*">"    { print_token("DOCTYPE"); /* Ignore DOCTYPE */ }
"<html>"               { print_token("HTML_START"); return HTML_START; }
"</html>"              { print_token("HTML_END"); return HTML_END; }
"<head>"               { print_token("HEAD_START"); return HEAD_START; }
"</head>"              { print_token("HEAD_END"); return HEAD_END; }
"<title>"              { print_token("TITLE_START"); return TITLE_START; }
"</title>"             { print_token("TITLE_END"); return TITLE_END; }
"<body>"               { print_token("BODY_START"); return BODY_START; }
"</body>"              { print_token("BODY_END"); return BODY_END; }
"<nav>"                { print_token("NAV_START"); return NAV_START; }
"</nav>"               { print_token("NAV_END"); return NAV_END; }
"<header>"             { print_token("HEADER_START"); return HEADER_START; }
"</header>"            { print_token("HEADER_END"); return HEADER_END; }
"<h1>"                 { print_token("H1_START"); yylval.ival = 1; return H_START; }
"</h1>"                { print_token("H1_END"); yylval.ival = 1; return H_END; }
"<h2>"                 { print_token("H2_START"); yylval.ival = 2; return H_START; }
"</h2>"                { print_token("H2_END"); yylval.ival = 2; return H_END; }
"<h3>"                 { print_token("H3_START"); yylval.ival = 3; return H_START; }
"</h3>"                { print_token("H3_END"); yylval.ival = 3; return H_END; }
"<h4>"                 { print_token("H4_START"); yylval.ival = 4; return H_START; }
"</h4>"                { print_token("H4_END"); yylval.ival = 4; return H_END; }
"<h5>"                 { print_token("H5_START"); yylval.ival = 5; return H_START; }
"</h5>"                { print_token("H5_END"); yylval.ival = 5; return H_END; }
"<p>"                  { print_token("P_START"); return P_START; }
"</p>"                 { print_token("P_END"); return P_END; }
"<section>"            { print_token("SECTION_START"); return SECTION_START; }
"</section>"           { print_token("SECTION_END"); return SECTION_END; }
"<article>"            { print_token("ARTICLE_START"); return ARTICLE_START; }
"</article>"           { print_token("ARTICLE_END"); return ARTICLE_END; }
"<aside>"              { print_token("ASIDE_START"); return ASIDE_START; }
"</aside>"             { print_token("ASIDE_END"); return ASIDE_END; }
"<footer>"             { print_token("FOOTER_START"); return FOOTER_START; }
"</footer>"            { print_token("FOOTER_END"); return FOOTER_END; }
"<ul>"                 { print_token("UL_START"); return UL_START; }
"</ul>"                { print_token("UL_END"); return UL_END; }

"<ol>"                 { print_token("OL_START"); return OL_START; }
"</ol>"                { print_token("OL_END"); return OL_END; }
"<li>"                 { print_token("LI_START"); return LI_START; }
"</li>"                { print_token("LI_END"); return LI_END; }
"<strong>"             { print_token("STRONG_START"); return STRONG_START; }
"</strong>"            { print_token("STRONG_END"); return STRONG_END; }
"<em>"                 { print_token("EM_START"); return EM_START; }
"</em>"                { print_token("EM_END"); return EM_END; }
"<pre>"                { print_token("PRE_START"); return PRE_START; }
"</pre>"               { print_token("PRE_END"); return PRE_END; }
"<blockquote>"         { print_token("BLOCKQUOTE_START"); return BLOCKQUOTE_START; }
"</blockquote>"        { print_token("BLOCKQUOTE_END"); return BLOCKQUOTE_END; }

"<a"[ ][^>]*">"        { print_token("A_START"); yylval.sval = strdup(yytext); return A_START; }
"</a>"                 { print_token("A_END"); return A_END; }
"<img"[ ][^>]*">"      { print_token("IMG"); yylval.sval = strdup(yytext); return IMG; }

[ \t\n\r]+            ; /* Skip whitespace */

[^<> \t\n\r][^<>]*    { 
                        /* Match any text between tags, including spaces and special chars */
                        char* cleaned = strdup(yytext);
                        /* Trim trailing whitespace */
                        int len = strlen(cleaned);
                        while (len > 0 && isspace(cleaned[len-1])) {
                            cleaned[--len] = '\0';
                        }
                        if (len > 0) {
                            print_token("TEXT");
                            yylval.sval = cleaned;
                            return TEXT;
                        }
                        free(cleaned);
                      }

.                     { print_token("UNMATCHED"); /* Ignore unmatched characters */ }

%%

int yywrap(void) {
    return 1;
}