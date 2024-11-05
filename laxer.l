%{
#include "parser.tab.h"
#include <string>
%}

TAG_OPEN         "<"
TAG_CLOSE        ">"
TAG_END          "</"
TAG_SELF_CLOSE   "/>"
ATTR_EQUALS      "="
ATTR_QUOTE       "\""
TEXT             [^<>]+

%%

{TAG_OPEN}html{TAG_CLOSE}              { return HTML_TAG; }
{TAG_END}html{TAG_CLOSE}               { return HTML_TAG_CLOSE; }

{TAG_OPEN}head{TAG_CLOSE}              { return HEAD_TAG; }
{TAG_END}head{TAG_CLOSE}               { return HEAD_TAG_CLOSE; }

{TAG_OPEN}title{TAG_CLOSE}             { return TITLE_TAG; }
{TAG_END}title{TAG_CLOSE}              { return TITLE_TAG_CLOSE; }

{TAG_OPEN}body{TAG_CLOSE}              { return BODY_TAG; }
{TAG_END}body{TAG_CLOSE}               { return BODY_TAG_CLOSE; }

{TAG_OPEN}nav{TAG_CLOSE}               { return NAV_TAG; }
{TAG_END}nav{TAG_CLOSE}                { return NAV_TAG_CLOSE; }

{TAG_OPEN}ul{TAG_CLOSE}                { return UL_TAG; }
{TAG_END}ul{TAG_CLOSE}                 { return UL_TAG_CLOSE; }

{TAG_OPEN}li{TAG_CLOSE}                { return LI_TAG; }
{TAG_END}li{TAG_CLOSE}                 { return LI_TAG_CLOSE; }

{TAG_OPEN}a{TAG_CLOSE}                 { return A_TAG; }
{TAG_END}a{TAG_CLOSE}                  { return A_TAG_CLOSE; }

{TAG_OPEN}header{TAG_CLOSE}            { return HEADER_TAG; }
{TAG_END}header{TAG_CLOSE}             { return HEADER_TAG_CLOSE; }

{TAG_OPEN}h1{TAG_CLOSE}                { return H1_TAG; }
{TAG_END}h1{TAG_CLOSE}                 { return H1_TAG_CLOSE; }

{TAG_OPEN}h2{TAG_CLOSE}                { return H2_TAG; }
{TAG_END}h2{TAG_CLOSE}                 { return H2_TAG_CLOSE; }

{TAG_OPEN}h3{TAG_CLOSE}                { return H3_TAG; }
{TAG_END}h3{TAG_CLOSE}                 { return H3_TAG_CLOSE; }

{TAG_OPEN}h4{TAG_CLOSE}                { return H4_TAG; }
{TAG_END}h4{TAG_CLOSE}                 { return H4_TAG_CLOSE; }

{TAG_OPEN}h5{TAG_CLOSE}                { return H5_TAG; }
{TAG_END}h5{TAG_CLOSE}                 { return H5_TAG_CLOSE; }

{TAG_OPEN}section{TAG_CLOSE}           { return SECTION_TAG; }
{TAG_END}section{TAG_CLOSE}            { return SECTION_TAG_CLOSE; }

{TAG_OPEN}article{TAG_CLOSE}           { return ARTICLE_TAG; }
{TAG_END}article{TAG_CLOSE}            { return ARTICLE_TAG_CLOSE; }

{TAG_OPEN}p{TAG_CLOSE}                 { return P_TAG; }
{TAG_END}p{TAG_CLOSE}                  { return P_TAG_CLOSE; }

{TAG_OPEN}strong{TAG_CLOSE}            { return STRONG_TAG; }
{TAG_END}strong{TAG_CLOSE}             { return STRONG_TAG_CLOSE; }

{TAG_OPEN}em{TAG_CLOSE}                { return EM_TAG; }
{TAG_END}em{TAG_CLOSE}                 { return EM_TAG_CLOSE; }

{TAG_OPEN}pre{TAG_CLOSE}               { return PRE_TAG; }
{TAG_END}pre{TAG_CLOSE}                { return PRE_TAG_CLOSE; }

{TAG_OPEN}blockquote{TAG_CLOSE}        { return BLOCKQUOTE_TAG; }
{TAG_END}blockquote{TAG_CLOSE}         { return BLOCKQUOTE_TAG_CLOSE; }

{TAG_OPEN}aside{TAG_CLOSE}             { return ASIDE_TAG; }
{TAG_END}aside{TAG_CLOSE}              { return ASIDE_TAG_CLOSE; }

{TAG_OPEN}footer{TAG_CLOSE}            { return FOOTER_TAG; }
{TAG_END}footer{TAG_CLOSE}             { return FOOTER_TAG_CLOSE; }

{TAG_OPEN}img{TAG_CLOSE}               { return IMG_TAG; }

{TEXT}                                  { yylval.str = strdup(yytext); return TEXT_CONTENT; }



.                                       { return *yytext; }

%%

int yywrap() {
    return 1;
}