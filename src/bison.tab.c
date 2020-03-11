/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "test.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "Struct.h"
  struct Word // 单词表结构体: 单词名字、标识类型、状态、序号、行号、连接符号表指针、连接下一结点指针
{
	char name[20];
	char mark_name;
	int state;
	int num;
	int line;
	struct Sign* link;
	struct Word* next;
};
  extern int yylex (void);
  void yyerror (char const *s);
  int insertVar(char *scope, char *name, char type);
  int insertFunc(char *name, struct Var *argHead, char *rType, int start);
  void callVar(char *name, char *funcName);
  void varMatch();
  void callFunc(char *name);
  void init();


  struct L* makelist(int quad);
  struct L* merge(struct L* p1, struct L* p2);
  void backpatch(struct L* list, int quad);
  int lex(FILE* fp);
  int emit(char *type, char *arg1, char *arg2, char *res);
  char *newTemp();
  int isFunc(int i);
  void myPrint(struct Word* w_look);
 struct Var* gHead = NULL;
 struct Function* fHead = NULL;
 struct L* lHead;
 struct Word* head;
 extern struct Stack stack;
 extern struct Queue queue;

 extern struct FunOut funOut[100];
 int funNum = 0;
 int mainNum = 0;
 int inC = 0;
 int eip = 100;
 int start = 0;
 int end = 0;
 int tempNum = 0;
 int j = 0;
 int TEMP[1000];
  char funcName[200] = "\0";
  char buffer1[200];
  char buffer2[200];
  char buffer3[200];
  char buffer4[200];

#line 124 "test.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "test.tab.h".  */
#ifndef YY_YY_TEST_TAB_H_INCLUDED
# define YY_YY_TEST_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LE = 258,
    GE = 259,
    EQ = 260,
    NE = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    INT = 268,
    VOID = 269,
    RETURN = 270,
    NUM = 271,
    ID = 272,
    NEG = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 61 "test.y" /* yacc.c:355  */

    struct L{
    int k;
    char op[20];
    char op1[20];
    char op2[20];
    char res[30];
    struct L *next;
    struct L *true;
    struct L *false;
    };

    struct Var *var;
    struct L  l;
    double value;
    char strval[2000];
    int subtok;
    int quad;

#line 203 "test.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TEST_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "test.tab.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    22,     2,     2,
      30,    31,    20,    19,    27,    18,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      34,    23,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   117,   118,   121,   122,   125,   128,   136,
     144,   152,   169,   170,   173,   173,   192,   193,   194,   199,
     207,   210,   218,   228,   231,   232,   241,   242,   246,   257,
     258,   259,   260,   263,   274,   278,   289,   292,   292,   292,
     302,   305,   311,   311,   311,   319,   319,   319,   334,   338,
     346,   358,   370,   371,   381,   390,   397,   404,   409,   414,
     430,   431,   432,   433,   434,   435,   438,   450,   451,   454,
     455,   458,   463,   466,   467,   470,   471,   472,   473,   476,
     490,   491,   494,   497
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"",
  "\"&&\"", "\"||\"", "\"!\"", "IF", "ELSE", "WHILE", "INT", "VOID",
  "RETURN", "NUM", "ID", "'-'", "'+'", "'*'", "'/'", "'%'", "'='", "NEG",
  "'^'", "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "'<'",
  "'>'", "$accept", "program", "declaration-list", "declaration",
  "var-declaration", "var-list", "type-specifier", "fun-declaration",
  "$@1", "params", "param-list", "param", "compound-stmt",
  "local-declarations", "statement-list", "statement", "expression-stmt",
  "c-statement", "selection-stmt", "$@2", "$@3", "M", "N", "$@4", "$@5",
  "iteration-stmt", "$@6", "$@7", "return-stmt", "expression", "var",
  "simple-expression", "relop", "additive-expression", "addop", "term",
  "mulop", "factor", "call", "args", "arg-list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    45,    43,
      42,    47,    37,    61,   273,    94,    59,    44,    91,    93,
      40,    41,   123,   125,    60,    62
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -62,   -62,    29,     6,   -62,   -62,    -3,   -62,   -62,
     -62,   -27,    24,     0,   -62,   -62,    22,    -5,    40,    17,
     -62,    42,    30,    44,    28,   -62,    70,    59,    56,     6,
      62,    64,   -62,   -62,   -62,   -62,   -62,     6,   -62,    82,
      68,    74,    16,    14,   -62,   -15,   -62,    16,   -62,   -62,
     -62,   -62,   -62,    93,    94,   -62,    95,   -62,    79,    96,
      52,     3,    50,   -62,   -62,   -62,    52,   -62,    91,    16,
      16,    87,     4,    92,   100,   104,   -62,    16,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    26,    26,
     -62,   -62,    26,   -62,   106,   -62,   105,    97,   -62,   -62,
      16,    16,   -62,   -62,    16,    16,    16,    63,    50,   -62,
     -62,   -62,    16,   107,   109,    16,    52,    52,   -62,   -62,
     -62,   113,   -62,   -62,   -62,    99,   111,   -62,   -62,   -62,
     -62,   -62,   111,    80,   131,   -62,   -62,   -62,   -62,    99,
     -62,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,     0,     2,     4,     5,     0,     6,     1,
       3,    10,     0,     0,    14,     7,     0,     0,    18,     8,
      11,    13,     0,     0,    16,    20,     0,    21,     0,     0,
       0,     0,    24,    15,    19,     9,    22,    26,    25,     0,
      68,    10,    68,    68,    78,    52,    34,    68,    23,    29,
      27,    28,    30,     0,     0,    31,     0,    32,     0,    76,
      51,    59,    67,    72,    77,    76,    57,    48,     0,    68,
      68,     0,     0,     0,     0,     0,    33,    68,    40,    40,
      60,    63,    64,    65,    70,    69,    61,    62,    68,     0,
      73,    74,     0,    49,     0,    83,     0,    81,    75,    58,
      68,    68,    40,    50,    68,    68,    68,    54,    66,    71,
      53,    79,    68,     0,     0,    68,    56,    55,    82,    38,
      43,     0,    40,    40,    46,    68,    68,    40,    24,    35,
      41,    44,    68,    68,     0,    40,    36,    40,    47,    68,
      40,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   141,   110,   -62,    -1,   -62,   -62,   -62,
     -62,   119,   121,   -62,    23,     7,   -62,    11,   -62,   -62,
     -62,   -61,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -43,
     -40,   -37,   -62,    65,   -62,    66,   -62,    60,   -62,   -62,
     -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    12,     7,     8,    18,    23,
      24,    25,    49,    37,    40,    50,    51,   130,    52,    53,
     122,   104,   134,    54,   123,    55,    56,   127,    57,    58,
      59,    60,    88,    61,    89,    62,    92,    63,    64,    96,
      97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    13,    65,    14,    71,    66,    80,    81,    82,    83,
      72,    78,    79,    69,    11,    70,    17,    22,   105,     1,
       2,    84,    85,    42,    20,    42,    94,    95,    22,     9,
      44,    45,    44,    45,   103,    99,    39,    86,    87,    19,
      67,   115,    44,    45,    47,    26,    47,    27,    65,    65,
      15,    16,    65,     1,    21,    29,   106,   113,   114,    78,
      79,   125,   126,    71,    65,    65,   132,   116,   117,   118,
      90,    91,   121,   -17,   138,    28,   139,    42,   -37,   141,
     -45,    84,    85,    43,    44,    45,    30,    31,    32,    42,
     -37,    35,   -45,    36,    46,    43,    44,    45,    47,    41,
      32,    48,    13,    73,    74,    76,    46,    75,    42,   -37,
      47,   -45,    32,   136,    43,    44,    45,    93,    98,    77,
      42,   -37,   100,   -45,   112,    46,    43,    44,    45,    47,
     101,   128,   129,   131,   102,   110,   111,    46,   119,   135,
     120,    47,   137,    32,   124,    10,   129,    38,    34,    33,
     140,   133,   109,   107,     0,   108
};

static const yytype_int16 yycheck[] =
{
      43,    28,    42,    30,    47,    42,     3,     4,     5,     6,
      47,     7,     8,    28,    17,    30,    16,    18,    79,    13,
      14,    18,    19,     9,    29,     9,    69,    70,    29,     0,
      16,    17,    16,    17,    77,    31,    37,    34,    35,    17,
      26,   102,    16,    17,    30,    28,    30,    17,    88,    89,
      26,    27,    92,    13,    14,    27,    30,   100,   101,     7,
       8,   122,   123,   106,   104,   105,   127,   104,   105,   112,
      20,    21,   115,    31,   135,    31,   137,     9,    10,   140,
      12,    18,    19,    15,    16,    17,    16,    28,    32,     9,
      10,    29,    12,    29,    26,    15,    16,    17,    30,    17,
      32,    33,    28,    10,    10,    26,    26,    12,     9,    10,
      30,    12,    32,    33,    15,    16,    17,    26,    31,    23,
       9,    10,    30,    12,    27,    26,    15,    16,    17,    30,
      30,    32,   125,   126,    30,    29,    31,    26,    31,   132,
      31,    30,    11,    32,    31,     4,   139,    37,    29,    28,
     139,   128,    92,    88,    -1,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    37,    38,    39,    40,    42,    43,     0,
      39,    17,    41,    28,    30,    26,    27,    16,    44,    17,
      29,    14,    42,    45,    46,    47,    28,    17,    31,    27,
      16,    28,    32,    48,    47,    29,    29,    49,    40,    42,
      50,    17,     9,    15,    16,    17,    26,    30,    33,    48,
      51,    52,    54,    55,    59,    61,    62,    64,    65,    66,
      67,    69,    71,    73,    74,    66,    67,    26,    65,    28,
      30,    65,    67,    10,    10,    12,    26,    23,     7,     8,
       3,     4,     5,     6,    18,    19,    34,    35,    68,    70,
      20,    21,    72,    26,    65,    65,    75,    76,    31,    31,
      30,    30,    30,    65,    57,    57,    30,    69,    71,    73,
      29,    31,    27,    65,    65,    57,    67,    67,    65,    31,
      31,    65,    56,    60,    31,    57,    57,    63,    32,    51,
      53,    51,    57,    50,    58,    51,    33,    11,    57,    57,
      53,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      41,    41,    42,    42,    44,    43,    45,    45,    45,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    53,    53,    55,    56,    54,
      57,    58,    59,    60,    54,    62,    63,    61,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    74,
      75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     6,
       1,     4,     1,     1,     0,     7,     1,     1,     0,     3,
       1,     2,     4,     4,     0,     2,     0,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     0,     0,    13,
       0,     0,     0,     0,     8,     0,     0,    10,     2,     3,
       3,     1,     1,     4,     3,     4,     4,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       0,     1,     3,     1
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
#line 114 "test.y" /* yacc.c:1646  */
    {printf("*******************************this is a program\n");}
#line 1383 "test.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 128 "test.y" /* yacc.c:1646  */
    {
                if(funcName[0] !='\0' ) {
                strcpy((yyval.strval), funcName);
            } else {
                strcpy((yyval.strval), "global");
            }
            insertVar((yyval.strval), (yyvsp[0].strval), 'b');
        }
#line 1396 "test.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "test.y" /* yacc.c:1646  */
    {
            if(funcName[0] !='\0' ) {
                strcpy((yyval.strval), funcName);
            } else {
                strcpy((yyval.strval), "global");
            }
            insertVar((yyval.strval), (yyvsp[-3].strval), 'a');
        }
#line 1409 "test.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "test.y" /* yacc.c:1646  */
    {
                if(funcName[0] !='\0' ) {
                    strcpy((yyval.strval), funcName);
                } else {
                    strcpy((yyval.strval), "global");
                }
                insertVar((yyval.strval), (yyvsp[0].strval), 'b');
            }
#line 1422 "test.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "test.y" /* yacc.c:1646  */
    {
                        if(funcName[0] !='\0' ) {
                            strcpy((yyval.strval), funcName);
                        } else {
                            strcpy((yyval.strval), "global");
                        }
                        insertVar((yyval.strval), (yyvsp[-3].strval), 'a');
                    }
#line 1435 "test.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 169 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval),"INT"); }
#line 1441 "test.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 170 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval),"VOID"); }
#line 1447 "test.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "test.y" /* yacc.c:1646  */
    {
                    funOut[funNum].lines = eip;
                    strcpy(funOut[funNum++].name, (yyvsp[-1].strval));
                    strcpy(funcName, (yyvsp[-1].strval));
                    if(!strcmp("main", funcName)) {
                        mainNum = eip;
                    }
                    start = eip;
                    }
#line 1461 "test.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "test.y" /* yacc.c:1646  */
    {
                end = eip;
                /* insertFunc */
                insertFunc((yyvsp[-5].strval), (yyvsp[-2].var), (yyvsp[-6].strval), start);
                struct Var* temp = (yyvsp[-2].var);
                memset(funcName, 0, sizeof(funcName));
                //insertFunc()
             }
#line 1474 "test.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 192 "test.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1480 "test.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 193 "test.y" /* yacc.c:1646  */
    {(yyval.var)=NULL;}
#line 1486 "test.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "test.y" /* yacc.c:1646  */
    {(yyval.var)=NULL;}
#line 1492 "test.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 199 "test.y" /* yacc.c:1646  */
    {
            (yyval.var) = (yyvsp[-2].var);
            struct Var* temp = (yyval.var);
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = (yyvsp[0].var);
        }
#line 1505 "test.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "test.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1511 "test.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 210 "test.y" /* yacc.c:1646  */
    {
            (yyval.var) = (struct Var*)malloc(sizeof(struct Var));
            strcpy((yyval.var)->scope, funcName);
            strcpy((yyval.var)->name, (yyvsp[0].strval));
            (yyval.var)->type = 'b';
            (yyval.var)->next = NULL;
            insertVar(funcName, (yyvsp[0].strval), 'b');
        }
#line 1524 "test.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 218 "test.y" /* yacc.c:1646  */
    {
            (yyval.var) = (struct Var*)malloc(sizeof(struct Var));
            strcpy((yyval.var)->scope, funcName);
            strcpy((yyval.var)->name, (yyvsp[-2].strval));
            (yyval.var)->type = 'a';
            (yyval.var)->next = NULL;
            insertVar(funcName, (yyvsp[-2].strval), 'a');
        }
#line 1537 "test.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 232 "test.y" /* yacc.c:1646  */
    {
                if(funcName[0] !='\0' ) {
                    strcpy((yyvsp[0].strval), funcName);
                } else {
                    strcpy((yyvsp[0].strval), "global");
                }
            }
#line 1549 "test.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 246 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).k = (yyvsp[0].l).k;
                strcpy((yyval.l).op, (yyvsp[0].l).op);
                strcpy((yyval.l).op1, (yyvsp[0].l).op1);
                strcpy((yyval.l).op2, (yyvsp[0].l).op2);
                strcpy((yyval.l).res, (yyvsp[0].l).res);
                (yyval.l).next = (yyvsp[0].l).next;
                (yyval.l).true = (yyvsp[0].l).true;
                (yyval.l).false = (yyvsp[0].l).false;
                 ;
        }
#line 1565 "test.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 263 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).k = (yyvsp[-1].l).k;
                strcpy((yyval.l).op, (yyvsp[-1].l).op);
                strcpy((yyval.l).op1, (yyvsp[-1].l).op1);
                strcpy((yyval.l).op2, (yyvsp[-1].l).op2);
                strcpy((yyval.l).res, (yyvsp[-1].l).res);
                (yyval.l).next = (yyvsp[-1].l).next;
                (yyval.l).true = (yyvsp[-1].l).true;
                (yyval.l).false = (yyvsp[-1].l).false;
                 ;
        }
#line 1581 "test.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 278 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).k = (yyvsp[0].l).k;
                strcpy((yyval.l).op, (yyvsp[0].l).op);
                strcpy((yyval.l).op1, (yyvsp[0].l).op1);
                strcpy((yyval.l).op2, (yyvsp[0].l).op2);
                strcpy((yyval.l).res, (yyvsp[0].l).res);
                (yyval.l).next = (yyvsp[0].l).next;
                (yyval.l).true = (yyvsp[0].l).true;
                (yyval.l).false = (yyvsp[0].l).false;
                 ;
            }
#line 1597 "test.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 292 "test.y" /* yacc.c:1646  */
    {inC=1;}
#line 1603 "test.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 292 "test.y" /* yacc.c:1646  */
    {inC=0;}
#line 1609 "test.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 292 "test.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-9].l).true, (yyvsp[-6].quad));
                backpatch((yyvsp[-9].l).false, (yyvsp[-2].quad));
                backpatch((yyvsp[-4].l).next, (yyvsp[0].quad));
                (yyval.l).next = merge((yyvsp[-5].l).next, (yyvsp[-4].l).next);
                (yyval.l).next = merge((yyval.l).next, (yyvsp[-1].l).next);
            }
#line 1621 "test.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 302 "test.y" /* yacc.c:1646  */
    {(yyval.quad) = eip;}
#line 1627 "test.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 305 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).next = makelist(eip);
                emit("j","-", "-", "-");
                }
#line 1636 "test.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 311 "test.y" /* yacc.c:1646  */
    {inC = 1;}
#line 1642 "test.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 311 "test.y" /* yacc.c:1646  */
    {inC = 0;}
#line 1648 "test.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 311 "test.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-4].l).true, (yyvsp[-1].quad));
                (yyval.l).next = merge((yyvsp[-4].l).false, (yyvsp[0].l).next);
            }
#line 1657 "test.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 319 "test.y" /* yacc.c:1646  */
    {inC = 1;}
#line 1663 "test.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 319 "test.y" /* yacc.c:1646  */
    {inC = 0;}
#line 1669 "test.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "test.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-1].l).next, (yyvsp[-6].quad));
                backpatch((yyvsp[-5].l).true, (yyvsp[-2].quad));
                (yyval.l).next = (yyvsp[-5].l).false;
                itoa((yyvsp[-6].quad), buffer1, 10);
                emit("j", "-", "-", buffer1);
                backpatch((yyvsp[-5].l).false, (yyvsp[0].quad)+1);
                memset(buffer1, 0, sizeof(buffer1));
            }
#line 1683 "test.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "test.y" /* yacc.c:1646  */
    { 
            emit("ret", "-", "-", "None");
            emit("pop", "-", "-", "eip");
            }
#line 1692 "test.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 338 "test.y" /* yacc.c:1646  */
    {
            emit("=", (yyvsp[-1].l).res, "-", "eax");
            emit("ret", "-", "-", "eax");
            emit("pop", "-", "-", "eip");
            //stack.val[top--];
            }
#line 1703 "test.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 346 "test.y" /* yacc.c:1646  */
    {
                callVar((yyvsp[-2].strval), funcName);
                (yyval.l).k = (yyvsp[0].l).k;
                strcpy((yyval.l).op, "=");
                strcpy((yyval.l).op1, (yyvsp[0].l).res);
                strcpy((yyval.l).op2, "-");
                strcpy((yyval.l).res, (yyvsp[-2].strval));
                (yyval.l).next = (yyvsp[0].l).next;
                (yyval.l).true = (yyvsp[0].l).true;
                (yyval.l).false = (yyvsp[0].l).false;
                emit("=", (yyvsp[0].l).res, "-",(yyvsp[-2].strval));
                }
#line 1720 "test.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 358 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).k = (yyvsp[0].l).k;
                strcpy((yyval.l).op, (yyvsp[0].l).op);
                strcpy((yyval.l).op1, (yyvsp[0].l).op1);
                strcpy((yyval.l).op2, (yyvsp[0].l).op2);
                strcpy((yyval.l).res, (yyvsp[0].l).res);
                (yyval.l).next = (yyvsp[0].l).next;
                (yyval.l).true = (yyvsp[0].l).true;
                (yyval.l).false = (yyvsp[0].l).false;
                }
#line 1735 "test.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 370 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), (yyvsp[0].strval)); }
#line 1741 "test.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 371 "test.y" /* yacc.c:1646  */
    {
            strcpy(buffer3, (yyvsp[-3].strval));
            strcat(buffer3, "[");
            strcat(buffer3, (yyvsp[-1].l).res);
            strcat(buffer3, "]");
            strcpy((yyval.strval), buffer3);
            memset(buffer3, 0, sizeof(buffer3));
        }
#line 1754 "test.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 381 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).true = makelist(eip);
                (yyval.l).false = makelist(eip+1);
                buffer1[0] = 'j';
                strcat(buffer1, (yyvsp[-1].strval));
                emit(buffer1, (yyvsp[-2].strval), (yyvsp[0].strval), "0");
                memset(buffer1, 0, sizeof(buffer1));
                emit("j", "-", "-", "0");
            }
#line 1768 "test.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 390 "test.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-3].l).false, (yyvsp[-1].quad));
                (yyval.l).true = merge((yyvsp[-3].l).true, (yyvsp[0].l).true);
                (yyval.l).false = (yyvsp[0].l).false;
                strcpy((yyval.l).res, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
            }
#line 1780 "test.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 397 "test.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-3].l).true, (yyvsp[-1].quad));
                (yyval.l).false = merge((yyvsp[-3].l).false, (yyvsp[0].l).false);
                (yyval.l).true = (yyvsp[0].l).true;
                strcpy((yyval.l).res, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
            }
#line 1792 "test.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 404 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).true = (yyvsp[0].l).false;
                (yyval.l).false = (yyvsp[0].l).true;
                strcpy((yyval.l).res, (yyvsp[0].l).res);
            }
#line 1802 "test.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 409 "test.y" /* yacc.c:1646  */
    {
                (yyval.l).true = (yyvsp[-1].l).true;
                (yyval.l).false = (yyvsp[-1].l).false;
                strcpy((yyval.l).res, (yyvsp[-1].l).res);
        }
#line 1812 "test.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 414 "test.y" /* yacc.c:1646  */
    {
                if(inC == 1) {
                        (yyval.l).true = makelist(eip);
                        (yyval.l).false = makelist(eip+1);
                        strcpy((yyval.l).res, (yyvsp[0].strval));
                        emit("jnz", (yyvsp[0].strval), "-", "0");
                        emit("j", "-", "-", "0");
                } else {
                        strcpy((yyval.l).res, newTemp());
                        memset(buffer2, 0, sizeof(buffer2));
                        emit("=", (yyvsp[0].strval), "-", (yyval.l).res);
                }
            }
#line 1830 "test.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 430 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "<=");}
#line 1836 "test.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 431 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "<"); }
#line 1842 "test.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 432 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), ">"); }
#line 1848 "test.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 433 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), ">="); }
#line 1854 "test.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 434 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "==");}
#line 1860 "test.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 435 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "!="); }
#line 1866 "test.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 438 "test.y" /* yacc.c:1646  */
    {
            if (!strcmp((yyvsp[-2].strval), "empty"))
            {
                strcpy((yyval.strval), newTemp());
                memset(buffer2, 0, sizeof(buffer2));
                emit((yyvsp[-1].strval), "0", (yyvsp[0].strval), (yyval.strval));
            } else {
                strcpy((yyval.strval), newTemp());
                memset(buffer2, 0, sizeof(buffer2));
                emit((yyvsp[-1].strval), (yyvsp[-2].strval), (yyvsp[0].strval), (yyval.strval));
            }
        }
#line 1883 "test.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 450 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval),(yyvsp[0].strval)); }
#line 1889 "test.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 451 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "empty");}
#line 1895 "test.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 454 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "+"); }
#line 1901 "test.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 455 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "-"); }
#line 1907 "test.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 458 "test.y" /* yacc.c:1646  */
    {
            strcpy((yyval.strval), newTemp());
            emit((yyvsp[-1].strval), (yyvsp[-2].strval), (yyvsp[0].strval), (yyval.strval));
            memset(buffer2, 0, sizeof(buffer1));
        }
#line 1917 "test.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 463 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval),(yyvsp[0].strval));}
#line 1923 "test.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 466 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "*"); }
#line 1929 "test.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 467 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), "/"); }
#line 1935 "test.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 470 "test.y" /* yacc.c:1646  */
    { strcpy((yyval.strval),(yyvsp[-1].l).res); }
#line 1941 "test.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 471 "test.y" /* yacc.c:1646  */
    {callVar((yyvsp[0].strval), funcName);strcpy((yyval.strval), (yyvsp[0].strval));}
#line 1947 "test.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 472 "test.y" /* yacc.c:1646  */
    {callFunc((yyvsp[0].strval));queue.end=0; strcpy((yyval.strval), "eax");}
#line 1953 "test.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 473 "test.y" /* yacc.c:1646  */
    {strcpy((yyval.strval), (yyvsp[0].strval)); }
#line 1959 "test.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 476 "test.y" /* yacc.c:1646  */
    {
                strcpy((yyval.strval), (yyvsp[-3].strval));
                int i = queue.front;
                for(; i < queue.end; i++) {
                    emit("par", "-", "-", queue.val[i]);
                }
                emit("push", "-", "-", "eip+1");
                //queue.end = 0;
                //printf("eip+1 is %d\n", eip+1);
                //stack.val[stack.top++] = (eip+1);
                emit("call", "-", "-", (yyvsp[-3].strval));
            }
#line 1976 "test.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 494 "test.y" /* yacc.c:1646  */
    {
                 queue.val[queue.end++] = (yyvsp[0].l).res; 
                 }
#line 1984 "test.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 497 "test.y" /* yacc.c:1646  */
    {
            queue.front = queue.end = 0;
            queue.val[queue.end++] = (yyvsp[0].l).res;
            }
#line 1993 "test.tab.c" /* yacc.c:1646  */
    break;


#line 1997 "test.tab.c" /* yacc.c:1646  */
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
#line 503 "test.y" /* yacc.c:1906  */

void yyerror (char const *s) {
    fprintf (stderr, "%s/n", s);
}

int insertVar(char *scope, char *name, char type) {
    struct Var* temp = gHead;
    struct Var* t2 = temp;
    while(temp) {
        if(!strcmp(temp->name, name)){
            if(!strcmp(temp->scope, scope)) {
                printf(" \'%s\' Redefinition error\n", name);
                return 0;
            }
        }
        t2 = temp;
        temp = temp->next;
    }
    struct Var* newVar = (struct Var*)malloc(sizeof(struct Var));
    strcpy(newVar->scope, scope);
    strcpy(newVar->name, name);
    newVar->type = type;
    newVar->next = NULL;
    if(gHead == NULL) {
        gHead = newVar;
    } else {
        t2->next = newVar;
    }
    return 1;
}


void init() {
    lHead = (struct L*)malloc(200 * sizeof(struct L));
    int i;
    for(i = 100; i < 200; i++) {
        lHead[i].k = 0;
        memset(lHead[i].op, 0, sizeof(lHead[i].op));
        memset(lHead[i].op1, 0, sizeof(lHead[i].op1));
        memset(lHead[i].op2, 0, sizeof(lHead[i].op2));
        memset(lHead[i].res, 0, sizeof(lHead[i].res));
        lHead[i].next = NULL;
        lHead[i].true = NULL;
        lHead[i].false = NULL;
    }
}

struct L* makelist(int quad) {

    return &lHead[quad];
}

struct L* merge(struct L* p1, struct L* p2) {
    struct L* temp = p1;
    if(p1 == NULL) {
        return p2;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p2;
     ;
    return p1;
}


void backpatch(struct L* list, int quad) {
    struct L* temp = list;
    itoa(quad, buffer1, 10);
    while(temp) {
        strcpy(temp->res, buffer1);
        temp = temp->next;
    }
    memset(buffer1, 0, sizeof(buffer1));
}


int emit(char *type, char *arg1, char *arg2, char *res) {
    printf("%d:\t (%s, %s, %s, %s)\n", eip, type, arg1, arg2, res);
    strcpy(lHead[eip].op, type);
    strcpy(lHead[eip].op1, arg1);
    strcpy(lHead[eip].op2, arg2);
    strcpy(lHead[eip].res, res);
    eip++;
    return 1;
}

char *newTemp() {
    buffer2[0] = 'T';
    itoa(tempNum, buffer1, 10);
    strcat(buffer2, buffer1);
    tempNum++;
    memset(buffer1, 0, sizeof(buffer1));
    return buffer2;
}

int isFunc(int i) { //判断第i行第i个四元式是否是某个函数的开始位置
    for(j = 0; j < funNum; j++) {
        if(i == funOut[j].lines)
            return 1;
    }
    return 0;
}


void myPrint(struct Word* w_look) {
	printf("\n===================Lex Result===================\n");
	w_look = head;
	printf("WordNumber     WordLine       WordName       WordMark\n");
	while (w_look) {
        printf(" %d\t\t%d\t\t%s\t\t%c\n", w_look->num, w_look->line, w_look->name, w_look->mark_name);
		w_look = w_look->next;
	}
}

int insertFunc(char *name, struct Var *argHead, char *rType, int start) {
    struct Function* temp = fHead;
    struct Function* t2 = temp;
    while(temp) {
        if(!strcmp(temp->name, name)){
            printf(" \'%s\' Redefinition error\n", name);
            return 0;
        }
        t2 = temp;
        temp = temp->next;
    }
    struct Function* newVar = (struct Function*)malloc(sizeof(struct Function));
    strcpy(newVar->name, name);
    newVar->argHead = argHead;
    strcpy(newVar->rType,rType);
    newVar->qStartLabel = start;
    newVar->next = NULL;
    if(fHead == NULL) {
        fHead = newVar;
    } else {
        t2->next = newVar;
    }
    return 1;
}

void callVar(char *name, char *funcName) {
    struct Var* temp = gHead;
    while(temp) {
        if(!strcmp(name, temp->name)) {
            return;
        }
        temp = temp->next;
    }
    printf("Var %s isn't difined.\n", name);
}

void callFunc(char *name) {
    struct Function* temp = fHead;
    while(temp) {
        if(!strcmp(name, temp->name)) {
            int num = 0;
            struct Var* t2 = temp->argHead;
            while(t2) {
                num++;
                t2=t2->next;
            }
            if(num == queue.end) {
                return;
            } else {
                printf("arguement number's isn't matched\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("%s function isn't defined!\n", name);
}

int main(int argc, const char *args[]) {
     //   yydebug = 1;
    //static struct L lHead[1000];
     init();
    extern FILE *yyin;
    char document[50] = "li.txt";
	if(argc > 1 && (yyin = fopen(document, "rt")) == NULL) {
		fprintf(stderr, "can not open %s\n", args[1]);
		exit(1);
	}
	if(yyparse()) {
		exit(-1);
	}
    myPrint(head);
    int i = 100;
    for(i = 100; i < eip; i++) {
        if(i == mainNum) {
            printf("Program Begin at :\n");
        } else if(isFunc(i)) {
            printf("%s Begin at :\n", funOut[j].name);
        }
        printf("\t %d:\t (%s, %s, %s, %s)\n", i, lHead[i].op, lHead[i].op1, lHead[i].op2, lHead[i].res);
    }
    printf("\t %d:\t \n", eip);

    while(gHead) {
        printf("%s\t%s\t%c\n", gHead->scope, gHead->name, gHead->type);
        gHead = gHead->next;
    }
    printf("******************************\n");
    while(fHead) {
        printf("%s\t%s\t\n", fHead->name, fHead->rType);
        while(fHead->argHead) {
            printf("name is %s    scope is %s   type is %c\n", fHead->argHead->name, fHead->argHead->scope, fHead->argHead->type);
            fHead->argHead = fHead->argHead->next;
        }
        fHead = fHead->next;
    }
    return 0;
}
