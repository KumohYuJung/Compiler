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
     INTEGER = 258,
     IDENTITY = 259,
     INT = 260,
     VOID = 261,
     CONST = 262,
     WHILE = 263,
     FOR = 264,
     IF = 265,
     SWITCH = 266,
     CONTINUE = 267,
     BREAK = 268,
     RETURN = 269,
     CASE = 270,
     DEFAULT = 271,
     INC = 272,
     DEC = 273,
     ADDASSIGN = 274,
     SUBASSIGN = 275,
     MULASSIGN = 276,
     MODASSIGN = 277,
     DIVASSIGN = 278,
     OR = 279,
     AND = 280,
     IFX = 281,
     CASEX = 282,
     ELSE = 283,
     NE = 284,
     EQ = 285,
     LE = 286,
     GE = 287,
     UMINUS = 288
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define IDENTITY 259
#define INT 260
#define VOID 261
#define CONST 262
#define WHILE 263
#define FOR 264
#define IF 265
#define SWITCH 266
#define CONTINUE 267
#define BREAK 268
#define RETURN 269
#define CASE 270
#define DEFAULT 271
#define INC 272
#define DEC 273
#define ADDASSIGN 274
#define SUBASSIGN 275
#define MULASSIGN 276
#define MODASSIGN 277
#define DIVASSIGN 278
#define OR 279
#define AND 280
#define IFX 281
#define CASEX 282
#define ELSE 283
#define NE 284
#define EQ 285
#define LE 286
#define GE 287
#define UMINUS 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "minic.y"
{
	int iValue;
	char* string;
	nodeType *nPtr;
}
/* Line 1529 of yacc.c.  */
#line 121 "minic.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

