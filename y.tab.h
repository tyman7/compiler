/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "ExprEval.y" /* yacc.c:1909  */

  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;
  struct BExprRes * BExprRes;

#line 112 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
