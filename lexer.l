%{
#include <string.h>
#include <stdlib.h>  // for atoi
#include "ast.hpp"
#include "parser.tab.h"
%}

%option yylineno
%option nounput

%%

[ \t\n\r]+         ; /* Skip all whitespace */

"<!DOCTYPE html>"   { return DOCTYPE; }
"<html>"           { return HTML_START; }
"</html>"          { return HTML_END; }
"<head>"           { return HEAD_START; }
"</head>"          { return HEAD_END; }
"<title>"          { return TITLE_START; }
"</title>"         { return TITLE_END; }
"<h"[1-6]">"       { 
    yylval.number = atoi(yytext + 2);
    return H_START; 
}
"</h"[1-6]">"      { return H_END; }
"<body>"           { return BODY_START; }
"</body>"          { return BODY_END; }
"<nav>"            { return NAV_START; }
"</nav>"           { return NAV_END; }
"<header>"         { return HEADER_START; }
"</header>"        { return HEADER_END; }
"<section>"        { return SECTION_START; }
"</section>"       { return SECTION_END; }
"<article>"        { return ARTICLE_START; }
"</article>"       { return ARTICLE_END; }
"<aside>"          { return ASIDE_START; }
"</aside>"         { return ASIDE_END; }
"<footer>"         { return FOOTER_START; }
"</footer>"        { return FOOTER_END; }
"<p>"              { return P_START; }
"</p>"             { return P_END; }
"<ul>"             { return UL_START; }
"</ul>"            { return UL_END; }
"<li>"             { return LI_START; }
"</li>"            { return LI_END; }
"<strong>"         { return STRONG_START; }
"</strong>"        { return STRONG_END; }
"<em>"             { return EM_START; }
"</em>"            { return EM_END; }
"<pre>"            { return PRE_START; }
"</pre>"           { return PRE_END; }
"<blockquote>"     { return BLOCKQUOTE_START; }
"</blockquote>"    { return BLOCKQUOTE_END; }
"<a "[^>]*">"      { yylval.text = strdup(yytext); return A_START; }
"</a>"             { return A_END; }
"<img "[^>]*">"    { yylval.text = strdup(yytext); return IMG; }
"<ol>"             { return OL_START; }
"</ol>"            { return OL_END; }
"<li>"             { return LI_START; }
"</li>"            { return LI_END; }
"<code>"           { return CODE_START; }
"</code>"          { return CODE_END; }
"<small>"          { return SMALL_START; }
"</small>"         { return SMALL_END; }
"<u>"              { return U_START; }
"</u>"             { return U_END; }

[^<>]+             { yylval.text = strdup(yytext); return TEXT; }

.                  ; /* Ignore any other character */

%%

int yywrap() {
    return 1;
}