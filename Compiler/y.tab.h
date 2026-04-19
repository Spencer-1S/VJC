/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER_LITERAL = 258,          /* NUMBER_LITERAL  */
    DECIMAL_LITERAL = 259,         /* DECIMAL_LITERAL  */
    TRUTH_LITERAL = 260,           /* TRUTH_LITERAL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    FSTRING_LITERAL = 263,         /* FSTRING_LITERAL  */
    TYPE_NUMBER = 264,             /* TYPE_NUMBER  */
    TYPE_DECIMAL = 265,            /* TYPE_DECIMAL  */
    TYPE_TRUTH = 266,              /* TYPE_TRUTH  */
    TYPE_STRING = 267,             /* TYPE_STRING  */
    TYPE_VOID = 268,               /* TYPE_VOID  */
    MAIN = 269,                    /* MAIN  */
    WRITE = 270,                   /* WRITE  */
    WRITELINE = 271,               /* WRITELINE  */
    READ = 272,                    /* READ  */
    READLINE = 273,                /* READLINE  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    FROM = 278,                    /* FROM  */
    TO = 279,                      /* TO  */
    STEP = 280,                    /* STEP  */
    BREAK = 281,                   /* BREAK  */
    CONTINUE = 282,                /* CONTINUE  */
    RETURN = 283,                  /* RETURN  */
    NEW = 284,                     /* NEW  */
    LENGTH = 285,                  /* LENGTH  */
    TO_DECIMAL = 286,              /* TO_DECIMAL  */
    TO_NUMBER = 287,               /* TO_NUMBER  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    LE = 290,                      /* LE  */
    GE = 291,                      /* GE  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    IFX = 294,                     /* IFX  */
    UMINUS = 295                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER_LITERAL 258
#define DECIMAL_LITERAL 259
#define TRUTH_LITERAL 260
#define IDENTIFIER 261
#define STRING_LITERAL 262
#define FSTRING_LITERAL 263
#define TYPE_NUMBER 264
#define TYPE_DECIMAL 265
#define TYPE_TRUTH 266
#define TYPE_STRING 267
#define TYPE_VOID 268
#define MAIN 269
#define WRITE 270
#define WRITELINE 271
#define READ 272
#define READLINE 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define FOR 277
#define FROM 278
#define TO 279
#define STEP 280
#define BREAK 281
#define CONTINUE 282
#define RETURN 283
#define NEW 284
#define LENGTH 285
#define TO_DECIMAL 286
#define TO_NUMBER 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define AND 292
#define OR 293
#define IFX 294
#define UMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

    long iValue;
    double dValue;
    bool bValue;
    char *sValue;
    nodeType *nPtr;

#line 155 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
