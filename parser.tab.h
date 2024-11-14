/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    HTML_START = 258,              /* HTML_START  */
    HTML_END = 259,                /* HTML_END  */
    HEAD_START = 260,              /* HEAD_START  */
    HEAD_END = 261,                /* HEAD_END  */
    TITLE_START = 262,             /* TITLE_START  */
    TITLE_END = 263,               /* TITLE_END  */
    BODY_START = 264,              /* BODY_START  */
    BODY_END = 265,                /* BODY_END  */
    NAV_START = 266,               /* NAV_START  */
    NAV_END = 267,                 /* NAV_END  */
    HEADER_START = 268,            /* HEADER_START  */
    HEADER_END = 269,              /* HEADER_END  */
    H_START = 270,                 /* H_START  */
    H_END = 271,                   /* H_END  */
    P_START = 272,                 /* P_START  */
    P_END = 273,                   /* P_END  */
    SECTION_START = 274,           /* SECTION_START  */
    SECTION_END = 275,             /* SECTION_END  */
    ARTICLE_START = 276,           /* ARTICLE_START  */
    ARTICLE_END = 277,             /* ARTICLE_END  */
    ASIDE_START = 278,             /* ASIDE_START  */
    ASIDE_END = 279,               /* ASIDE_END  */
    FOOTER_START = 280,            /* FOOTER_START  */
    FOOTER_END = 281,              /* FOOTER_END  */
    UL_START = 282,                /* UL_START  */
    UL_END = 283,                  /* UL_END  */
    OL_START = 284,                /* OL_START  */
    OL_END = 285,                  /* OL_END  */
    LI_START = 286,                /* LI_START  */
    LI_END = 287,                  /* LI_END  */
    STRONG_START = 288,            /* STRONG_START  */
    STRONG_END = 289,              /* STRONG_END  */
    EM_START = 290,                /* EM_START  */
    EM_END = 291,                  /* EM_END  */
    PRE_START = 292,               /* PRE_START  */
    PRE_END = 293,                 /* PRE_END  */
    BLOCKQUOTE_START = 294,        /* BLOCKQUOTE_START  */
    BLOCKQUOTE_END = 295,          /* BLOCKQUOTE_END  */
    A_START = 296,                 /* A_START  */
    A_END = 297,                   /* A_END  */
    IMG = 298,                     /* IMG  */
    TEXT = 299,                    /* TEXT  */
    DOCTYPE = 300                  /* DOCTYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"
 char* text; int number; ASTNode* node; 

#line 112 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
