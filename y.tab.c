/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ExprEval.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymTab.h"
#include "IOMngr.h"
#include "Semantics.h"
#include "CodeGen.h"

int yyerror(char* s);
extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern struct SymTab *table;
extern struct SymEntry *entry;


#line 87 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Ident = 258,
    IntLit = 259,
    Int = 260,
    Bool = 261,
    Write = 262,
    IF = 263,
    EQ = 264,
    GTEQ = 265,
    LTEQ = 266,
    NEQ = 267,
    Tru = 268,
    Fal = 269,
    AND = 270,
    OR = 271,
    WriteSp = 272,
    WriteLn = 273,
    STR = 274,
    Read = 275,
    Else = 276,
    While = 277,
    Def = 278,
    Call = 279,
    Return = 280
  };
#endif
/* Tokens.  */
#define Ident 258
#define IntLit 259
#define Int 260
#define Bool 261
#define Write 262
#define IF 263
#define EQ 264
#define GTEQ 265
#define LTEQ 266
#define NEQ 267
#define Tru 268
#define Fal 269
#define AND 270
#define OR 271
#define WriteSp 272
#define WriteLn 273
#define STR 274
#define Read 275
#define Else 276
#define While 277
#define Def 278
#define Call 279
#define Return 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "ExprEval.y" /* yacc.c:355  */

  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;
  struct BExprRes * BExprRes;

#line 185 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    41,     2,     2,
      26,    27,    39,    37,    34,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      35,    33,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    78,    79,    80,    81,    81,    83,
      83,    85,    86,    87,    88,    89,    90,    91,    93,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Ident", "IntLit", "Int", "Bool",
  "Write", "IF", "EQ", "GTEQ", "LTEQ", "NEQ", "Tru", "Fal", "AND", "OR",
  "WriteSp", "WriteLn", "STR", "Read", "Else", "While", "Def", "Call",
  "Return", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "'='", "','",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'!'", "$accept",
  "Prog", "Declarations", "FSeq", "FDec", "$@1", "$@2", "Dec", "StmtSeq",
  "Stmt", "RExprSeq", "RExpr", "PExpr", "Expr", "OTerm", "ATerm", "BTerm",
  "CTerm", "Term", "ExpTerm", "NegTerm", "Factor", "ValInt", "Id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    40,    41,   123,   125,
      59,    91,    93,    61,    44,    60,    62,    43,    45,    42,
      47,    37,    94,    33
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,    23,    23,    31,    75,    49,   -38,    70,    72,   -38,
     101,   -38,    75,   -38,   -38,    57,   -38,    57,    23,    23,
     -38,   -38,    46,    50,    78,    86,    89,    93,    81,    97,
     -38,   -38,    88,    98,    49,    49,   -38,   -38,    59,    59,
       1,   102,     1,    99,   104,   105,    23,     1,   103,    59,
      38,   106,   -38,   -38,   -38,     1,    39,    39,   107,   -13,
     112,    16,    -2,    73,    55,   -38,    91,   -38,   -38,    42,
       1,     0,   -38,    23,     1,   110,    19,   -38,   -38,     1,
       1,   -38,    43,   -38,   -38,   -38,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,   111,     1,    47,   -38,   113,   108,   115,    48,
     116,   -38,   -10,    20,   -38,   112,   -38,    16,    -2,    -2,
      73,    73,    73,    73,    73,    55,    55,   -38,   -38,   -38,
     -38,   -38,    -9,   119,   109,    23,     1,   120,   114,   117,
     -38,   -38,    59,   -38,   -38,    -3,    59,   -38,     1,   122,
     -38,   123,    30,   128,   -38,   -38,   125,    59,   126,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     6,     4,    68,     0,     0,     1,
       0,     2,     6,     3,    11,     0,    12,     0,     0,     0,
       5,    64,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,     4,     4,     7,     9,    16,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    59,    60,    61,     0,     0,     0,     0,    33,
      35,    37,    40,    46,    49,    53,    55,    58,    62,    66,
       0,     0,    20,     0,     0,     0,     0,     8,    15,     0,
       0,    10,     0,    56,    57,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    29,    30,     0,
       0,    27,     0,     0,    65,    34,    32,    36,    39,    38,
      41,    42,    43,    44,    45,    47,    48,    50,    51,    52,
      54,    63,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    67,    16,    25,    28,     0,    16,    26,     0,     0,
      31,     0,     0,    23,    17,    22,     0,    16,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,     6,   142,   -38,   -38,   -38,   -38,   -37,   -38,
      22,   -38,    71,   -23,    74,    76,    25,    -6,    21,    -8,
     -38,    65,    82,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    11,    12,    38,    39,     5,    48,    49,
     106,   107,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,     8,    51,    86,     6,    21,    86,    86,    91,    92,
      93,    13,    78,    86,    52,    53,    86,    24,    25,    71,
      54,    87,   139,   141,    76,    89,     6,    55,    90,   150,
     105,     9,    82,    94,    95,    86,    86,    50,    50,    56,
      36,    37,     6,    21,    57,    75,    86,   104,    50,   111,
     140,   109,    52,    53,     1,     2,   112,   113,    54,    86,
     155,    21,     6,    86,    86,    55,    40,    41,   102,    79,
     114,    80,   108,   103,   133,   137,    42,    43,    26,    44,
     132,    45,    27,    46,    47,   120,   121,   122,   123,   124,
     127,   128,   129,   130,    98,    99,   100,    22,    10,    23,
      14,    15,    16,    17,    28,   149,    18,    19,    32,   151,
      96,    97,    29,   145,   118,   119,    34,   125,   126,    30,
     158,    83,    84,    31,    33,   152,    35,    88,    70,    72,
      73,    74,    77,   101,   108,    81,   110,    85,   131,   143,
     134,    50,   135,   138,   147,    50,   136,   142,   146,   156,
     148,   153,   154,   157,    20,   159,    50,   144,   116,     0,
     115,     0,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
       1,     2,    39,    16,     3,     4,    16,    16,    10,    11,
      12,     5,    49,    16,    13,    14,    16,    18,    19,    42,
      19,    34,    32,    32,    47,     9,     3,    26,    12,    32,
      30,     0,    55,    35,    36,    16,    16,    38,    39,    38,
      34,    35,     3,     4,    43,    46,    16,    70,    49,    30,
      30,    74,    13,    14,     5,     6,    79,    80,    19,    16,
      30,     4,     3,    16,    16,    26,     7,     8,    26,    31,
      27,    33,    73,    31,    27,    27,    17,    18,    32,    20,
     103,    22,    32,    24,    25,    91,    92,    93,    94,    95,
      98,    99,   100,   101,    39,    40,    41,    15,    23,    17,
      30,    31,    30,    31,    26,   142,     5,     6,    27,   146,
      37,    38,    26,   136,    89,    90,    28,    96,    97,    30,
     157,    56,    57,    30,    27,   148,    28,    15,    26,    30,
      26,    26,    29,    42,   135,    29,    26,    30,    27,    30,
      27,   142,    34,    27,    30,   146,    31,    28,    28,    21,
      33,    29,    29,    28,    12,    29,   157,   135,    87,    -1,
      86,    -1,    -1,    -1,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    45,    46,    51,     3,    67,    67,     0,
      23,    47,    48,    46,    30,    31,    30,    31,     5,     6,
      47,     4,    66,    66,    67,    67,    32,    32,    26,    26,
      30,    30,    27,    27,    28,    28,    46,    46,    49,    50,
       7,     8,    17,    18,    20,    22,    24,    25,    52,    53,
      67,    52,    13,    14,    19,    26,    38,    43,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      26,    57,    30,    26,    26,    67,    57,    29,    52,    31,
      33,    29,    57,    65,    65,    30,    16,    34,    15,     9,
      12,    10,    11,    12,    35,    36,    37,    38,    39,    40,
      41,    42,    26,    31,    57,    30,    54,    55,    67,    57,
      26,    30,    57,    57,    27,    58,    56,    59,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    27,    57,    27,    27,    34,    31,    27,    27,    32,
      30,    32,    28,    30,    54,    57,    28,    30,    33,    52,
      32,    52,    57,    29,    29,    30,    21,    28,    52,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    49,    48,    50,
      48,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    66,    65,    65,    65,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     0,     0,    10,     0,
      10,     3,     3,     6,     6,     2,     0,     7,     3,     3,
       2,     4,     7,     7,    11,     5,     5,     3,     3,     1,
       1,     4,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 76 "ExprEval.y" /* yacc.c:1646  */
    {Finish((yyvsp[0].InstrSeq)); }
#line 1379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "ExprEval.y" /* yacc.c:1646  */
    { }
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "ExprEval.y" /* yacc.c:1646  */
    { }
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = AppendSeq((yyvsp[-1].InstrSeq), (yyvsp[0].InstrSeq));}
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = NULL;}
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "ExprEval.y" /* yacc.c:1646  */
    {FuncInit((yyvsp[-4].string), TYPE_INT);}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = FuncDec((yyvsp[-7].string), (yyvsp[-1].InstrSeq));}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "ExprEval.y" /* yacc.c:1646  */
    {FuncInit((yyvsp[-4].string), TYPE_BOOL); }
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = FuncDec((yyvsp[-7].string), (yyvsp[-1].InstrSeq)); }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "ExprEval.y" /* yacc.c:1646  */
    {IntDec((yyvsp[-1].string)); }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "ExprEval.y" /* yacc.c:1646  */
    {BoolDec((yyvsp[-1].string)); }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "ExprEval.y" /* yacc.c:1646  */
    {IntArrDec((yyvsp[-4].string),(yyvsp[-2].string)); }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 88 "ExprEval.y" /* yacc.c:1646  */
    {BoolArrDec((yyvsp[-4].string),(yyvsp[-2].string)); }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 89 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = AppendSeq((yyvsp[-1].InstrSeq), (yyvsp[0].InstrSeq)); }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 90 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = NULL; }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 91 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doWhile((yyvsp[-4].ExprRes), (yyvsp[-1].InstrSeq)); }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 93 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = (yyvsp[-1].InstrSeq); }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doPrintsp((yyvsp[-1].ExprRes)); }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 95 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doPrintln();}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 96 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doAssign((yyvsp[-3].string), (yyvsp[-1].ExprRes)); }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doArrayAssign((yyvsp[-6].string),(yyvsp[-4].ExprRes),(yyvsp[-1].ExprRes)); }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 99 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doIf((yyvsp[-4].ExprRes), (yyvsp[-1].InstrSeq)); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doIfElse((yyvsp[-8].ExprRes), (yyvsp[-5].InstrSeq), (yyvsp[-1].InstrSeq)); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = (yyvsp[-2].InstrSeq); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doFuncStmt((yyvsp[-3].string));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doReturn((yyvsp[-1].ExprRes));}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 104 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq)); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 105 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 106 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doRead((yyvsp[0].string)); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 107 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doArrayRead((yyvsp[-3].string), (yyvsp[-1].ExprRes)); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 108 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doPrintSeq((yyvsp[-2].ExprRes), (yyvsp[0].InstrSeq)); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 109 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.InstrSeq) = doPrint((yyvsp[0].ExprRes)); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doOr((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doAnd((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 3); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 115 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 0); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 117 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 1); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 118 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 2); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 3); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 120 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 4); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 121 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doRelOp((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes), 5); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 122 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 124 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doAdd((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 125 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = doBinaryMinus((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 126 "ExprEval.y" /* yacc.c:1646  */
    {(yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 127 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doMult((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doDivide((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doMod((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 131 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doPower((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes)); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doNeg((yyvsp[0].ExprRes)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doNot((yyvsp[0].ExprRes)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 136 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doBoolLit(1); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 137 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doBoolLit(0); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 138 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doStrLit(yytext ); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 139 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doIntLit((yyvsp[0].string)) ; }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 140 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doFuncCall((yyvsp[-2].string)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 141 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.string) = strdup(yytext); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 142 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = (yyvsp[-1].ExprRes); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 143 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doRval((yyvsp[0].string)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 144 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.ExprRes) = doArrayRval((yyvsp[-3].string), (yyvsp[-1].ExprRes)); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 145 "ExprEval.y" /* yacc.c:1646  */
    { (yyval.string) = strdup(yytext); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1779 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 147 "ExprEval.y" /* yacc.c:1906  */


int
yyerror(char *s)  {
  WriteIndicator(GetCurrentColumn());
  WriteMessage("Illegal Character in YACC");
  return 1;
}
