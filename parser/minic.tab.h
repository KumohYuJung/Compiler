/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "minic.y"
{
	char* string;
	struct nodeType *nPtr;
}
/* Line 1529 of yacc.c.  */
#line 118 "minic.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

