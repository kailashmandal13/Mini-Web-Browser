/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "ast.hpp"

extern FILE* yyin;
extern int yylex(void);
extern char* yytext;
void yyerror(const char* s);
extern int yylineno;
ASTNode* root = nullptr;
#define YYDEBUG 1

#line 87 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_HTML_START = 3,                 /* HTML_START  */
  YYSYMBOL_HTML_END = 4,                   /* HTML_END  */
  YYSYMBOL_HEAD_START = 5,                 /* HEAD_START  */
  YYSYMBOL_HEAD_END = 6,                   /* HEAD_END  */
  YYSYMBOL_TITLE_START = 7,                /* TITLE_START  */
  YYSYMBOL_TITLE_END = 8,                  /* TITLE_END  */
  YYSYMBOL_BODY_START = 9,                 /* BODY_START  */
  YYSYMBOL_BODY_END = 10,                  /* BODY_END  */
  YYSYMBOL_NAV_START = 11,                 /* NAV_START  */
  YYSYMBOL_NAV_END = 12,                   /* NAV_END  */
  YYSYMBOL_HEADER_START = 13,              /* HEADER_START  */
  YYSYMBOL_HEADER_END = 14,                /* HEADER_END  */
  YYSYMBOL_H_START = 15,                   /* H_START  */
  YYSYMBOL_H_END = 16,                     /* H_END  */
  YYSYMBOL_P_START = 17,                   /* P_START  */
  YYSYMBOL_P_END = 18,                     /* P_END  */
  YYSYMBOL_SECTION_START = 19,             /* SECTION_START  */
  YYSYMBOL_SECTION_END = 20,               /* SECTION_END  */
  YYSYMBOL_ARTICLE_START = 21,             /* ARTICLE_START  */
  YYSYMBOL_ARTICLE_END = 22,               /* ARTICLE_END  */
  YYSYMBOL_ASIDE_START = 23,               /* ASIDE_START  */
  YYSYMBOL_ASIDE_END = 24,                 /* ASIDE_END  */
  YYSYMBOL_FOOTER_START = 25,              /* FOOTER_START  */
  YYSYMBOL_FOOTER_END = 26,                /* FOOTER_END  */
  YYSYMBOL_UL_START = 27,                  /* UL_START  */
  YYSYMBOL_UL_END = 28,                    /* UL_END  */
  YYSYMBOL_OL_START = 29,                  /* OL_START  */
  YYSYMBOL_OL_END = 30,                    /* OL_END  */
  YYSYMBOL_LI_START = 31,                  /* LI_START  */
  YYSYMBOL_LI_END = 32,                    /* LI_END  */
  YYSYMBOL_STRONG_START = 33,              /* STRONG_START  */
  YYSYMBOL_STRONG_END = 34,                /* STRONG_END  */
  YYSYMBOL_EM_START = 35,                  /* EM_START  */
  YYSYMBOL_EM_END = 36,                    /* EM_END  */
  YYSYMBOL_PRE_START = 37,                 /* PRE_START  */
  YYSYMBOL_PRE_END = 38,                   /* PRE_END  */
  YYSYMBOL_BLOCKQUOTE_START = 39,          /* BLOCKQUOTE_START  */
  YYSYMBOL_BLOCKQUOTE_END = 40,            /* BLOCKQUOTE_END  */
  YYSYMBOL_A_START = 41,                   /* A_START  */
  YYSYMBOL_A_END = 42,                     /* A_END  */
  YYSYMBOL_IMG = 43,                       /* IMG  */
  YYSYMBOL_TEXT = 44,                      /* TEXT  */
  YYSYMBOL_DOCTYPE = 45,                   /* DOCTYPE  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_document = 47,                  /* document  */
  YYSYMBOL_html = 48,                      /* html  */
  YYSYMBOL_html_content = 49,              /* html_content  */
  YYSYMBOL_head_content = 50,              /* head_content  */
  YYSYMBOL_title = 51,                     /* title  */
  YYSYMBOL_text_content = 52,              /* text_content  */
  YYSYMBOL_mixed_content = 53,             /* mixed_content  */
  YYSYMBOL_body_content = 54,              /* body_content  */
  YYSYMBOL_body_elements = 55,             /* body_elements  */
  YYSYMBOL_body_element = 56,              /* body_element  */
  YYSYMBOL_nav_element = 57,               /* nav_element  */
  YYSYMBOL_header_element = 58,            /* header_element  */
  YYSYMBOL_header_content = 59,            /* header_content  */
  YYSYMBOL_header_item = 60,               /* header_item  */
  YYSYMBOL_section_element = 61,           /* section_element  */
  YYSYMBOL_section_content = 62,           /* section_content  */
  YYSYMBOL_article_element = 63,           /* article_element  */
  YYSYMBOL_article_content = 64,           /* article_content  */
  YYSYMBOL_aside_element = 65,             /* aside_element  */
  YYSYMBOL_aside_content = 66,             /* aside_content  */
  YYSYMBOL_footer_element = 67,            /* footer_element  */
  YYSYMBOL_footer_content = 68,            /* footer_content  */
  YYSYMBOL_footer_item = 69,               /* footer_item  */
  YYSYMBOL_p_element = 70,                 /* p_element  */
  YYSYMBOL_heading = 71,                   /* heading  */
  YYSYMBOL_list = 72,                      /* list  */
  YYSYMBOL_list_items = 73,                /* list_items  */
  YYSYMBOL_list_item = 74,                 /* list_item  */
  YYSYMBOL_link = 75,                      /* link  */
  YYSYMBOL_img_element = 76,               /* img_element  */
  YYSYMBOL_formatted_element = 77,         /* formatted_element  */
  YYSYMBOL_article_item = 78,              /* article_item  */
  YYSYMBOL_aside_item = 79                 /* aside_item  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    44,    49,    51,    56,    58,    59,
      60,    61,    65,    69,    74,    85,    86,    88,    88,    88,
      89,    89,    89,    89,    91,    92,    94,   100,   101,   103,
     103,   105,   109,   110,   112,   118,   119,   121,   123,   124,
     126,   128,   129,   131,   131,   133,   144,   155,   157,   158,
     160,   171,   176,   178,   187,   196,   205,   216,   216,   216,
     218,   218
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "HTML_START",
  "HTML_END", "HEAD_START", "HEAD_END", "TITLE_START", "TITLE_END",
  "BODY_START", "BODY_END", "NAV_START", "NAV_END", "HEADER_START",
  "HEADER_END", "H_START", "H_END", "P_START", "P_END", "SECTION_START",
  "SECTION_END", "ARTICLE_START", "ARTICLE_END", "ASIDE_START",
  "ASIDE_END", "FOOTER_START", "FOOTER_END", "UL_START", "UL_END",
  "OL_START", "OL_END", "LI_START", "LI_END", "STRONG_START", "STRONG_END",
  "EM_START", "EM_END", "PRE_START", "PRE_END", "BLOCKQUOTE_START",
  "BLOCKQUOTE_END", "A_START", "A_END", "IMG", "TEXT", "DOCTYPE",
  "$accept", "document", "html", "html_content", "head_content", "title",
  "text_content", "mixed_content", "body_content", "body_elements",
  "body_element", "nav_element", "header_element", "header_content",
  "header_item", "section_element", "section_content", "article_element",
  "article_content", "aside_element", "aside_content", "footer_element",
  "footer_content", "footer_item", "p_element", "heading", "list",
  "list_items", "list_item", "link", "img_element", "formatted_element",
  "article_item", "aside_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,     9,    26,    22,   -45,   -45,    23,    28,    25,    10,
      60,   -45,   139,   -45,    61,   -45,   116,    -7,   197,    49,
      -6,    -4,    43,   117,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   197,   197,   197,   197,   197,   -45,   -45,
      53,    64,   -45,   -45,   197,    86,   -45,   -45,   -45,    81,
      38,     2,   -45,   -10,   -45,   -45,   -45,   -45,    -8,   -45,
     -45,   -45,   197,   -12,   -45,   -45,   -45,   147,   157,   167,
     177,   187,   -45,   -45,   -45,   -45,   -45,    69,   -45,   -45,
     -45,   102,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   135,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
       0,     3,     0,     4,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    17,    18,    19,    20,    21,
      23,    22,     6,     0,     0,     0,     0,     0,     7,     8,
       0,     0,    10,     9,     0,     0,    27,    30,    29,     0,
       0,     0,    32,     0,    60,    61,    38,    52,     0,    41,
      43,    44,     0,     0,    48,    14,    16,     0,     0,     0,
       0,     0,    25,    11,    13,    12,    24,     0,    26,    28,
      45,     0,    58,    57,    59,    35,    31,    33,    37,    39,
      40,    42,     0,    47,    49,    53,    54,    55,    56,    51,
      46,    34,    36,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   -20,    45,   -45,   -45,
      68,   -45,   -45,   -45,    39,   -45,   -45,    36,   -45,   -45,
     -45,   -45,   -45,    35,   -17,   -44,   -15,   -45,    32,    -9,
     -45,   -25,    15,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,     7,     8,    10,    39,    40,    13,    23,
      24,    25,    26,    45,    46,    27,    51,    52,    81,    28,
      53,    29,    58,    59,    30,    48,    31,    63,    64,    42,
      61,    43,    85,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      47,    41,     1,    54,    60,    55,    83,    18,    44,    18,
      18,    18,     3,    18,    88,    75,    93,    22,    90,    62,
      73,    22,    86,    50,    75,    84,     5,     6,    47,    73,
       9,    74,    11,    82,    12,    57,    54,    83,    55,    57,
      74,    60,    75,    75,    75,    75,    75,    73,    73,    73,
      73,    73,    75,    44,    14,    18,    84,    73,    74,    74,
      74,    74,    74,    49,    82,    72,    15,    75,    74,    32,
      50,    33,    73,    34,    62,    35,    76,    36,    67,    68,
      69,    70,    71,    74,    79,   100,    33,    87,    34,    77,
      35,    66,    36,    91,    37,    94,   102,    38,     0,    80,
      78,    44,    33,    18,    34,    89,    35,    92,    36,     0,
      37,     0,     0,    38,    33,     0,    34,    44,    35,    18,
      36,     0,    37,     0,   101,    38,     0,    65,    16,     0,
      17,     0,     0,     0,    18,    33,    19,    34,     0,    35,
      20,    36,    21,    22,    22,     0,     0,     0,     0,    33,
      16,    34,    17,    35,     0,    36,    18,    37,    19,     0,
      38,     0,    20,     0,    21,     0,    22,   103,    33,     0,
      34,     0,    35,     0,    36,     0,    37,     0,     0,    38,
      33,    95,    34,     0,    35,     0,    36,     0,    37,     0,
      33,    38,    34,    96,    35,     0,    36,     0,    37,     0,
      33,    38,    34,     0,    35,    97,    36,     0,    37,     0,
      33,    38,    34,     0,    35,     0,    36,    98,    37,     0,
      33,    38,    34,     0,    35,     0,    36,     0,    37,    99,
      33,    38,    34,     0,    35,     0,    36,     0,    37,     0,
       0,    38
};

static const yytype_int8 yycheck[] =
{
      17,    16,    45,    20,    21,    20,    50,    17,    15,    17,
      17,    17,     3,    17,    24,    40,    28,    27,    26,    31,
      40,    27,    20,    21,    49,    50,     0,     5,    45,    49,
       7,    40,     4,    50,     9,    43,    53,    81,    53,    43,
      49,    58,    67,    68,    69,    70,    71,    67,    68,    69,
      70,    71,    77,    15,    44,    17,    81,    77,    67,    68,
      69,    70,    71,    18,    81,    12,     6,    92,    77,     8,
      21,    33,    92,    35,    31,    37,    12,    39,    33,    34,
      35,    36,    37,    92,    45,    16,    33,    51,    35,    44,
      37,    23,    39,    58,    41,    63,    81,    44,    -1,    18,
      14,    15,    33,    17,    35,    53,    37,    62,    39,    -1,
      41,    -1,    -1,    44,    33,    -1,    35,    15,    37,    17,
      39,    -1,    41,    -1,    22,    44,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    33,    19,    35,    -1,    37,
      23,    39,    25,    27,    27,    -1,    -1,    -1,    -1,    33,
      11,    35,    13,    37,    -1,    39,    17,    41,    19,    -1,
      44,    -1,    23,    -1,    25,    -1,    27,    32,    33,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    44,
      33,    34,    35,    -1,    37,    -1,    39,    -1,    41,    -1,
      33,    44,    35,    36,    37,    -1,    39,    -1,    41,    -1,
      33,    44,    35,    -1,    37,    38,    39,    -1,    41,    -1,
      33,    44,    35,    -1,    37,    -1,    39,    40,    41,    -1,
      33,    44,    35,    -1,    37,    -1,    39,    -1,    41,    42,
      33,    44,    35,    -1,    37,    -1,    39,    -1,    41,    -1,
      -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    47,     3,    48,     0,     5,    49,    50,     7,
      51,     4,     9,    54,    44,     6,    11,    13,    17,    19,
      23,    25,    27,    55,    56,    57,    58,    61,    65,    67,
      70,    72,     8,    33,    35,    37,    39,    41,    44,    52,
      53,    72,    75,    77,    15,    59,    60,    70,    71,    53,
      21,    62,    63,    66,    70,    72,    79,    43,    68,    69,
      70,    76,    31,    73,    74,    10,    56,    53,    53,    53,
      53,    53,    12,    52,    75,    77,    12,    53,    14,    60,
      18,    64,    70,    71,    77,    78,    20,    63,    24,    79,
      26,    69,    53,    28,    74,    34,    36,    38,    40,    42,
      16,    22,    78,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    51,    52,    53,    53,
      53,    53,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    62,    62,    63,    64,    64,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    71,    72,    73,    73,
      74,    75,    76,    77,    77,    77,    77,    78,    78,    78,
      79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     2,     1,
       1,     3,     1,     2,     3,     1,     2,     3,     1,     2,
       3,     1,     2,     1,     1,     3,     3,     3,     1,     2,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* document: DOCTYPE html  */
#line 36 "parser.y"
                       { auto* node = new ASTNode(NodeType::ROOT); if ((yyvsp[0].node)) node->add_child((yyvsp[0].node)); root = node; (yyval.node) = node; }
#line 1261 "parser.tab.c"
    break;

  case 3: /* html: HTML_START html_content HTML_END  */
#line 38 "parser.y"
                                       {
    auto* node = new ASTNode(NodeType::HTML);
    if ((yyvsp[-1].node)) { for (auto* child : (yyvsp[-1].node)->children) node->add_child(child); (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node); }
    (yyval.node) = node;
}
#line 1271 "parser.tab.c"
    break;

  case 4: /* html_content: head_content body_content  */
#line 44 "parser.y"
                                        {
    auto* node = new ASTNode(NodeType::CONTAINER);
    if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); if ((yyvsp[0].node)) node->add_child((yyvsp[0].node)); (yyval.node) = node;
}
#line 1280 "parser.tab.c"
    break;

  case 5: /* head_content: HEAD_START title HEAD_END  */
#line 49 "parser.y"
                                        { auto* node = new ASTNode(NodeType::HEAD); if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); (yyval.node) = node; }
#line 1286 "parser.tab.c"
    break;

  case 6: /* title: TITLE_START TEXT TITLE_END  */
#line 51 "parser.y"
                                  {
    auto* node = new ASTNode(NodeType::TITLE); auto* text_node = new ASTNode(NodeType::TEXT);
    text_node->content = std::string((yyvsp[-1].text)); free((yyvsp[-1].text)); node->add_child(text_node); (yyval.node) = node;
}
#line 1295 "parser.tab.c"
    break;

  case 7: /* text_content: TEXT  */
#line 56 "parser.y"
                   { auto* node = new ASTNode(NodeType::TEXT); node->content = std::string((yyvsp[0].text)); free((yyvsp[0].text)); (yyval.node) = node; }
#line 1301 "parser.tab.c"
    break;

  case 8: /* mixed_content: text_content  */
#line 58 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1307 "parser.tab.c"
    break;

  case 9: /* mixed_content: formatted_element  */
#line 59 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1313 "parser.tab.c"
    break;

  case 10: /* mixed_content: link  */
#line 60 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1319 "parser.tab.c"
    break;

  case 11: /* mixed_content: mixed_content text_content  */
#line 61 "parser.y"
                                 {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
        else { auto* node = new ASTNode(NodeType::PARAGRAPH); node->add_child((yyvsp[-1].node)); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
    }
#line 1328 "parser.tab.c"
    break;

  case 12: /* mixed_content: mixed_content formatted_element  */
#line 65 "parser.y"
                                      {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
        else { auto* node = new ASTNode(NodeType::PARAGRAPH); node->add_child((yyvsp[-1].node)); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
    }
#line 1337 "parser.tab.c"
    break;

  case 13: /* mixed_content: mixed_content link  */
#line 69 "parser.y"
                         {
        auto* node = new ASTNode(NodeType::PARAGRAPH);
        if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); if ((yyvsp[0].node)) node->add_child((yyvsp[0].node)); (yyval.node) = node;
    }
#line 1346 "parser.tab.c"
    break;

  case 14: /* body_content: BODY_START body_elements BODY_END  */
#line 74 "parser.y"
                                                {
    auto* node = new ASTNode(NodeType::BODY);
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::BODY) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1361 "parser.tab.c"
    break;

  case 15: /* body_elements: body_element  */
#line 85 "parser.y"
                            { auto* node = new ASTNode(NodeType::BODY); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1367 "parser.tab.c"
    break;

  case 16: /* body_elements: body_elements body_element  */
#line 86 "parser.y"
                                 { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1373 "parser.tab.c"
    break;

  case 17: /* body_element: nav_element  */
#line 88 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1379 "parser.tab.c"
    break;

  case 18: /* body_element: header_element  */
#line 88 "parser.y"
                                                        { (yyval.node) = (yyvsp[0].node); }
#line 1385 "parser.tab.c"
    break;

  case 19: /* body_element: section_element  */
#line 88 "parser.y"
                                                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1391 "parser.tab.c"
    break;

  case 20: /* body_element: aside_element  */
#line 89 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1397 "parser.tab.c"
    break;

  case 21: /* body_element: footer_element  */
#line 89 "parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1403 "parser.tab.c"
    break;

  case 22: /* body_element: list  */
#line 89 "parser.y"
                                                                      { (yyval.node) = (yyvsp[0].node); }
#line 1409 "parser.tab.c"
    break;

  case 23: /* body_element: p_element  */
#line 89 "parser.y"
                                                                                               { (yyval.node) = (yyvsp[0].node); }
#line 1415 "parser.tab.c"
    break;

  case 24: /* nav_element: NAV_START list NAV_END  */
#line 91 "parser.y"
                                    { auto* node = new ASTNode(NodeType::NAV); if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); (yyval.node) = node; }
#line 1421 "parser.tab.c"
    break;

  case 25: /* nav_element: NAV_START mixed_content NAV_END  */
#line 92 "parser.y"
                                      { auto* node = new ASTNode(NodeType::NAV); if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); (yyval.node) = node; }
#line 1427 "parser.tab.c"
    break;

  case 26: /* header_element: HEADER_START header_content HEADER_END  */
#line 94 "parser.y"
                                                       {
    auto* node = new ASTNode(NodeType::HEADER);
    if ((yyvsp[-1].node)) { for (auto* child : (yyvsp[-1].node)->children) node->add_child(child); (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node); }
    (yyval.node) = node;
}
#line 1437 "parser.tab.c"
    break;

  case 27: /* header_content: header_item  */
#line 100 "parser.y"
                            { auto* node = new ASTNode(NodeType::HEADER); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1443 "parser.tab.c"
    break;

  case 28: /* header_content: header_content header_item  */
#line 101 "parser.y"
                                 { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1449 "parser.tab.c"
    break;

  case 29: /* header_item: heading  */
#line 103 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1455 "parser.tab.c"
    break;

  case 30: /* header_item: p_element  */
#line 103 "parser.y"
                                              { (yyval.node) = (yyvsp[0].node); }
#line 1461 "parser.tab.c"
    break;

  case 31: /* section_element: SECTION_START section_content SECTION_END  */
#line 105 "parser.y"
                                                           { 
    auto* node = new ASTNode(NodeType::SECTION); if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); (yyval.node) = node; 
}
#line 1469 "parser.tab.c"
    break;

  case 32: /* section_content: article_element  */
#line 109 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 1475 "parser.tab.c"
    break;

  case 33: /* section_content: section_content article_element  */
#line 110 "parser.y"
                                      { if (!(yyvsp[-1].node)) (yyval.node) = (yyvsp[0].node); else { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); } }
#line 1481 "parser.tab.c"
    break;

  case 34: /* article_element: ARTICLE_START article_content ARTICLE_END  */
#line 112 "parser.y"
                                                           {
    auto* node = new ASTNode(NodeType::ARTICLE);
    if ((yyvsp[-1].node)) { for (auto* child : (yyvsp[-1].node)->children) node->add_child(child); (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node); }
    (yyval.node) = node;
}
#line 1491 "parser.tab.c"
    break;

  case 35: /* article_content: article_item  */
#line 118 "parser.y"
                              { auto* node = new ASTNode(NodeType::ARTICLE); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1497 "parser.tab.c"
    break;

  case 36: /* article_content: article_content article_item  */
#line 119 "parser.y"
                                   { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1503 "parser.tab.c"
    break;

  case 37: /* aside_element: ASIDE_START aside_content ASIDE_END  */
#line 121 "parser.y"
                                                   { (yyval.node) = (yyvsp[-1].node); }
#line 1509 "parser.tab.c"
    break;

  case 38: /* aside_content: aside_item  */
#line 123 "parser.y"
                          { auto* node = new ASTNode(NodeType::ASIDE); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1515 "parser.tab.c"
    break;

  case 39: /* aside_content: aside_content aside_item  */
#line 124 "parser.y"
                               { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1521 "parser.tab.c"
    break;

  case 40: /* footer_element: FOOTER_START footer_content FOOTER_END  */
#line 126 "parser.y"
                                                       { (yyval.node) = (yyvsp[-1].node); }
#line 1527 "parser.tab.c"
    break;

  case 41: /* footer_content: footer_item  */
#line 128 "parser.y"
                            { auto* node = new ASTNode(NodeType::FOOTER); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1533 "parser.tab.c"
    break;

  case 42: /* footer_content: footer_content footer_item  */
#line 129 "parser.y"
                                 { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1539 "parser.tab.c"
    break;

  case 43: /* footer_item: p_element  */
#line 131 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1545 "parser.tab.c"
    break;

  case 44: /* footer_item: img_element  */
#line 131 "parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1551 "parser.tab.c"
    break;

  case 45: /* p_element: P_START mixed_content P_END  */
#line 133 "parser.y"
                                       {
    auto* node = new ASTNode(NodeType::PARAGRAPH);
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1566 "parser.tab.c"
    break;

  case 46: /* heading: H_START mixed_content H_END  */
#line 144 "parser.y"
                                     {
    auto* node = new ASTNode(NodeType::HEADING); node->heading_level = (yyvsp[-2].number);
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1581 "parser.tab.c"
    break;

  case 47: /* list: UL_START list_items UL_END  */
#line 155 "parser.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 1587 "parser.tab.c"
    break;

  case 48: /* list_items: list_item  */
#line 157 "parser.y"
                      { auto* node = new ASTNode(NodeType::LIST); node->add_child((yyvsp[0].node)); (yyval.node) = node; }
#line 1593 "parser.tab.c"
    break;

  case 49: /* list_items: list_items list_item  */
#line 158 "parser.y"
                           { (yyvsp[-1].node)->add_child((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1599 "parser.tab.c"
    break;

  case 50: /* list_item: LI_START mixed_content LI_END  */
#line 160 "parser.y"
                                         {
    auto* node = new ASTNode(NodeType::LIST_ITEM);
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1614 "parser.tab.c"
    break;

  case 51: /* link: A_START mixed_content A_END  */
#line 171 "parser.y"
                                  {
    auto* node = new ASTNode(NodeType::LINK); node->attributes = std::string((yyvsp[-2].text));
    if ((yyvsp[-1].node)) node->add_child((yyvsp[-1].node)); free((yyvsp[-2].text)); (yyval.node) = node;
}
#line 1623 "parser.tab.c"
    break;

  case 52: /* img_element: IMG  */
#line 176 "parser.y"
                 { auto* node = new ASTNode(NodeType::IMAGE); node->attributes = std::string((yyvsp[0].text)); free((yyvsp[0].text)); (yyval.node) = node; }
#line 1629 "parser.tab.c"
    break;

  case 53: /* formatted_element: STRONG_START mixed_content STRONG_END  */
#line 178 "parser.y"
                                                         {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"strong\"";
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1644 "parser.tab.c"
    break;

  case 54: /* formatted_element: EM_START mixed_content EM_END  */
#line 187 "parser.y"
                                  {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"emphasis\"";
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1659 "parser.tab.c"
    break;

  case 55: /* formatted_element: PRE_START mixed_content PRE_END  */
#line 196 "parser.y"
                                    {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"preformatted\"";
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1674 "parser.tab.c"
    break;

  case 56: /* formatted_element: BLOCKQUOTE_START mixed_content BLOCKQUOTE_END  */
#line 205 "parser.y"
                                                  {
    auto* node = new ASTNode(NodeType::FORMATTED_TEXT); node->attributes = "type=\"blockquote\"";
    if ((yyvsp[-1].node)) {
        if ((yyvsp[-1].node)->type == NodeType::PARAGRAPH) {
            for (auto* child : (yyvsp[-1].node)->children) node->add_child(child);
            (yyvsp[-1].node)->children.clear(); delete (yyvsp[-1].node);
        } else node->add_child((yyvsp[-1].node));
    }
    (yyval.node) = node;
}
#line 1689 "parser.tab.c"
    break;

  case 57: /* article_item: heading  */
#line 216 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1695 "parser.tab.c"
    break;

  case 58: /* article_item: p_element  */
#line 216 "parser.y"
                                               { (yyval.node) = (yyvsp[0].node); }
#line 1701 "parser.tab.c"
    break;

  case 59: /* article_item: formatted_element  */
#line 216 "parser.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1707 "parser.tab.c"
    break;

  case 60: /* aside_item: p_element  */
#line 218 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1713 "parser.tab.c"
    break;

  case 61: /* aside_item: list  */
#line 218 "parser.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 1719 "parser.tab.c"
    break;


#line 1723 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 220 "parser.y"


void yyerror(const char* s) {
    std::cerr << "Parser error near line " << yylineno << ": " << s << " at token '" << yytext << "'\n";
}
