/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TINTEGER = 258,
     TIDENTITY = 259,
     TINT = 260,
     TVOID = 261,
     TCONST = 262,
     TWHILE = 263,
     TFOR = 264,
     TIF = 265,
     TSWITCH = 266,
     TCONTINUE = 267,
     TBREAK = 268,
     TRETURN = 269,
     TCASE = 270,
     TDEFAULT = 271,
     TINC = 272,
     TDEC = 273,
     TADDASSIGN = 274,
     TSUBASSIGN = 275,
     TMULASSIGN = 276,
     TMODASSIGN = 277,
     TDIVASSIGN = 278,
     TOR = 279,
     TAND = 280,
     TIFX = 281,
     TELSE = 282,
     TNE = 283,
     TEQ = 284,
     TLE = 285,
     TGE = 286,
     TUMINUS = 287
   };
#endif
/* Tokens.  */
#define TINTEGER 258
#define TIDENTITY 259
#define TINT 260
#define TVOID 261
#define TCONST 262
#define TWHILE 263
#define TFOR 264
#define TIF 265
#define TSWITCH 266
#define TCONTINUE 267
#define TBREAK 268
#define TRETURN 269
#define TCASE 270
#define TDEFAULT 271
#define TINC 272
#define TDEC 273
#define TADDASSIGN 274
#define TSUBASSIGN 275
#define TMULASSIGN 276
#define TMODASSIGN 277
#define TDIVASSIGN 278
#define TOR 279
#define TAND 280
#define TIFX 281
#define TELSE 282
#define TNE 283
#define TEQ 284
#define TLE 285
#define TGE 286
#define TUMINUS 287




/* Copy the first part of user declarations.  */
#line 1 "minic.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minic_ast.h"
#include "ucode_gen.h"
extern FILE *yyin;

int yylex(void);
void yyerror(char *s);
Node *root;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "minic.y"
{
	char* string;
	struct nodeType *nPtr;
}
/* Line 193 of yacc.c.  */
#line 178 "minic.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 191 "minic.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    49,     2,     2,
      39,    40,    36,    34,    41,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    44,
      29,    45,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    30,    31,    32,    33,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    17,    21,
      23,    25,    28,    30,    32,    34,    36,    38,    40,    44,
      46,    47,    49,    53,    56,    61,    63,    64,    66,    69,
      73,    75,    79,    81,    85,    87,    92,    94,    95,    97,
      98,   100,   103,   113,   115,   116,   120,   122,   124,   125,
     127,   128,   130,   134,   137,   140,   148,   151,   153,   156,
     159,   161,   165,   168,   170,   172,   174,   176,   178,   180,
     182,   184,   186,   188,   190,   192,   195,   197,   198,   204,
     212,   218,   222,   224,   226,   230,   234,   238,   242,   246,
     250,   252,   256,   258,   262,   264,   268,   272,   274,   278,
     282,   286,   290,   292,   296,   300,   302,   306,   310,   314,
     316,   319,   322,   325,   328,   330,   335,   340,   343,   346,
     348,   349,   351,   353,   357,   359,   361
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    54,    -1,    53,    54,    -1,
      55,    -1,    70,    -1,    56,    67,    -1,    57,    62,    63,
      -1,    58,    -1,    59,    -1,    58,    59,    -1,    60,    -1,
      61,    -1,     7,    -1,     5,    -1,     6,    -1,     4,    -1,
      39,    64,    40,    -1,    65,    -1,    -1,    66,    -1,    65,
      41,    66,    -1,    57,    73,    -1,    42,    68,    75,    43,
      -1,    69,    -1,    -1,    70,    -1,    69,    70,    -1,    57,
      71,    44,    -1,    72,    -1,    71,    41,    72,    -1,    73,
      -1,    73,    45,     3,    -1,     4,    -1,     4,    46,    74,
      47,    -1,     3,    -1,    -1,    76,    -1,    -1,    90,    -1,
      76,    90,    -1,     9,    39,    78,    44,    80,    44,    81,
      40,    90,    -1,    79,    -1,    -1,    79,    41,   100,    -1,
     100,    -1,   101,    -1,    -1,    82,    -1,    -1,   100,    -1,
      82,    41,   100,    -1,    12,    44,    -1,    13,    44,    -1,
      11,    39,    73,    40,    42,    86,    43,    -1,    86,    87,
      -1,    87,    -1,    88,    76,    -1,    88,    89,    -1,    89,
      -1,    15,     3,    48,    -1,    16,    48,    -1,    67,    -1,
      94,    -1,    92,    -1,    91,    -1,    93,    -1,    77,    -1,
      97,    -1,    96,    -1,    85,    -1,    98,    -1,    83,    -1,
      84,    -1,    95,    44,    -1,    99,    -1,    -1,    10,    39,
      99,    40,    90,    -1,    10,    39,    99,    40,    90,    27,
      90,    -1,     8,    39,    99,    40,    90,    -1,    14,    95,
      44,    -1,   100,    -1,   101,    -1,   107,    45,   100,    -1,
     107,    19,   100,    -1,   107,    20,   100,    -1,   107,    21,
     100,    -1,   107,    23,   100,    -1,   107,    22,   100,    -1,
     102,    -1,   101,    24,   102,    -1,   103,    -1,   102,    25,
     103,    -1,   104,    -1,   103,    31,   104,    -1,   103,    30,
     104,    -1,   105,    -1,   104,    28,   105,    -1,   104,    29,
     105,    -1,   104,    33,   105,    -1,   104,    32,   105,    -1,
     106,    -1,   105,    34,   106,    -1,   105,    35,   106,    -1,
     107,    -1,   106,    36,   107,    -1,   106,    37,   107,    -1,
     106,    49,   107,    -1,   108,    -1,    35,   107,    -1,    50,
     107,    -1,    17,   107,    -1,    18,   107,    -1,   112,    -1,
     108,    46,    99,    47,    -1,   108,    39,   109,    40,    -1,
     108,    17,    -1,   108,    18,    -1,   110,    -1,    -1,   111,
      -1,   100,    -1,   111,    41,   100,    -1,     4,    -1,     3,
      -1,    39,    99,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    52,    55,    61,    64,    69,    75,    83,
      88,    91,    97,    98,   101,   106,   109,   114,   119,   124,
     125,   128,   129,   135,   141,   147,   148,   151,   152,   158,
     164,   165,   171,   172,   177,   181,   188,   189,   192,   193,
     196,   197,   203,   211,   214,   217,   221,   226,   229,   232,
     235,   238,   239,   244,   249,   254,   260,   263,   267,   275,
     278,   283,   287,   292,   293,   294,   295,   296,   299,   300,
     303,   304,   307,   308,   309,   312,   317,   318,   321,   325,
     332,   338,   343,   346,   347,   351,   355,   359,   363,   367,
     373,   374,   380,   381,   387,   388,   392,   398,   399,   403,
     407,   411,   417,   418,   422,   428,   429,   433,   437,   443,
     444,   447,   450,   453,   458,   459,   463,   467,   470,   475,
     476,   479,   484,   485,   491,   492,   493
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TINTEGER", "TIDENTITY", "TINT", "TVOID",
  "TCONST", "TWHILE", "TFOR", "TIF", "TSWITCH", "TCONTINUE", "TBREAK",
  "TRETURN", "TCASE", "TDEFAULT", "TINC", "TDEC", "TADDASSIGN",
  "TSUBASSIGN", "TMULASSIGN", "TMODASSIGN", "TDIVASSIGN", "TOR", "TAND",
  "TIFX", "TELSE", "'>'", "'<'", "TNE", "TEQ", "TLE", "TGE", "'+'", "'-'",
  "'*'", "'/'", "TUMINUS", "'('", "')'", "','", "'{'", "'}'", "';'", "'='",
  "'['", "']'", "':'", "'%'", "'!'", "$accept", "mini_c",
  "translation_unit", "external_dcl", "function_def", "function_header",
  "dcl_spec", "dcl_specifiers", "dcl_specifier", "type_qualifier",
  "type_specifier", "function_name", "formal_param", "opt_formal_param",
  "formal_param_list", "param_dcl", "compound_st", "opt_dcl_list",
  "declaration_list", "declaration", "init_dcl_list", "init_declarator",
  "declarator", "opt_number", "opt_stat_list", "statement_list", "for_st",
  "for_dcl", "for_dcl_list", "for_exp", "for_inc", "for_inc_list",
  "continue_st", "break_st", "switch_st", "switch_list", "switch_compound",
  "case_list", "switch_case", "statement", "loop_st", "condition_st",
  "flow_st", "expression_st", "opt_expression", "if_st", "while_st",
  "return_st", "expression", "assignment_exp", "logical_or_exp",
  "logical_and_exp", "equality_exp", "relational_exp", "additive_exp",
  "multiplicative_exp", "unary_exp", "postfix_exp", "opt_actual_param",
  "actual_param", "actual_param_list", "primary_exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    62,    60,
     283,   284,   285,   286,    43,    45,    42,    47,   287,    40,
      41,    44,   123,   125,    59,    61,    91,    93,    58,    37,
      33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    63,    64,
      64,    65,    65,    66,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    84,    85,    86,    86,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    94,    95,    95,    96,    96,
      97,    98,    99,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   104,   104,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   108,   108,   108,   108,   108,   109,
     109,   110,   111,   111,   112,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     3,     2,     4,     1,     0,     1,     2,     3,
       1,     3,     1,     3,     1,     4,     1,     0,     1,     0,
       1,     2,     9,     1,     0,     3,     1,     1,     0,     1,
       0,     1,     3,     2,     2,     7,     2,     1,     2,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     5,     7,
       5,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     1,     4,     4,     2,     2,     1,
       0,     1,     1,     3,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    16,    14,     0,     2,     3,     5,     0,     0,
       9,    10,    12,    13,     6,     1,     4,    26,     7,    34,
       0,     0,    30,    32,    11,     0,    39,    25,    27,    37,
      20,     8,     0,    29,     0,    34,   125,   124,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
      63,     0,    38,    68,    73,    74,    71,    40,    66,    65,
      67,    64,     0,    70,    69,    72,    76,    82,    83,    90,
      92,    94,    97,   102,   105,   109,   114,    28,    36,     0,
       0,     0,    19,    21,    31,    33,     0,    44,     0,     0,
      53,    54,     0,   112,   113,   110,     0,   111,    24,    41,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   118,   120,     0,    35,    23,    18,     0,     0,     0,
      43,    46,     0,     0,    81,   126,    91,   105,    93,    96,
      95,    98,    99,   101,   100,   103,   104,   106,   107,   108,
      85,    86,    87,    89,    88,    84,   122,     0,   119,   121,
       0,    22,    77,    48,     0,    77,     0,   116,     0,   115,
      80,     0,    47,    45,    78,     0,   123,    50,    77,     0,
       0,     0,    57,    77,    60,     0,    49,    51,    79,     0,
      62,    55,    56,    58,    59,    77,     0,    61,    42,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    20,    31,    81,    82,    83,    50,    26,    27,    14,
      21,    22,    23,    79,    51,    52,    53,   129,   130,   171,
     185,   186,    54,    55,    56,   181,   182,   183,   184,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   157,   158,
     159,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
      79,   -82,   -82,   -82,    13,    79,   -82,   -82,    12,    20,
      79,   -82,   -82,   -82,   -82,   -82,   -82,    79,   -82,     7,
       9,     8,   -82,    -3,   -82,    46,   141,    79,   -82,    53,
      79,   -82,    46,   -82,   105,    63,   -82,   -82,    72,    77,
      78,    81,    68,    74,     5,     5,     5,     5,     5,     5,
     -82,    80,   141,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,    83,   -82,   -82,   -82,   -82,   -82,    97,   100,
      50,    42,    38,   -18,     6,    -7,   -82,   -82,   -82,    75,
      46,    90,    88,   -82,   -82,   -82,     5,     5,     5,    46,
     -82,   -82,    91,   -82,   -82,   -82,    92,   -82,   -82,   -82,
     -82,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
     -82,   -82,     5,     5,   -82,   -82,   -82,    79,    93,    94,
      95,   -82,   102,   106,   -82,   -82,   100,   -82,    50,    42,
      42,    38,    38,    38,    38,   -18,   -18,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   107,   -82,    96,
      87,   -82,   153,     5,     5,   153,    98,   -82,     5,   -82,
     -82,   104,    97,   -82,   133,    73,   -82,     5,   153,   165,
     121,     0,   -82,    89,   -82,   132,   134,   -82,   -82,   125,
     -82,   -82,   -82,   141,   -82,   153,     5,   -82,   -82,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   169,   -82,   -82,   -13,   -82,   167,   -82,
     -82,   -82,   -82,   -82,   -82,    51,   171,   -82,   -82,     3,
     -82,   149,   -68,   -82,   -82,    -1,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,    15,   -82,     1,   -52,
     -82,   -82,   -82,   -82,   142,   -82,   -82,   -82,   -41,   -81,
      24,    99,   103,    -9,   -29,   -19,   -44,   -82,   -82,   -82,
     -82,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -78
static const yytype_int16 yytable[] =
{
      99,    93,    94,    95,    25,    97,   131,    96,    36,    37,
     120,   121,   125,    15,    25,   179,   180,    80,   111,   112,
      28,   133,    45,    46,    19,   114,   115,   116,   117,   118,
      77,   113,   122,   150,   151,   152,   153,   154,   155,   123,
      47,   156,    34,   191,    48,   128,   -17,   132,    30,    32,
      35,   119,    33,    29,    17,    49,    78,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   147,   148,   149,
     105,   106,   109,   110,   107,   108,   141,   142,   143,   144,
     103,   104,   160,   173,     1,     2,     3,   176,   179,   180,
     145,   146,    36,    37,   139,   140,   187,    38,    39,    40,
      41,    42,    43,    44,   179,   180,    45,    46,    85,    29,
     170,    86,    90,   174,    80,   199,    87,    88,    91,   137,
      89,   101,   124,    98,    47,   102,   188,   100,    48,   127,
     126,    17,   135,   162,   169,   134,   164,   168,   163,    49,
     175,    99,   165,   198,    36,    37,   166,   167,   177,    38,
      39,    40,    41,    42,    43,    44,    36,    37,    45,    46,
     178,    38,    39,    40,    41,    42,    43,    44,   189,   190,
      45,    46,   195,   197,    16,   196,    47,    24,   161,    18,
      48,    84,   193,    17,   194,   -77,    92,   172,    47,     0,
       0,    49,    48,     0,     0,    17,   192,     0,     0,     0,
     136,     0,     0,    49,     0,   138
};

static const yytype_int16 yycheck[] =
{
      52,    45,    46,    47,    17,    49,    87,    48,     3,     4,
      17,    18,    80,     0,    27,    15,    16,    30,    36,    37,
      17,    89,    17,    18,     4,    19,    20,    21,    22,    23,
      27,    49,    39,   114,   115,   116,   117,   118,   119,    46,
      35,   122,    45,    43,    39,    86,    39,    88,    39,    41,
       4,    45,    44,    46,    42,    50,     3,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      28,    29,    34,    35,    32,    33,   105,   106,   107,   108,
      30,    31,   123,   164,     5,     6,     7,   168,    15,    16,
     109,   110,     3,     4,   103,   104,   177,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,    46,
     162,    39,    44,   165,   127,   196,    39,    39,    44,   163,
      39,    24,    47,    43,    35,    25,   178,    44,    39,    41,
      40,    42,    40,    40,    47,    44,    41,    41,    44,    50,
      42,   193,    40,   195,     3,     4,    40,    40,    44,     8,
       9,    10,    11,    12,    13,    14,     3,     4,    17,    18,
      27,     8,     9,    10,    11,    12,    13,    14,     3,    48,
      17,    18,    40,    48,     5,    41,    35,    10,   127,     8,
      39,    32,   183,    42,   183,    44,    44,   163,    35,    -1,
      -1,    50,    39,    -1,    -1,    42,   181,    -1,    -1,    -1,
     101,    -1,    -1,    50,    -1,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    70,     0,    54,    42,    67,     4,
      62,    71,    72,    73,    59,    57,    68,    69,    70,    46,
      39,    63,    41,    44,    45,     4,     3,     4,     8,     9,
      10,    11,    12,    13,    14,    17,    18,    35,    39,    50,
      67,    75,    76,    77,    83,    84,    85,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   112,    70,     3,    74,
      57,    64,    65,    66,    72,     3,    39,    39,    39,    39,
      44,    44,    95,   107,   107,   107,    99,   107,    43,    90,
      44,    24,    25,    30,    31,    28,    29,    32,    33,    34,
      35,    36,    37,    49,    19,    20,    21,    22,    23,    45,
      17,    18,    39,    46,    47,    73,    40,    41,    99,    78,
      79,   100,    99,    73,    44,    40,   102,   107,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     100,   100,   100,   100,   100,   100,   100,   109,   110,   111,
      99,    66,    40,    44,    41,    40,    40,    40,    41,    47,
      90,    80,   101,   100,    90,    42,   100,    44,    27,    15,
      16,    86,    87,    88,    89,    81,    82,   100,    90,     3,
      48,    43,    87,    76,    89,    40,    41,    48,    90,   100
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 47 "minic.y"
    { 
		root = buildTree(PROGRAM, (yyvsp[(1) - (1)].nPtr));
	;}
    break;

  case 3:
#line 52 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 4:
#line 55 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr),(yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);
	;}
    break;

  case 5:
#line 61 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 6:
#line 64 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 7:
#line 69 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = buildTree(FUNC_DEF, (yyvsp[(1) - (2)].nPtr));
	;}
    break;

  case 8:
#line 75 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
		appendBrother((yyvsp[(2) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(FUNC_HEAD, (yyvsp[(1) - (3)].nPtr));

	;}
    break;

  case 9:
#line 83 "minic.y"
    {
		(yyval.nPtr) = buildTree(DCL_SPEC,(yyvsp[(1) - (1)].nPtr));
	;}
    break;

  case 10:
#line 88 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 11:
#line 91 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);
	;}
    break;

  case 12:
#line 97 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 13:
#line 98 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 14:
#line 101 "minic.y"
    {
		(yyval.nPtr) = buildTree(CONST_TYPE, NULL);
	;}
    break;

  case 15:
#line 106 "minic.y"
    {
		(yyval.nPtr) = buildTree(INT_TYPE, NULL);
	;}
    break;

  case 16:
#line 109 "minic.y"
    {
		(yyval.nPtr) = buildTree(VOID_TYPE, NULL);
	;}
    break;

  case 17:
#line 114 "minic.y"
    {
		(yyval.nPtr) = buildNode(IDENT,(yyvsp[(1) - (1)].string));
	;}
    break;

  case 18:
#line 119 "minic.y"
    {
		(yyval.nPtr) = buildTree(FORMAL_PARA, (yyvsp[(2) - (3)].nPtr));
	;}
    break;

  case 19:
#line 124 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 20:
#line 125 "minic.y"
    { (yyval.nPtr) = NULL; ;}
    break;

  case 21:
#line 128 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 22:
#line 129 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (3)].nPtr);
	;}
    break;

  case 23:
#line 135 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = buildTree(PARAM_DCL, (yyvsp[(1) - (2)].nPtr));
	;}
    break;

  case 24:
#line 141 "minic.y"
    {
		appendBrother((yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
		(yyval.nPtr) = buildTree(COMPOUND_ST, (yyvsp[(2) - (4)].nPtr));
	;}
    break;

  case 25:
#line 147 "minic.y"
    { (yyval.nPtr) = buildTree(DCL_LIST, (yyvsp[(1) - (1)].nPtr)); ;}
    break;

  case 26:
#line 148 "minic.y"
    { (yyval.nPtr) = buildTree(DCL_LIST,NULL); ;}
    break;

  case 27:
#line 151 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 28:
#line 152 "minic.y"
    { 
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr);
	;}
    break;

  case 29:
#line 158 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr));
		(yyval.nPtr) = buildTree(DCL, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 30:
#line 164 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 31:
#line 165 "minic.y"
    { 
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (3)].nPtr);
	;}
    break;

  case 32:
#line 171 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 33:
#line 172 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr)->son, buildNode(NUMBER, (yyvsp[(3) - (3)].string))); 
	;}
    break;

  case 34:
#line 177 "minic.y"
    {
		Node* ptr = buildTree(SIMPLE_VAR, buildNode(IDENT, (yyvsp[(1) - (1)].string)));
		(yyval.nPtr) = buildTree(DCL_ITEM,ptr);
	;}
    break;

  case 35:
#line 181 "minic.y"
    {
		Node* ptr = buildNode(IDENT, (yyvsp[(1) - (4)].string));
		appendBrother(ptr,(yyvsp[(3) - (4)].nPtr));
		(yyval.nPtr) = buildTree(DCL_ITEM, buildTree(ARRAY_VAR, ptr));
	;}
    break;

  case 36:
#line 188 "minic.y"
    { (yyval.nPtr) = buildNode(NUMBER, (yyvsp[(1) - (1)].string)); ;}
    break;

  case 37:
#line 189 "minic.y"
    { (yyval.nPtr) = NULL; ;}
    break;

  case 38:
#line 192 "minic.y"
    { (yyval.nPtr) = buildTree(STAT_LIST, (yyvsp[(1) - (1)].nPtr)); ;}
    break;

  case 39:
#line 193 "minic.y"
    { (yyval.nPtr) = NULL; ;}
    break;

  case 40:
#line 196 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 41:
#line 197 "minic.y"
    { 
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); 
	;}
    break;

  case 42:
#line 203 "minic.y"
    {
		appendBrother((yyvsp[(3) - (9)].nPtr), (yyvsp[(5) - (9)].nPtr));
		appendBrother((yyvsp[(5) - (9)].nPtr), (yyvsp[(7) - (9)].nPtr));
		appendBrother((yyvsp[(7) - (9)].nPtr), (yyvsp[(9) - (9)].nPtr));
		(yyval.nPtr) = buildTree(FOR_ST,(yyvsp[(3) - (9)].nPtr));
	;}
    break;

  case 43:
#line 211 "minic.y"
    {
		(yyval.nPtr) = buildTree(FOR_DCL, (yyvsp[(1) - (1)].nPtr));
	;}
    break;

  case 44:
#line 214 "minic.y"
    { (yyval.nPtr) = buildTree(FOR_DCL,NULL); ;}
    break;

  case 45:
#line 217 "minic.y"
    { // init_declarator -> assignment_exp로 수정됨
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (3)].nPtr);	
	;}
    break;

  case 46:
#line 221 "minic.y"
    { //  init_declarator -> assignment_exp로 수정됨
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 47:
#line 226 "minic.y"
    {
		(yyval.nPtr) = buildTree(FOR_EXP, (yyvsp[(1) - (1)].nPtr));
	;}
    break;

  case 48:
#line 229 "minic.y"
    { (yyval.nPtr) = buildTree(FOR_EXP, NULL); ;}
    break;

  case 49:
#line 232 "minic.y"
    {
		(yyval.nPtr) = buildTree(FOR_INC, (yyvsp[(1) - (1)].nPtr));
	;}
    break;

  case 50:
#line 235 "minic.y"
    { (yyval.nPtr) = buildTree(FOR_INC,NULL); ;}
    break;

  case 51:
#line 238 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 52:
#line 239 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (3)].nPtr);
	;}
    break;

  case 53:
#line 244 "minic.y"
    {
		(yyval.nPtr) = buildTree(CONTINUE_ST,NULL);
	;}
    break;

  case 54:
#line 249 "minic.y"
    {
		(yyval.nPtr) = buildTree(BREAK_ST, NULL);
	;}
    break;

  case 55:
#line 254 "minic.y"
    {
		appendBrother((yyvsp[(3) - (7)].nPtr), (yyvsp[(6) - (7)].nPtr));	
		(yyval.nPtr) = buildTree(SWITCH_ST, (yyvsp[(3) - (7)].nPtr));
	;}
    break;

  case 56:
#line 260 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));	
	;}
    break;

  case 57:
#line 263 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 58:
#line 267 "minic.y"
    {
		Node *p = buildTree(CASE_EXP,(yyvsp[(2) - (2)].nPtr));
		Node *q = buildTree(CASE_LST,(yyvsp[(1) - (2)].nPtr));
		appendBrother(q, p);
		(yyval.nPtr) = q;
	;}
    break;

  case 59:
#line 275 "minic.y"
    {
		appendBrother((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
	;}
    break;

  case 60:
#line 278 "minic.y"
    {
		(yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);
	;}
    break;

  case 61:
#line 283 "minic.y"
    { // 전체적인 문법이 수정됨 
		Node * son = buildNode(NUMBER, (yyvsp[(2) - (3)].string));
		(yyval.nPtr) = buildTree(CASE_ST, son);		
	;}
    break;

  case 62:
#line 287 "minic.y"
    {
		(yyval.nPtr) = buildTree(DEFAULT_ST, NULL);
	;}
    break;

  case 63:
#line 292 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 64:
#line 293 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 65:
#line 294 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 66:
#line 295 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 67:
#line 296 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 68:
#line 299 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 69:
#line 300 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 70:
#line 303 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 71:
#line 304 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 72:
#line 307 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 73:
#line 308 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 74:
#line 309 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 75:
#line 312 "minic.y"
    { 
		(yyval.nPtr) = buildTree(EXP_ST, (yyvsp[(1) - (2)].nPtr));
	;}
    break;

  case 76:
#line 317 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 77:
#line 318 "minic.y"
    { (yyval.nPtr) = NULL; ;}
    break;

  case 78:
#line 321 "minic.y"
    {
		appendBrother((yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));
		(yyval.nPtr) = buildTree(IF_ST, (yyvsp[(3) - (5)].nPtr));
	;}
    break;

  case 79:
#line 325 "minic.y"
    {
		appendBrother((yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr));
		appendBrother((yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr));
		(yyval.nPtr) = buildTree(IF_ELSE_ST, (yyvsp[(3) - (7)].nPtr));
	;}
    break;

  case 80:
#line 332 "minic.y"
    {
		appendBrother((yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));
		(yyval.nPtr) = buildTree(WHILE_ST, (yyvsp[(3) - (5)].nPtr));
	;}
    break;

  case 81:
#line 338 "minic.y"
    { 
		(yyval.nPtr) = buildTree(RETURN_ST, (yyvsp[(2) - (3)].nPtr));
	;}
    break;

  case 82:
#line 343 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 83:
#line 346 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 84:
#line 347 "minic.y"
    { 
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(ASSIGN_OP, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 85:
#line 351 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(ADD_ASSIGN, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 86:
#line 355 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(SUB_ASSIGN, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 87:
#line 359 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(MUL_ASSIGN, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 88:
#line 363 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(DIV_ASSIGN, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 89:
#line 367 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(MOD_ASSIGN, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 90:
#line 373 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 91:
#line 374 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(LOGICAL_OR, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 92:
#line 380 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 93:
#line 381 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(LOGICAL_AND, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 94:
#line 387 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 95:
#line 388 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(EQ, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 96:
#line 392 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(NE, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 97:
#line 398 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 98:
#line 399 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(GT, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 99:
#line 403 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(LT, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 100:
#line 407 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(GE, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 101:
#line 411 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(LE, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 102:
#line 417 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 103:
#line 418 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(ADD, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 104:
#line 422 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(SUB, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 105:
#line 428 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 106:
#line 429 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(MUL, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 107:
#line 433 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(DIV, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 108:
#line 437 "minic.y"
    {
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = buildTree(REMAINDER, (yyvsp[(1) - (3)].nPtr));
	;}
    break;

  case 109:
#line 443 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 110:
#line 444 "minic.y"
    {
		(yyval.nPtr) = buildTree(UNARY_MINUS, (yyvsp[(2) - (2)].nPtr));
	;}
    break;

  case 111:
#line 447 "minic.y"
    {
		(yyval.nPtr) = buildTree(LOGICAL_NOT, (yyvsp[(2) - (2)].nPtr));
	;}
    break;

  case 112:
#line 450 "minic.y"
    {
		(yyval.nPtr) = buildTree(PRE_INC, (yyvsp[(2) - (2)].nPtr));
	;}
    break;

  case 113:
#line 453 "minic.y"
    {
		(yyval.nPtr) = buildTree(PRE_DEC, (yyvsp[(2) - (2)].nPtr));
	;}
    break;

  case 114:
#line 458 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 115:
#line 459 "minic.y"
    {
		appendBrother((yyvsp[(1) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
		(yyval.nPtr) = buildTree(INDEX, (yyvsp[(1) - (4)].nPtr));
	;}
    break;

  case 116:
#line 463 "minic.y"
    {
		appendBrother((yyvsp[(1) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr));
		(yyval.nPtr) = buildTree(CALL, (yyvsp[(1) - (4)].nPtr));
	;}
    break;

  case 117:
#line 467 "minic.y"
    {
		(yyval.nPtr) = buildTree(POST_INC, (yyvsp[(1) - (2)].nPtr));
	;}
    break;

  case 118:
#line 470 "minic.y"
    {
		(yyval.nPtr) = buildTree(POST_DEC, (yyvsp[(1) - (2)].nPtr));
	;}
    break;

  case 119:
#line 475 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 120:
#line 476 "minic.y"
    { (yyval.nPtr) = NULL; ;}
    break;

  case 121:
#line 479 "minic.y"
    {
		(yyval.nPtr) = buildTree(ACTUAL_PARAM, (yyvsp[(1) - (1)].nPtr));	
	;}
    break;

  case 122:
#line 484 "minic.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 123:
#line 485 "minic.y"
    { 
		appendBrother((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
		(yyval.nPtr) = (yyvsp[(1) - (3)].nPtr);
	;}
    break;

  case 124:
#line 491 "minic.y"
    { (yyval.nPtr) = buildNode(IDENT, (yyvsp[(1) - (1)].string)); ;}
    break;

  case 125:
#line 492 "minic.y"
    { (yyval.nPtr) = buildNode(NUMBER, (yyvsp[(1) - (1)].string)); ;}
    break;

  case 126:
#line 493 "minic.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2419 "minic.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 496 "minic.y"

char *toString(char *string)
{
	char *str;
	int len = strlen(string);
	str = (char *)malloc(len+1);
	strcpy(str,string);
	str[len] = '\0';
	return str;
}

void parse(FILE *cFile)
{

	yyin = cFile;
	do{
		yyparse();
	}while(!feof(yyin));
}
int main(int argc, char *argv[]){
	FILE *cFile, *astFile, *ucoFile;
	char fileName[256];
	if(argc != 2){
		fprintf(stderr, "arguments not valid.");
		return -1;
	}
	strcpy(fileName, argv[1]);
	cFile = fopen(fileName, "r");
	astFile = fopen(strcat(strtok(fileName,"."),".ast"),"w");
	ucoFile = fopen(strcat(strtok(fileName,"."),".uco"),"w");	

	parse(cFile);
	printTree(root,0,astFile);
	
	codeGen(root, ucoFile);

	fclose(cFile);
	fclose(astFile);
	fclose(ucoFile);
	return 0;
}

