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

#ifndef YY_YY_ATS_TAB_H_INCLUDED
# define YY_YY_ATS_TAB_H_INCLUDED
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
    TPROGRAM = 258,
    TMAIN = 259,
    TPROC = 260,
    TFUNC = 261,
    TRETURNS = 262,
    TVAR = 263,
    TINT = 264,
    TLONG = 265,
    TIF = 266,
    TTHEN = 267,
    TELSE = 268,
    TWHILE = 269,
    TFOR = 270,
    TTO = 271,
    TCALL = 272,
    TRETURN = 273,
    TBEGIN = 274,
    TEND = 275,
    TASS = 276,
    TAND = 277,
    TOR = 278,
    TNOT = 279,
    TLT = 280,
    TLE = 281,
    TGT = 282,
    TGE = 283,
    TNE = 284,
    TPLUS = 285,
    TMINUS = 286,
    TMUL = 287,
    TDIV = 288,
    TNUMBER = 289,
    TNAME = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "ats.y" /* yacc.c:1909  */

    double dval;
    char *sval;
    struct Node *nval;

#line 96 "ats.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ATS_TAB_H_INCLUDED  */
