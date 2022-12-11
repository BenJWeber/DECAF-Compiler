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
#line 1 "lab9.y" /* yacc.c:339  */

// Ben Weber
// Lab 9
// 10/31/2022 
// 


	/* begin specs */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "symtable.h"
#include "ast.h"
#include "emit.h"

// function prototypes for emit.c
extern void emit_gas(FILE *fp);


// file variables
FILE *fp;

// create space for filename with .s suffix
char filename_final[100];


// keep track of level of blocks we have seen
int LEVEL = 0;

// maintain offsets
int OFFSET = 0;
int GOFFSET;
int MAXOFFSET;

// AST Global Pointer
struct ASTnodetype *PROGRAM;

// from Lex
extern int linecount;

extern int debugsw;

// prints linecount along with error notification
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line  %d\n", s, linecount);
}

// This prototype makes the type of yylex() explicit and clears a warning
int yylex();



#line 122 "y.tab.c" /* yacc.c:339  */

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
    T_PACKAGE = 258,
    T_EXTERN = 259,
    T_ID = 260,
    T_INTEGER = 261,
    T_FUNC = 262,
    T_INT = 263,
    T_BOOL = 264,
    T_STRING = 265,
    T_VOID = 266,
    T_ASSIGN = 267,
    T_BREAK = 268,
    T_BOOLTYPE = 269,
    T_AND = 270,
    T_CHARCONSTANT = 271,
    T_CONTINUE = 272,
    T_DOT = 273,
    T_ELSE = 274,
    T_EQ = 275,
    T_FALSE = 276,
    T_FOR = 277,
    T_GEQ = 278,
    T_GT = 279,
    T_IF = 280,
    T_LT = 281,
    T_INTCONSTANT = 282,
    T_INTTYPE = 283,
    T_LEFTSHIFT = 284,
    T_LEQ = 285,
    T_NEQ = 286,
    T_NULL = 287,
    T_OR = 288,
    T_RETURN = 289,
    T_RIGHTSHIFT = 290,
    T_STRINGCONSTANT = 291,
    T_STRINGTYPE = 292,
    T_TRUE = 293,
    T_VAR = 294,
    T_WHILE = 295
  };
#endif
/* Tokens.  */
#define T_PACKAGE 258
#define T_EXTERN 259
#define T_ID 260
#define T_INTEGER 261
#define T_FUNC 262
#define T_INT 263
#define T_BOOL 264
#define T_STRING 265
#define T_VOID 266
#define T_ASSIGN 267
#define T_BREAK 268
#define T_BOOLTYPE 269
#define T_AND 270
#define T_CHARCONSTANT 271
#define T_CONTINUE 272
#define T_DOT 273
#define T_ELSE 274
#define T_EQ 275
#define T_FALSE 276
#define T_FOR 277
#define T_GEQ 278
#define T_GT 279
#define T_IF 280
#define T_LT 281
#define T_INTCONSTANT 282
#define T_INTTYPE 283
#define T_LEFTSHIFT 284
#define T_LEQ 285
#define T_NEQ 286
#define T_NULL 287
#define T_OR 288
#define T_RETURN 289
#define T_RIGHTSHIFT 290
#define T_STRINGCONSTANT 291
#define T_STRINGTYPE 292
#define T_TRUE 293
#define T_VAR 294
#define T_WHILE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "lab9.y" /* yacc.c:355  */

   int value;
   char* string;
   struct ASTnodetype *astnode;
   enum AST_Decaf_Types asttype;
   enum AST_Operators operator;

#line 250 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      43,    44,    51,    49,    46,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   109,   110,   114,   129,   130,   133,   138,
     146,   147,   153,   166,   180,   196,   197,   202,   203,   202,
     227,   228,   231,   244,   261,   260,   277,   278,   284,   297,
     313,   314,   320,   323,   324,   325,   326,   332,   339,   344,
     347,   350,   354,   360,   376,   396,   420,   449,   450,   454,
     464,   478,   482,   490,   493,   494,   512,   513,   514,   515,
     516,   517,   520,   521,   539,   540,   543,   544,   576,   577,
     578,   579,   580,   581,   582,   585,   605,   606,   627,   628,
     629,   644,   663,   664,   667,   668,   671,   672,   675,   680,
     687,   694,   700
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PACKAGE", "T_EXTERN", "T_ID",
  "T_INTEGER", "T_FUNC", "T_INT", "T_BOOL", "T_STRING", "T_VOID",
  "T_ASSIGN", "T_BREAK", "T_BOOLTYPE", "T_AND", "T_CHARCONSTANT",
  "T_CONTINUE", "T_DOT", "T_ELSE", "T_EQ", "T_FALSE", "T_FOR", "T_GEQ",
  "T_GT", "T_IF", "T_LT", "T_INTCONSTANT", "T_INTTYPE", "T_LEFTSHIFT",
  "T_LEQ", "T_NEQ", "T_NULL", "T_OR", "T_RETURN", "T_RIGHTSHIFT",
  "T_STRINGCONSTANT", "T_STRINGTYPE", "T_TRUE", "T_VAR", "T_WHILE", "'{'",
  "'}'", "'('", "')'", "';'", "','", "'['", "']'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "$accept", "Program", "Externs", "ExternDefn",
  "ExternTypeList", "ExternTypeList1", "FieldDecls", "FieldDecl",
  "MethodDecls", "MethodDecl", "$@1", "$@2", "IdTypeList", "IdTypeList1",
  "Block", "$@3", "VarDecls", "VarDecl", "Statements", "Statement",
  "Assign", "Lvalue", "MethodCall", "MethodArgList", "MethodArgList1",
  "MethodArg", "Expr", "Simpleexpression", "Relop", "Additiveexpression",
  "Addop", "Term", "Multop", "Factor", "ExternType", "Type", "MethodType",
  "BoolConstant", "ArrayType", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   123,   125,    40,    41,    59,    44,    91,    93,    43,
      45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,     8,    22,    25,     4,    26,   -94,    33,   -94,     0,
      19,    46,    36,   -94,   -94,   -94,    32,   -94,    17,   -94,
      72,    71,    36,    57,    46,    -2,    78,    43,    71,   -94,
     -94,   -94,    41,   -94,    62,    -9,    45,   -94,   -94,   -94,
     -94,    44,    -8,   -94,   -94,    48,    61,   -94,   -94,   -94,
     -94,    55,    97,   -94,   -94,    61,    64,   -94,    60,    57,
      97,   -94,   -94,    69,   -94,   -94,    74,   109,    54,    74,
      -2,   -38,    70,    73,    76,   -29,    77,   -94,    75,    54,
      79,   104,    80,   -94,    82,    84,    -4,    -1,   -94,   -94,
      -1,    -3,   -94,    -1,   -94,   -94,   -94,    -1,   -94,   -94,
     -94,   -14,   -94,    -1,    -1,    -1,   -94,    86,   -94,    85,
     -94,    81,    24,    29,   -94,   -94,    87,    88,    89,    92,
      93,   -94,    -1,    94,   -94,   -94,   -94,    -4,   -94,   -94,
     -94,   -94,   -94,   -94,    -1,   -94,   -94,    -1,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,    -1,   -94,    69,   -94,    95,
      69,    91,   -94,   -94,    24,    29,   -94,   102,   -94,   -94,
     -94,    69,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,     0,     4,     0,
       0,     6,    10,    84,    85,    82,     0,     7,     8,    83,
       0,    15,    10,     0,     0,     0,     0,     0,    15,    11,
      86,    87,     0,     9,     0,     0,     0,    17,     2,    16,
       5,     0,     0,    12,    14,     0,     0,    89,    91,    88,
      92,     0,    20,    90,    13,     0,     0,    21,    22,     0,
       0,    18,    23,     0,    24,    19,    26,     0,    30,    26,
       0,    44,     0,     0,     0,     0,     0,    33,     0,    30,
       0,     0,     0,    27,     0,     0,    47,     0,    32,    42,
       0,     0,    39,     0,    25,    31,    34,     0,    35,    28,
      29,    75,    52,     0,     0,     0,    76,     0,    48,    49,
      51,    53,    54,    62,    66,    78,     0,     0,     0,     0,
       0,    43,     0,     0,    81,    80,    46,     0,    60,    59,
      58,    57,    56,    61,     0,    64,    65,     0,    71,    73,
      72,    74,    68,    69,    70,     0,    45,     0,    40,     0,
       0,     0,    79,    50,    55,    63,    67,    36,    41,    38,
      77,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   118,   -94,   -94,    99,   111,   -94,    98,   -94,
     -94,   -94,   -94,    83,   -63,   -94,    90,   -94,    63,   -94,
     -94,   -94,   -58,   -94,    14,   -94,     6,   -94,   -94,    10,
     -94,     9,   -94,   -93,   -94,     2,    96,   -94,   100,   103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    16,    17,    21,    22,    27,    28,
      45,    63,    56,    57,    77,    66,    68,    69,    78,    79,
      80,    81,   106,   107,   108,   109,   110,   111,   134,   112,
     137,   113,   145,   114,    18,    19,    32,    50,    36,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,   101,   101,    42,   101,    86,    13,    14,     1,    87,
      82,   124,   125,    47,    91,     5,    92,    47,    47,    48,
      47,    82,     6,    48,    48,    31,    48,    35,     7,    86,
      49,     9,   102,   122,    49,    49,    43,    49,    10,   103,
     103,   118,   103,    11,   138,    34,   104,   104,    53,   104,
     105,   105,   156,   105,    13,    14,    15,    58,   139,    71,
      12,    31,   140,    24,   141,    13,    14,    72,    30,    13,
      14,    73,    84,   135,   136,    20,    23,    25,    26,    74,
     142,   143,   144,    37,   157,    38,    40,   159,    75,    41,
      44,    52,    46,   116,    76,    64,   117,   119,   162,   120,
      54,   128,    55,   121,   129,   130,    60,   131,    59,   123,
      64,   132,   133,    67,    70,    88,    97,    94,    89,    90,
      93,   161,     8,    33,    96,    98,    39,    99,   151,   100,
     126,   127,   147,    29,   148,   146,   149,   150,   152,   160,
     158,   153,    95,    62,   154,    51,   155,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85
};

static const yytype_int16 yycheck[] =
{
      63,     5,     5,    12,     5,    43,     8,     9,     4,    47,
      68,   104,   105,    21,    43,     7,    45,    21,    21,    27,
      21,    79,     0,    27,    27,    23,    27,    25,     3,    43,
      38,     5,    36,    47,    38,    38,    45,    38,     5,    43,
      43,    44,    43,    43,    15,    47,    50,    50,    46,    50,
      54,    54,   145,    54,     8,     9,    10,    55,    29,     5,
      41,    59,    33,    46,    35,     8,     9,    13,    11,     8,
       9,    17,    70,    49,    50,    39,    44,     5,     7,    25,
      51,    52,    53,     5,   147,    42,    45,   150,    34,    27,
      45,    43,    48,    87,    40,    41,    90,    91,   161,    93,
      45,    20,     5,    97,    23,    24,    46,    26,    44,   103,
      41,    30,    31,    39,     5,    45,    12,    42,    45,    43,
      43,    19,     4,    24,    45,    45,    28,    45,   122,    45,
      44,    46,    44,    22,    45,    48,    44,    44,    44,    48,
      45,   127,    79,    60,   134,    42,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    56,    57,    58,     7,     0,     3,    57,     5,
       5,    43,    41,     8,     9,    10,    59,    60,    89,    90,
      39,    61,    62,    44,    46,     5,     7,    63,    64,    61,
      11,    90,    91,    60,    47,    90,    93,     5,    42,    63,
      45,    27,    12,    45,    45,    65,    48,    21,    27,    38,
      92,    94,    43,    90,    45,     5,    67,    68,    90,    44,
      46,    91,    68,    66,    41,    69,    70,    39,    71,    72,
       5,     5,    13,    17,    25,    34,    40,    69,    73,    74,
      75,    76,    77,    71,    90,    93,    43,    47,    45,    45,
      43,    43,    45,    43,    42,    73,    45,    12,    45,    45,
      45,     5,    36,    43,    50,    54,    77,    78,    79,    80,
      81,    82,    84,    86,    88,    94,    81,    81,    44,    81,
      81,    81,    47,    81,    88,    88,    44,    46,    20,    23,
      24,    26,    30,    31,    83,    49,    50,    85,    15,    29,
      33,    35,    51,    52,    53,    87,    48,    44,    45,    44,
      44,    81,    44,    79,    84,    86,    88,    69,    45,    69,
      48,    19,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    65,    66,    64,
      67,    67,    68,    68,    70,    69,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     2,     8,     0,     1,     1,     3,
       0,     2,     4,     6,     4,     0,     2,     0,     0,     9,
       0,     1,     2,     4,     0,     5,     0,     2,     4,     4,
       0,     2,     2,     1,     2,     2,     5,     7,     5,     2,
       4,     5,     2,     3,     1,     4,     4,     0,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1
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
#line 98 "lab9.y" /* yacc.c:1646  */
    { PROGRAM = ASTCreateNode(A_PROGRAM);
              PROGRAM->S1 = (yyvsp[-6].astnode);
              PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
              PROGRAM->S2->name = (yyvsp[-4].string);
              PROGRAM->S2->S1 = (yyvsp[-2].astnode); 
              PROGRAM->S2->S2 = (yyvsp[-1].astnode);
	      PROGRAM->S2->symbol = Insert((yyvsp[-4].string), A_Decaf_VOID, ID_Sub_Type_Package , LEVEL, 0, 0, NULL);
            }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "lab9.y" /* yacc.c:1646  */
    {(yyvsp[-1].astnode)->next = (yyvsp[0].astnode);}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "lab9.y" /* yacc.c:1646  */
    {
              	if (Search((yyvsp[-5].string),LEVEL,0) != NULL) {
	         yyerror("Symbol already defined");
		 yyerror((yyvsp[-5].string));
		 exit(1);
		}
	      	(yyval.astnode) = ASTCreateNode(A_EXTERN);
              	(yyval.astnode)->name = (yyvsp[-5].string);
              	(yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype);
              	(yyval.astnode)->S1 = (yyvsp[-3].astnode);
		(yyval.astnode)->symbol=Insert((yyvsp[-5].string), (yyvsp[-1].asttype), ID_Sub_Type_ExternMethod, LEVEL, 0, 0, (yyvsp[-3].astnode));
		}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "lab9.y" /* yacc.c:1646  */
    {
                     (yyval.astnode) = ASTCreateNode(A_ExternType);
                     (yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
                    }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "lab9.y" /* yacc.c:1646  */
    {
                     (yyval.astnode) = ASTCreateNode(A_ExternType);
                     (yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
                     (yyval.astnode)->next = (yyvsp[0].astnode);
                    }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 146 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[-1].astnode);
               (yyval.astnode)->next = (yyvsp[0].astnode);
             }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "lab9.y" /* yacc.c:1646  */
    {
		if (Search((yyvsp[-2].string), LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror((yyvsp[-2].string));
		   exit(1);
		}
		(yyval.astnode) = ASTCreateNode(A_VARDEC);
             	(yyval.astnode)->name = (yyvsp[-2].string);
             	(yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype);
		(yyval.astnode)->symbol = Insert((yyvsp[-2].string), (yyvsp[-1].asttype), ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		OFFSET++;		
            }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "lab9.y" /* yacc.c:1646  */
    {
		if (Search((yyvsp[-4].string), LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror((yyvsp[-4].string));
		   exit(1);
		}
		(yyval.astnode) = ASTCreateNode(A_VARDEC);
             	(yyval.astnode)->name = (yyvsp[-4].string);
             	(yyval.astnode)->A_Declared_Type = (yyvsp[-3].asttype);
             	(yyval.astnode)->S2 = (yyvsp[-1].astnode);
                (yyval.astnode)->symbol = Insert((yyvsp[-4].string), (yyvsp[-3].asttype), ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		OFFSET++;
	    }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "lab9.y" /* yacc.c:1646  */
    {
		if (Search((yyvsp[-2].string), LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror((yyvsp[-2].string));
		   exit(1);
		}
		(yyval.astnode) = ASTCreateNode(A_VARDEC);
             	(yyval.astnode)->name = (yyvsp[-2].string);
             	(yyval.astnode)->S1 = (yyvsp[-1].astnode);
             	(yyval.astnode)->A_Declared_Type = (yyvsp[-1].astnode)->A_Declared_Type;
                (yyval.astnode)->symbol = Insert((yyvsp[-2].string), (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Array, LEVEL, (yyval.astnode)->S1->value, OFFSET, NULL);
		OFFSET += (yyval.astnode)->S1->value;
	    }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);
              (yyval.astnode)->next = (yyvsp[0].astnode);}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "lab9.y" /* yacc.c:1646  */
    { GOFFSET = OFFSET; OFFSET = 0; MAXOFFSET = OFFSET;}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "lab9.y" /* yacc.c:1646  */
    { if (Search((yyvsp[-5].string), LEVEL, 0) != NULL) {
			yyerror("Method named already defined");
			yyerror((yyvsp[-5].string));
			exit(1);
		}
		
	        Insert((yyvsp[-5].string), (yyvsp[0].asttype), ID_Sub_Type_Method, LEVEL, 0, 0, (yyvsp[-2].astnode));
	      
	      }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 213 "lab9.y" /* yacc.c:1646  */
    {
	       (yyval.astnode) = ASTCreateNode(A_METHODDEC);
               (yyval.astnode)->name = (yyvsp[-7].string);
               (yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
               (yyval.astnode)->S1 = (yyvsp[-4].astnode);
               (yyval.astnode)->S2 = (yyvsp[0].astnode);
	       (yyval.astnode)->symbol = Search((yyvsp[-7].string), LEVEL, 0);
	       (yyval.astnode)->size = MAXOFFSET;
	       (yyval.astnode)->symbol->mysize = MAXOFFSET;
	       OFFSET = GOFFSET;
	                      
              }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 228 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "lab9.y" /* yacc.c:1646  */
    { if (Search((yyvsp[-1].string), LEVEL + 1, 0) != NULL) {
			yyerror("Duplicate method arg name");
			yyerror((yyvsp[-1].string));
			exit(1);
		} 
		
	      	(yyval.astnode) = ASTCreateNode(A_METHODIDENTIFIER);
               	(yyval.astnode)->name = (yyvsp[-1].string);
               	(yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
		(yyval.astnode)->symbol = Insert((yyvsp[-1].string), (yyvsp[0].asttype), ID_Sub_Type_Scalar, LEVEL + 1, 1, OFFSET, NULL);
		OFFSET++; 
              }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 245 "lab9.y" /* yacc.c:1646  */
    { 
	        if (Search((yyvsp[-3].string), LEVEL + 1, 0) != NULL) {
			yyerror("Duplicate method arg name");
			yyerror((yyvsp[-3].string));
			exit(1);
		} 
		(yyval.astnode) = ASTCreateNode(A_METHODIDENTIFIER);
               	(yyval.astnode)->name = (yyvsp[-3].string);
               	(yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
               	(yyval.astnode)->next = (yyvsp[0].astnode);
		(yyval.astnode)->symbol = Insert((yyvsp[-3].string), (yyvsp[-2].asttype), ID_Sub_Type_Scalar, LEVEL + 1, 1, OFFSET, NULL);
		OFFSET++; 
               }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "lab9.y" /* yacc.c:1646  */
    { LEVEL++; }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 263 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_BLOCK);
          (yyval.astnode)->S1 = (yyvsp[-2].astnode);
          (yyval.astnode)->S2 = (yyvsp[-1].astnode);
	  // at end of block, clear local variables and reduce offset and level accordingly
	  if (debugsw == 1) {
		Display();
	  }
	  
	  if (OFFSET > MAXOFFSET) MAXOFFSET = OFFSET;
	  OFFSET -= Delete(LEVEL);	
	  LEVEL--;
         }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 277 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 279 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);
             (yyval.astnode)->next = (yyvsp[0].astnode);
            }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 285 "lab9.y" /* yacc.c:1646  */
    {
 	if (Search((yyvsp[-2].string), LEVEL, 0) != NULL) {
	   yyerror("Variable already defined at this level");
	   yyerror((yyvsp[-2].string));
	   exit(1);
	}
	   (yyval.astnode) = ASTCreateNode(A_VARDEC);
           (yyval.astnode)->name = (yyvsp[-2].string);
           (yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype);
	   (yyval.astnode)->symbol = Insert((yyvsp[-2].string), (yyvsp[-1].asttype), ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	   OFFSET++;
	   }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 298 "lab9.y" /* yacc.c:1646  */
    {
	   if (Search((yyvsp[-2].string), LEVEL, 0) != NULL) {
	      yyerror("Array already defined at this level");
	      yyerror((yyvsp[-2].string));
	      exit(1);
	   }
	   (yyval.astnode) = ASTCreateNode(A_VARDEC);
           (yyval.astnode)->name = (yyvsp[-2].string);
           (yyval.astnode)->S1 = (yyvsp[-1].astnode);
           (yyval.astnode)->A_Declared_Type = (yyval.astnode)->S1->A_Declared_Type; 
           (yyval.astnode)->symbol = Insert((yyvsp[-2].string), (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Array, LEVEL, (yyval.astnode)->S1->value, OFFSET, NULL);
	   OFFSET += (yyval.astnode)->S1->value; 
	   }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);
          (yyval.astnode)->next = (yyvsp[0].astnode);
         }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 321 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_BREAK);
            }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 323 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 324 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 325 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_IFSTMT);
             (yyval.astnode)->S1 = (yyvsp[-2].astnode);
             (yyval.astnode)->S2 = ASTCreateNode(A_IFSTMT);
             (yyval.astnode)->S2->S1 = (yyvsp[0].astnode);
            }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 333 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_IFSTMT);
             (yyval.astnode)->S1 = (yyvsp[-4].astnode);
             (yyval.astnode)->S2 = ASTCreateNode(A_IFSTMT);
             (yyval.astnode)->S2->S1 = (yyvsp[-2].astnode);
             (yyval.astnode)->S2->S2 = (yyvsp[0].astnode);
            }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 340 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_WHILESTMT);
             (yyval.astnode)->S1 = (yyvsp[-2].astnode);
             (yyval.astnode)->S2 = (yyvsp[0].astnode);
            }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 345 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_RETURN);
            }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 348 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_RETURN);
            }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 351 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_RETURN);
             (yyval.astnode)->S1 = (yyvsp[-2].astnode);
            }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 355 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_CONTINUE);
            }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 361 "lab9.y" /* yacc.c:1646  */
    {
	  if ((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type) {
		yyerror("type mismatch on assignment ");
		exit(1);
	  }

	  (yyval.astnode) = ASTCreateNode(A_ASSIGN);
          (yyval.astnode)->S1 = (yyvsp[-2].astnode);
          (yyval.astnode)->S2 = (yyvsp[0].astnode);
	  (yyval.astnode)->name = TEMP_CREATE();
	  (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	  OFFSET++; 
         }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 377 "lab9.y" /* yacc.c:1646  */
    { 
	  struct SymbTab *p;
	  p = Search((yyvsp[0].string), LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on LVALUE not defined");
	       yyerror((yyvsp[0].string));
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Scalar)
	     { yyerror((yyvsp[0].string));
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }
	
	 (yyval.astnode) = ASTCreateNode(A_LVALUE);
         (yyval.astnode)->name = (yyvsp[0].string);
	 (yyval.astnode)->symbol = p;
	 (yyval.astnode)->A_Declared_Type = p->Type;
         }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 397 "lab9.y" /* yacc.c:1646  */
    {
	  struct SymbTab *p;
	  p = Search((yyvsp[-3].string), LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on LVALUE not defined");
	       yyerror((yyvsp[-3].string));
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Array)
	     { yyerror((yyvsp[-3].string));
	       yyerror(" needs to be an array, wrong subtype");
	       exit(1);
	     }
	

	  (yyval.astnode) = ASTCreateNode(A_LVALUE);
          (yyval.astnode)->name = (yyvsp[-3].string);
          (yyval.astnode)->S1 = (yyvsp[-1].astnode);
	  (yyval.astnode)->A_Declared_Type = p->Type;
         }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 421 "lab9.y" /* yacc.c:1646  */
    {	
	  struct SymbTab *p;
	  p = Search((yyvsp[-3].string), LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol not defined");
	       yyerror((yyvsp[-3].string));
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_ExternMethod && p->SubType != ID_Sub_Type_Method) {
	        yyerror((yyvsp[-3].string));
	       yyerror(" needs to be a method, wrong subtype");
	       exit(1);
	     }
		
	     if (check_parameters(p->fparms, (yyvsp[-1].astnode)) == 0) {
		yyerror("Formal and actual parameters do not match");
		yyerror((yyvsp[-3].string));
		exit(1);
	     }
	
	      (yyval.astnode) = ASTCreateNode(A_METHODCALL);
              (yyval.astnode)->name = (yyvsp[-3].string);
              (yyval.astnode)->S1 = (yyvsp[-1].astnode);
	      (yyval.astnode)->symbol = p;
	      (yyval.astnode)->A_Declared_Type = p->Type;
             }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 449 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 451 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 455 "lab9.y" /* yacc.c:1646  */
    {// MethodArg node is handled here instead of in the MethodArg rule like the videos because my rules were set up differently for some reason
		  			// Instead of getting the type from Expr immediately, we get it after plumbing S1
		  			(yyval.astnode) = ASTCreateNode(A_METHODARG);
        			(yyval.astnode)->S1 = (yyvsp[0].astnode);
		  			(yyval.astnode)->A_Declared_Type = (yyval.astnode)->S1->A_Declared_Type;
		  			(yyval.astnode)->name = TEMP_CREATE();
	        		(yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		  			OFFSET++;
                 }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 465 "lab9.y" /* yacc.c:1646  */
    {// MethodArg node is handled here instead of in the MethodArg rule like the videos because my rules were set up differently for some reason
                  // Instead of getting the type from Expr immediately, we get it after plumbing S1

		  (yyval.astnode) = ASTCreateNode(A_METHODARG);
                  (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                  (yyval.astnode)->next = (yyvsp[0].astnode);
                  (yyval.astnode)->A_Declared_Type = (yyval.astnode)->S1->A_Declared_Type;
	          (yyval.astnode)->name = TEMP_CREATE();
		  (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		  OFFSET++;
                 }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 479 "lab9.y" /* yacc.c:1646  */
    {
	     (yyval.astnode) = (yyvsp[0].astnode);
	    }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 483 "lab9.y" /* yacc.c:1646  */
    {	(yyval.astnode) = ASTCreateNode(A_CONSTANT_STRING);
             	(yyval.astnode)->name = (yyvsp[0].string);
	     		(yyval.astnode)->A_Declared_Type = A_Decaf_STRING;
            }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 490 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 493 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 495 "lab9.y" /* yacc.c:1646  */
    {
		    if ((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type)
			{ yyerror("both sides need to be of the same type");
			  exit(1);
			}

		    (yyval.astnode) = ASTCreateNode(A_EXPR);
                    (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                    (yyval.astnode)->operator = (yyvsp[-1].operator);
		    (yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
                    (yyval.astnode)->S2 = (yyvsp[0].astnode);
		    (yyval.astnode)->name = TEMP_CREATE();
                    (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		    OFFSET++;
                   }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 512 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LEQ;}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 513 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LT;}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 514 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GT;}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 515 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GEQ;}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 516 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_EQ;}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 517 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_NEQ;}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 520 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 522 "lab9.y" /* yacc.c:1646  */
    { // if the two parts are not integers, exit with error
		      if ( ((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type) || ((yyvsp[-2].astnode)->A_Declared_Type != A_Decaf_INT)) {
			yyerror("addition and subtraction only allowed for integers");
		        exit(1);
		     }
		
		      (yyval.astnode) = ASTCreateNode(A_EXPR);
                      (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                      (yyval.astnode)->operator = (yyvsp[-1].operator);
                      (yyval.astnode)->S2 = (yyvsp[0].astnode);
		      (yyval.astnode)->A_Declared_Type;
		      (yyval.astnode)->name = TEMP_CREATE();
                      (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		      OFFSET++;
                     }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 539 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_PLUS;}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 540 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MINUS;}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 543 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 545 "lab9.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type)
	{ yyerror("type mismatch");
	  exit(1);
        } 
        // if booleans are used in integer expression, exit with error
	if ((yyvsp[-2].astnode)->A_Declared_Type == A_Decaf_BOOL) {
		if (((yyvsp[-1].operator) == A_TIMES) || ((yyvsp[-1].operator) == A_DIVIDE) || ((yyvsp[-1].operator) == A_MOD)) {
			yyerror("cannot use boolean in arithmetic operation");
			exit(1);
		}
	}
	// if integeres are used in a boolean expression, exit with error
	if ((yyvsp[-2].astnode)->A_Declared_Type == A_Decaf_INT) {
		if (((yyvsp[-1].operator) == A_AND) || ((yyvsp[-1].operator) == A_OR) || ((yyvsp[-1].operator) == A_LEFTSHIFT) || ((yyvsp[-1].operator) == A_RIGHTSHIFT)) {
			yyerror("cannot use integer in boolean operation");
			exit(1);
		}
	}

	(yyval.astnode) = ASTCreateNode(A_EXPR);
        (yyval.astnode)->S1 = (yyvsp[-2].astnode);
        (yyval.astnode)->operator = (yyvsp[-1].operator);
        (yyval.astnode)->S2 = (yyvsp[0].astnode);
	(yyval.astnode)->A_Declared_Type = (yyvsp[-2].astnode)->A_Declared_Type;
	(yyval.astnode)->name = TEMP_CREATE();
        (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	OFFSET++;
       }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 576 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_TIMES;}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 577 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_DIVIDE;}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 578 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MOD;}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 579 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_AND;}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 580 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_OR;}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 581 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LEFTSHIFT;}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 582 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_RIGHTSHIFT;}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 586 "lab9.y" /* yacc.c:1646  */
    {	
	  struct SymbTab *p;
	  p = Search((yyvsp[0].string), LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on RVALUE not defined");
	       yyerror((yyvsp[0].string));
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Scalar)
	     { yyerror((yyvsp[0].string));
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }
	
	   (yyval.astnode) = ASTCreateNode(A_VAR_RVALUE);
           (yyval.astnode)->name = (yyvsp[0].string);
	   (yyval.astnode)->symbol = p;
	   (yyval.astnode)->A_Declared_Type = p->Type;
          }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 605 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 607 "lab9.y" /* yacc.c:1646  */
    {
	  struct SymbTab *p;
	  p = Search((yyvsp[-3].string), LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on RVALUE not defined");
	       yyerror((yyvsp[-3].string));
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Array)
	     { yyerror((yyvsp[-3].string));
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }

	   (yyval.astnode) = ASTCreateNode(A_VAR_RVALUE);
           (yyval.astnode)->name = (yyvsp[-3].string);
           (yyval.astnode)->S1 = (yyvsp[-1].astnode);
	   (yyval.astnode)->symbol = p;
	   (yyval.astnode)->A_Declared_Type = p->Type;
          }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 627 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 628 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 630 "lab9.y" /* yacc.c:1646  */
    {
	  if ((yyvsp[0].astnode)->A_Declared_Type != A_Decaf_BOOL)
		{ yyerror("type mismatch, expecting a boolean");
		  exit(1);
		}

	  	(yyval.astnode) = ASTCreateNode(A_EXPR);
        (yyval.astnode)->operator = A_NOT;
      	(yyval.astnode)->S1 = (yyvsp[0].astnode);
	  	(yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
	  	(yyval.astnode)->name = TEMP_CREATE();
  	 	(yyval.astnode)->symbol = Insert((yyval.astnode)->name, A_Decaf_BOOL, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	 	OFFSET++;
    	}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 645 "lab9.y" /* yacc.c:1646  */
    {// if factor is not an integer, exit with error
	  		if ((yyvsp[0].astnode)->A_Declared_Type != A_Decaf_INT)
			{
		 		yyerror("type mismatch, expecting an integer");
		 		exit(1);
			}

	  		(yyval.astnode) = ASTCreateNode(A_EXPR);
        	(yyval.astnode)->operator = A_UMINUS;
        	(yyval.astnode)->S1 = (yyvsp[0].astnode);
	  		(yyval.astnode)->A_Declared_Type = A_Decaf_INT;
        	(yyval.astnode)->name = TEMP_CREATE();
	  		(yyval.astnode)->symbol = Insert((yyval.astnode)->name, A_Decaf_INT, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	  		OFFSET++;
        }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 663 "lab9.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_STRING;}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 667 "lab9.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_INT;}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 668 "lab9.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_BOOL;}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 671 "lab9.y" /* yacc.c:1646  */
    {(yyval.asttype) = A_Decaf_VOID;}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 672 "lab9.y" /* yacc.c:1646  */
    {(yyval.asttype) = (yyvsp[0].asttype);}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 676 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_CONSTANT_BOOL);
                (yyval.astnode)->value = 1;
		(yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
               }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 681 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_CONSTANT_BOOL);
                (yyval.astnode)->value = 0;
		(yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
               }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 688 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_ARRAYTYPE);
              (yyval.astnode)->value = (yyvsp[-2].value);
              (yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
             }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 695 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_CONSTANT_INT);
            (yyval.astnode)->value = (yyvsp[0].value);
	    	(yyval.astnode)->A_Declared_Type = A_Decaf_INT;
           }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 700 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2398 "y.tab.c" /* yacc.c:1646  */
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
#line 703 "lab9.y" /* yacc.c:1906  */
	/* end of rules, start of program */

// added explicit type return to clear warning
int main(int argc, char* argv[])
{ 
	// create filename variable
	char* filename = (char *) malloc(100);
	char default_name = 'a';
	strncat(filename, &default_name, 1);

    // parse arguments
    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0)
            debugsw = 1;
        if (strcmp(argv[i], "-o") == 0) {
            if (argv[i+1] == NULL) {
                printf("-o flag must be followed by a filename.\n");
                exit(1);
            }
            
            filename = argv[i+1];
        }
    }
	
	// append filename with .s suffix
	strcpy(filename_final, filename);
	char period = '.';
	char extension = 's';
	strncat(filename_final, &period, 1);
	strncat(filename_final, &extension, 1);

    yyparse();

	if (debugsw == 1) {
    	Display();
    	printf("Parsing complete!\n");
    	ASTprint(0,PROGRAM);
    	printf("\nDone printing.\n");
	}

	fp = fopen(filename_final, "w");
	
	emit_gas(fp);

    return 0;
}
