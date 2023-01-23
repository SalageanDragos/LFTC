
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEGINN = 258,
     CONST = 259,
     DO = 260,
     ELSE = 261,
     END = 262,
     IF = 263,
     PRINT = 264,
     PROGRAM = 265,
     READ = 266,
     THEN = 267,
     VAR = 268,
     WHILE = 269,
     LL = 270,
     NUMBER = 271,
     lista_elem = 272,
     GG = 273,
     ID = 274,
     WRITE = 275,
     LET = 276,
     CONST_INT = 277,
     CONST_REAL = 278,
     CONST_CAR = 279,
     CONST_SIR = 280,
     CHAR = 281,
     INTEGER = 282,
     REAL = 283,
     BOOLEAN = 284,
     STRING = 285,
     EE = 286,
     IDENTIFIER = 287,
     ATRIB = 288,
     NE = 289,
     LE = 290,
     GE = 291,
     MOD = 292,
     DIV = 293,
     OR = 294,
     AND = 295,
     NOT = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "sspascal.y"

  	int l_val;
	char *p_val;



/* Line 1676 of yacc.c  */
#line 100 "sspascal.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


