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

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE* yyin;
extern int yylex(void);
void yyerror(const char* s);

ASTNode* root = NULL;

#define YYDEBUG 1

#line 85 "parser.tab.c"

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
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_document = 46,                  /* document  */
  YYSYMBOL_html_content = 47,              /* html_content  */
  YYSYMBOL_head_content = 48,              /* head_content  */
  YYSYMBOL_text_content = 49,              /* text_content  */
  YYSYMBOL_mixed_content = 50,             /* mixed_content  */
  YYSYMBOL_body_content = 51,              /* body_content  */
  YYSYMBOL_body_elements = 52,             /* body_elements  */
  YYSYMBOL_body_element = 53,              /* body_element  */
  YYSYMBOL_nav_element = 54,               /* nav_element  */
  YYSYMBOL_header_element = 55,            /* header_element  */
  YYSYMBOL_section_element = 56,           /* section_element  */
  YYSYMBOL_article_element = 57,           /* article_element  */
  YYSYMBOL_aside_element = 58,             /* aside_element  */
  YYSYMBOL_footer_element = 59,            /* footer_element  */
  YYSYMBOL_p_element = 60,                 /* p_element  */
  YYSYMBOL_heading = 61,                   /* heading  */
  YYSYMBOL_list = 62,                      /* list  */
  YYSYMBOL_list_items = 63,                /* list_items  */
  YYSYMBOL_list_item = 64,                 /* list_item  */
  YYSYMBOL_link = 65,                      /* link  */
  YYSYMBOL_img_element = 66,               /* img_element  */
  YYSYMBOL_formatted_text = 67             /* formatted_text  */
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
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    48,    57,    64,    68,    76,    80,    89,
      93,   102,   106,   118,   126,   130,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   158,
     166,   174,   182,   190,   198,   206,   214,   223,   228,   236,
     240,   252,   260,   269,   277,   282,   287,   292
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
  "BLOCKQUOTE_END", "A_START", "A_END", "IMG", "TEXT", "$accept",
  "document", "html_content", "head_content", "text_content",
  "mixed_content", "body_content", "body_elements", "body_element",
  "nav_element", "header_element", "section_element", "article_element",
  "aside_element", "footer_element", "p_element", "heading", "list",
  "list_items", "list_item", "link", "img_element", "formatted_text", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,     7,    13,    15,    16,   -53,   137,    18,   -53,   137,
     137,   137,   137,   137,   -53,   -53,    28,   -53,   -53,    25,
     358,   368,   378,   388,   398,   -53,   -53,   -53,   -53,   320,
     -53,   -53,   -53,   -53,   -53,   320,   320,   137,   137,   320,
     320,   320,   320,     4,     4,   -53,   -53,    32,   320,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   116,   150,   332,   333,   184,   218,   252,   286,
     137,   -20,   -53,   -29,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   346,   -53,   -53,   -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,     0,     0,     2,     0,
       0,     0,     0,     0,     6,     7,     0,    11,     9,     0,
       0,     0,     0,     0,     0,     4,     8,    12,    10,     0,
      44,    45,    46,    47,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    28,     0,    13,    14,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     3,    15,    29,    30,    36,    35,
      31,    32,    33,    34,     0,    37,    40,    38,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,    -6,    37,   -53,    44,    48,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -19,   -52,
      17,   -53,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,     7,    46,    16,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    71,    72,
      59,    60,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    87,    70,    15,    15,    15,    15,    15,    85,     1,
      26,    70,     3,     5,    26,    26,    26,    26,    26,    86,
       8,    86,     6,    17,    19,    73,    17,    17,    17,    17,
      17,    15,    15,    27,    29,    70,    25,    27,    27,    27,
      27,    27,    74,     0,     0,     0,    20,    21,    22,    23,
      24,     0,     0,     0,    17,    17,     0,     0,    26,    26,
       0,     9,     0,    10,    15,    11,     0,    12,     0,    13,
       0,     0,    14,     0,    64,    65,     0,     0,    26,    62,
      63,    27,    27,    66,    67,    68,    69,    17,    18,     0,
       0,    18,    18,    18,    18,    18,    75,     0,    28,     0,
       0,    27,    28,    28,    28,    28,    28,    84,     0,     0,
      75,    75,     0,     0,    75,    75,    75,    75,     0,    18,
      18,     0,     0,     0,     0,     0,     0,    35,    76,    36,
       0,    37,     0,    38,     0,    39,     0,    40,     0,    41,
       0,    42,     0,    43,     0,    44,    28,    28,     0,     9,
       0,    10,    18,    11,     0,    12,     0,    13,     0,    45,
      14,    35,     0,    36,    77,    37,    28,    38,     0,    39,
       9,    40,    10,    41,    11,    42,    12,    43,    13,    44,
       0,    14,     0,     9,     0,    10,     0,    11,     0,    12,
       0,    13,     0,    45,    14,    35,     0,    36,     0,    37,
       0,    38,     0,    39,    80,    40,     0,    41,     0,    42,
       0,    43,     0,    44,     0,     0,     0,     9,     0,    10,
       0,    11,     0,    12,     0,    13,     0,    45,    14,    35,
       0,    36,     0,    37,     0,    38,     0,    39,     0,    40,
      81,    41,     0,    42,     0,    43,     0,    44,     0,     0,
       0,     9,     0,    10,     0,    11,     0,    12,     0,    13,
       0,    45,    14,    35,     0,    36,     0,    37,     0,    38,
       0,    39,     0,    40,     0,    41,    82,    42,     0,    43,
       0,    44,     0,     0,     0,     9,     0,    10,     0,    11,
       0,    12,     0,    13,     0,    45,    14,    35,     0,    36,
       0,    37,     0,    38,     0,    39,     0,    40,     0,    41,
       0,    42,    83,    43,     0,    44,     0,     0,     0,     9,
       0,    10,     0,    11,     0,    12,     0,    13,     0,    45,
      14,    35,     0,    36,     0,    37,     0,    38,     0,    39,
       0,    40,     0,    41,     0,    42,     0,    43,    78,    44,
       0,    79,     0,     9,     0,    10,     0,    11,     0,    12,
       0,    13,     0,    45,    14,     9,     9,    10,    10,    11,
      11,    12,    12,    13,    13,     0,    14,    14,    88,     9,
       0,    10,     0,    11,     0,    12,     0,    13,     0,     0,
      14,     9,    30,    10,     0,    11,     0,    12,     0,    13,
       0,     9,    14,    10,    31,    11,     0,    12,     0,    13,
       0,     9,    14,    10,     0,    11,    32,    12,     0,    13,
       0,     9,    14,    10,     0,    11,     0,    12,    33,    13,
       0,     9,    14,    10,     0,    11,     0,    12,     0,    13,
      34,     0,    14
};

static const yytype_int8 yycheck[] =
{
       6,    30,    31,     9,    10,    11,    12,    13,    28,     3,
      16,    31,     5,     0,    20,    21,    22,    23,    24,    71,
       4,    73,     7,     6,     6,    44,     9,    10,    11,    12,
      13,    37,    38,    16,     9,    31,     8,    20,    21,    22,
      23,    24,    10,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    37,    38,    -1,    -1,    64,    65,
      -1,    33,    -1,    35,    70,    37,    -1,    39,    -1,    41,
      -1,    -1,    44,    -1,    37,    38,    -1,    -1,    84,    35,
      36,    64,    65,    39,    40,    41,    42,    70,     6,    -1,
      -1,     9,    10,    11,    12,    13,    48,    -1,    16,    -1,
      -1,    84,    20,    21,    22,    23,    24,    70,    -1,    -1,
      62,    63,    -1,    -1,    66,    67,    68,    69,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      -1,    15,    -1,    17,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    27,    -1,    29,    64,    65,    -1,    33,
      -1,    35,    70,    37,    -1,    39,    -1,    41,    -1,    43,
      44,    11,    -1,    13,    14,    15,    84,    17,    -1,    19,
      33,    21,    35,    23,    37,    25,    39,    27,    41,    29,
      -1,    44,    -1,    33,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    -1,    43,    44,    11,    -1,    13,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    -1,    23,    -1,    25,
      -1,    27,    -1,    29,    -1,    -1,    -1,    33,    -1,    35,
      -1,    37,    -1,    39,    -1,    41,    -1,    43,    44,    11,
      -1,    13,    -1,    15,    -1,    17,    -1,    19,    -1,    21,
      22,    23,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,
      -1,    33,    -1,    35,    -1,    37,    -1,    39,    -1,    41,
      -1,    43,    44,    11,    -1,    13,    -1,    15,    -1,    17,
      -1,    19,    -1,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    39,    -1,    41,    -1,    43,    44,    11,    -1,    13,
      -1,    15,    -1,    17,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    -1,    43,
      44,    11,    -1,    13,    -1,    15,    -1,    17,    -1,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    27,    16,    29,
      -1,    18,    -1,    33,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    -1,    43,    44,    33,    33,    35,    35,    37,
      37,    39,    39,    41,    41,    -1,    44,    44,    32,    33,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,
      44,    33,    34,    35,    -1,    37,    -1,    39,    -1,    41,
      -1,    33,    44,    35,    36,    37,    -1,    39,    -1,    41,
      -1,    33,    44,    35,    -1,    37,    38,    39,    -1,    41,
      -1,    33,    44,    35,    -1,    37,    -1,    39,    40,    41,
      -1,    33,    44,    35,    -1,    37,    -1,    39,    -1,    41,
      42,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,     5,    47,     0,     7,    48,     4,    33,
      35,    37,    39,    41,    44,    49,    50,    65,    67,     6,
      50,    50,    50,    50,    50,     8,    49,    65,    67,     9,
      34,    36,    38,    40,    42,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    43,    49,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    65,
      66,    67,    52,    52,    50,    50,    52,    52,    52,    52,
      31,    63,    64,    63,    10,    53,    12,    14,    16,    18,
      20,    22,    24,    26,    50,    28,    64,    30,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    50,    50,    50,
      50,    50,    50,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    62,    63,
      63,    64,    65,    66,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     6,     3,     0,     1,     1,     2,     1,
       2,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     1,     3,     3,     3,     3
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
  case 2: /* document: HTML_START html_content HTML_END  */
#line 40 "parser.y"
    {
        root = create_node(NODE_ROOT);
        add_child(root, (yyvsp[-1].node));
        (yyval.node) = root;
    }
#line 1273 "parser.tab.c"
    break;

  case 3: /* html_content: HEAD_START head_content HEAD_END BODY_START body_content BODY_END  */
#line 49 "parser.y"
    {
        (yyval.node) = create_node(NODE_HTML);
        if ((yyvsp[-4].node)) add_child((yyval.node), (yyvsp[-4].node));
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1283 "parser.tab.c"
    break;

  case 4: /* head_content: TITLE_START mixed_content TITLE_END  */
#line 58 "parser.y"
    {
        (yyval.node) = create_node(NODE_HEAD);
        ASTNode* title = create_node(NODE_TITLE);
        add_child(title, (yyvsp[-1].node));
        add_child((yyval.node), title);
    }
#line 1294 "parser.tab.c"
    break;

  case 5: /* head_content: %empty  */
#line 64 "parser.y"
                  { (yyval.node) = NULL; }
#line 1300 "parser.tab.c"
    break;

  case 6: /* text_content: TEXT  */
#line 69 "parser.y"
    {
        (yyval.node) = create_node(NODE_TEXT);
        (yyval.node)->content = (yyvsp[0].sval);
    }
#line 1309 "parser.tab.c"
    break;

  case 7: /* mixed_content: text_content  */
#line 77 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1317 "parser.tab.c"
    break;

  case 8: /* mixed_content: mixed_content text_content  */
#line 81 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1330 "parser.tab.c"
    break;

  case 9: /* mixed_content: formatted_text  */
#line 90 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1338 "parser.tab.c"
    break;

  case 10: /* mixed_content: mixed_content formatted_text  */
#line 94 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1351 "parser.tab.c"
    break;

  case 11: /* mixed_content: link  */
#line 103 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1359 "parser.tab.c"
    break;

  case 12: /* mixed_content: mixed_content link  */
#line 107 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1372 "parser.tab.c"
    break;

  case 13: /* body_content: body_elements  */
#line 119 "parser.y"
    {
        (yyval.node) = create_node(NODE_BODY);
        if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
    }
#line 1381 "parser.tab.c"
    break;

  case 14: /* body_elements: body_element  */
#line 127 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1389 "parser.tab.c"
    break;

  case 15: /* body_elements: body_elements body_element  */
#line 131 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1402 "parser.tab.c"
    break;

  case 16: /* body_element: nav_element  */
#line 142 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1408 "parser.tab.c"
    break;

  case 17: /* body_element: header_element  */
#line 143 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1414 "parser.tab.c"
    break;

  case 18: /* body_element: section_element  */
#line 144 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1420 "parser.tab.c"
    break;

  case 19: /* body_element: article_element  */
#line 145 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1426 "parser.tab.c"
    break;

  case 20: /* body_element: aside_element  */
#line 146 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1432 "parser.tab.c"
    break;

  case 21: /* body_element: footer_element  */
#line 147 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1438 "parser.tab.c"
    break;

  case 22: /* body_element: p_element  */
#line 148 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1444 "parser.tab.c"
    break;

  case 23: /* body_element: heading  */
#line 149 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1450 "parser.tab.c"
    break;

  case 24: /* body_element: list  */
#line 150 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1456 "parser.tab.c"
    break;

  case 25: /* body_element: link  */
#line 151 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1462 "parser.tab.c"
    break;

  case 26: /* body_element: img_element  */
#line 152 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1468 "parser.tab.c"
    break;

  case 27: /* body_element: formatted_text  */
#line 153 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1474 "parser.tab.c"
    break;

  case 28: /* body_element: text_content  */
#line 154 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1480 "parser.tab.c"
    break;

  case 29: /* nav_element: NAV_START body_elements NAV_END  */
#line 159 "parser.y"
    {
        (yyval.node) = create_node(NODE_NAV);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1489 "parser.tab.c"
    break;

  case 30: /* header_element: HEADER_START body_elements HEADER_END  */
#line 167 "parser.y"
    {
        (yyval.node) = create_node(NODE_HEADER);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1498 "parser.tab.c"
    break;

  case 31: /* section_element: SECTION_START body_elements SECTION_END  */
#line 175 "parser.y"
    {
        (yyval.node) = create_node(NODE_SECTION);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1507 "parser.tab.c"
    break;

  case 32: /* article_element: ARTICLE_START body_elements ARTICLE_END  */
#line 183 "parser.y"
    {
        (yyval.node) = create_node(NODE_ARTICLE);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1516 "parser.tab.c"
    break;

  case 33: /* aside_element: ASIDE_START body_elements ASIDE_END  */
#line 191 "parser.y"
    {
        (yyval.node) = create_node(NODE_ASIDE);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1525 "parser.tab.c"
    break;

  case 34: /* footer_element: FOOTER_START body_elements FOOTER_END  */
#line 199 "parser.y"
    {
        (yyval.node) = create_node(NODE_FOOTER);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1534 "parser.tab.c"
    break;

  case 35: /* p_element: P_START mixed_content P_END  */
#line 207 "parser.y"
    {
        (yyval.node) = create_node(NODE_PARAGRAPH);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1543 "parser.tab.c"
    break;

  case 36: /* heading: H_START mixed_content H_END  */
#line 215 "parser.y"
    {
        (yyval.node) = create_node(NODE_HEADING);
        (yyval.node)->heading_level = (yyvsp[-2].ival);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1553 "parser.tab.c"
    break;

  case 37: /* list: UL_START list_items UL_END  */
#line 224 "parser.y"
    {
        (yyval.node) = create_node(NODE_LIST);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1562 "parser.tab.c"
    break;

  case 38: /* list: OL_START list_items OL_END  */
#line 229 "parser.y"
    {
        (yyval.node) = create_node(NODE_LIST);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1571 "parser.tab.c"
    break;

  case 39: /* list_items: list_item  */
#line 237 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1579 "parser.tab.c"
    break;

  case 40: /* list_items: list_items list_item  */
#line 241 "parser.y"
    {
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            (yyval.node) = (yyvsp[-1].node);
            if ((yyvsp[0].node)) add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1592 "parser.tab.c"
    break;

  case 41: /* list_item: LI_START mixed_content LI_END  */
#line 253 "parser.y"
    {
        (yyval.node) = create_node(NODE_LIST_ITEM);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1601 "parser.tab.c"
    break;

  case 42: /* link: A_START mixed_content A_END  */
#line 261 "parser.y"
    {
        (yyval.node) = create_node(NODE_LINK);
        (yyval.node)->attributes = (yyvsp[-2].sval);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1611 "parser.tab.c"
    break;

  case 43: /* img_element: IMG  */
#line 270 "parser.y"
    {
        (yyval.node) = create_node(NODE_IMAGE);
        (yyval.node)->attributes = (yyvsp[0].sval);
    }
#line 1620 "parser.tab.c"
    break;

  case 44: /* formatted_text: STRONG_START mixed_content STRONG_END  */
#line 278 "parser.y"
    {
        (yyval.node) = create_node(NODE_FORMATTED_TEXT);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1629 "parser.tab.c"
    break;

  case 45: /* formatted_text: EM_START mixed_content EM_END  */
#line 283 "parser.y"
    {
        (yyval.node) = create_node(NODE_FORMATTED_TEXT);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1638 "parser.tab.c"
    break;

  case 46: /* formatted_text: PRE_START mixed_content PRE_END  */
#line 288 "parser.y"
    {
        (yyval.node) = create_node(NODE_FORMATTED_TEXT);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1647 "parser.tab.c"
    break;

  case 47: /* formatted_text: BLOCKQUOTE_START mixed_content BLOCKQUOTE_END  */
#line 293 "parser.y"
    {
        (yyval.node) = create_node(NODE_FORMATTED_TEXT);
        if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1656 "parser.tab.c"
    break;


#line 1660 "parser.tab.c"

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

#line 299 "parser.y"


void yyerror(const char* s) {
    extern int yylineno;
    extern char* yytext;
    fprintf(stderr, "Parser error near line %d: %s at token '%s'\n", 
            yylineno, s, yytext);
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    // Parse the input
    yyparse();

    if (root) {
        // Open output file
        char output_file[256];
        snprintf(output_file, sizeof(output_file), "%s.ast", argv[1]);
        FILE* fp = fopen(output_file, "w");
        if (!fp) {
            perror("Failed to open output file");
            free_node(root);
            return 1;
        }

        // Print AST to file
        print_ast_to_file(fp, root, 0);
        fclose(fp);

        // Print to console for debugging
        printf("AST has been written to %s\n", output_file);
        printf("Debug output to console:\n");
        print_ast(root, 0);

        free_node(root);
    }
    return 0;
}
