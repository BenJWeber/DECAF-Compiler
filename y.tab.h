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
#line 61 "lab9.y" /* yacc.c:1909  */

   int value;
   char* string;
   struct ASTnodetype *astnode;
   enum AST_Decaf_Types asttype;
   enum AST_Operators operator;

#line 142 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
