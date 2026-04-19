/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "ast.h"

int yylex(void);
void yyerror(char *s);
extern int lineno;

nodeType *root = NULL;

nodeType *coerceReadForType(int typeType, nodeType *expr);

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER_LITERAL = 3,             /* NUMBER_LITERAL  */
  YYSYMBOL_DECIMAL_LITERAL = 4,            /* DECIMAL_LITERAL  */
  YYSYMBOL_TRUTH_LITERAL = 5,              /* TRUTH_LITERAL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_FSTRING_LITERAL = 8,            /* FSTRING_LITERAL  */
  YYSYMBOL_TYPE_NUMBER = 9,                /* TYPE_NUMBER  */
  YYSYMBOL_TYPE_DECIMAL = 10,              /* TYPE_DECIMAL  */
  YYSYMBOL_TYPE_TRUTH = 11,                /* TYPE_TRUTH  */
  YYSYMBOL_TYPE_STRING = 12,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_VOID = 13,                 /* TYPE_VOID  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_WRITE = 15,                     /* WRITE  */
  YYSYMBOL_WRITELINE = 16,                 /* WRITELINE  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_READLINE = 18,                  /* READLINE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_FROM = 23,                      /* FROM  */
  YYSYMBOL_TO = 24,                        /* TO  */
  YYSYMBOL_STEP = 25,                      /* STEP  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 27,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_NEW = 29,                       /* NEW  */
  YYSYMBOL_LENGTH = 30,                    /* LENGTH  */
  YYSYMBOL_TO_DECIMAL = 31,                /* TO_DECIMAL  */
  YYSYMBOL_TO_NUMBER = 32,                 /* TO_NUMBER  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LE = 35,                        /* LE  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_IFX = 39,                       /* IFX  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_47_ = 47,                       /* '!'  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '='  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_function_list = 61,             /* function_list  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_main_func = 63,                 /* main_func  */
  YYSYMBOL_param_list = 64,                /* param_list  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_stmt_list = 68,                 /* stmt_list  */
  YYSYMBOL_stmt = 69,                      /* stmt  */
  YYSYMBOL_opt_step = 70,                  /* opt_step  */
  YYSYMBOL_var_decl = 71,                  /* var_decl  */
  YYSYMBOL_arr_decl = 72,                  /* arr_decl  */
  YYSYMBOL_arg_list = 73,                  /* arg_list  */
  YYSYMBOL_expr = 74                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    46,     2,     2,
      49,    50,    44,    42,    51,    43,    58,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
      40,    55,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    58,    59,    63,    64,    65,    66,    67,
      71,    75,    76,    80,    84,    85,    86,    87,    91,    92,
      96,    97,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   114,   115,   116,   117,   118,   119,   123,
     124,   128,   129,   133,   134,   138,   139,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER_LITERAL",
  "DECIMAL_LITERAL", "TRUTH_LITERAL", "IDENTIFIER", "STRING_LITERAL",
  "FSTRING_LITERAL", "TYPE_NUMBER", "TYPE_DECIMAL", "TYPE_TRUTH",
  "TYPE_STRING", "TYPE_VOID", "MAIN", "WRITE", "WRITELINE", "READ",
  "READLINE", "IF", "ELSE", "WHILE", "FOR", "FROM", "TO", "STEP", "BREAK",
  "CONTINUE", "RETURN", "NEW", "LENGTH", "TO_DECIMAL", "TO_NUMBER", "EQ",
  "NE", "LE", "GE", "AND", "OR", "IFX", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "UMINUS", "'('", "')'", "','", "'{'", "'}'", "';'",
  "'='", "'['", "']'", "'.'", "$accept", "program", "function_list",
  "function", "main_func", "param_list", "param", "type", "block",
  "stmt_list", "stmt", "opt_step", "var_decl", "arr_decl", "arg_list",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      99,   -93,   -93,   -93,   -93,     9,    12,    99,   -93,   -93,
      10,   -22,    -9,   -93,   -93,     1,    32,     7,    44,    41,
      14,   -93,    60,    41,    41,    33,   148,   -93,    41,    93,
     -93,   -93,   -93,    41,    43,    48,    64,    69,    76,    79,
      73,    75,    83,   -93,    -4,   171,   -93,    77,    81,   -93,
     -93,   -93,   199,   253,   253,   253,   253,   253,   253,    93,
     -93,   -93,   -93,   -93,   -93,   -10,   -93,   -93,    84,    87,
      89,    90,   253,   253,   253,   -93,   345,    85,    91,   -93,
     -93,   -93,   -93,    88,    45,   591,   360,   270,   411,   429,
     447,   465,   135,   233,   253,   116,   253,   253,   253,   253,
     -93,   -93,   483,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   -93,   253,   141,   -93,
      96,   253,   -93,    97,   101,   102,    41,    41,   130,   -93,
      66,   288,   -93,   501,   519,   537,   555,   -93,   -11,   -11,
      78,    78,   619,   605,    78,    78,   -35,   -35,   -93,   -93,
     -93,   591,   106,   -93,   591,   253,   -93,   -93,   142,   -93,
     119,   -93,   -93,   -93,   -93,   -93,   -93,   -24,   375,    -5,
     253,    93,   253,   -93,   123,   -93,   331,   109,    -2,   253,
     253,   253,   -93,   573,   397,   306,    41,   253,   128,   -93,
     -93,   591,   129,    41,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    14,    15,    16,    17,     0,     0,     2,     3,     5,
       0,     0,     0,     1,     4,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     9,     0,     0,
      13,    10,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,    20,     0,     0,     8,
      12,     6,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    47,    48,    49,    52,    50,    51,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    41,     0,    18,
      21,    22,    23,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,    38,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    60,
       0,     0,    54,     0,     0,     0,     0,    76,    66,    67,
      70,    71,    72,    73,    68,    69,    61,    62,    63,    64,
      65,    42,     0,    37,    46,     0,    26,    27,    28,    31,
       0,    59,    53,    57,    58,    55,    56,     0,     0,     0,
       0,     0,     0,    25,     0,    29,     0,     0,     0,     0,
       0,     0,    44,     0,    39,     0,     0,     0,     0,    43,
      30,    40,     0,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   177,   -93,   167,   159,     0,   -20,   -93,
     144,   -93,   -93,   -93,   -92,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    20,    21,    22,    27,    45,
      46,   188,    47,    48,    84,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,   130,    77,    31,    32,   171,    76,    10,    49,   113,
     114,   115,    13,    51,   174,    11,    15,    86,    87,    88,
      89,    90,    91,    12,   105,   106,    44,    16,   172,   109,
     110,   111,   112,   113,   114,   115,   100,   101,   102,    93,
      17,     1,     2,     3,     4,    44,    94,    26,    95,   121,
      18,   182,    78,     1,     2,     3,     4,    23,   131,    92,
     133,   134,   135,   136,    28,    29,    30,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     178,   151,    19,    33,    29,   154,    62,    63,    64,    65,
      66,    67,    52,    26,    24,   120,   121,    55,    53,    54,
      68,    69,     1,     2,     3,     4,   158,   159,     1,     2,
       3,     4,     5,    56,    70,    71,   161,   121,    57,   168,
     111,   112,   113,   114,   115,    58,    72,    60,    59,    61,
      73,    81,    74,    96,   176,    82,    97,    75,    98,    99,
     117,   128,   119,   183,   184,   185,   132,   152,   118,   175,
     153,   191,   155,   160,    34,   156,   157,     1,     2,     3,
       4,   167,   169,    35,    36,   181,   190,    37,   170,    38,
      39,   177,   179,   194,    40,    41,    42,    34,   192,   193,
       1,     2,     3,     4,    14,    25,    35,    36,    50,    80,
      37,     0,    38,    39,     0,     0,     0,    40,    41,    42,
       0,    43,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
      70,    71,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    72,     0,     0,     0,    73,     0,    74,    83,
      68,    69,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,     0,     0,    70,    71,     0,     0,     0,     0,
      68,    69,     0,     0,     0,     0,    72,     0,     0,     0,
      73,     0,    74,   129,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
      73,     0,    74,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   123,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   162,   109,   110,   111,   112,
     113,   114,   115,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,   189,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,     0,   103,   104,   105,   106,   107,   108,   116,
     109,   110,   111,   112,   113,   114,   115,     0,   103,   104,
     105,   106,   107,   108,   122,   109,   110,   111,   112,   113,
     114,   115,   187,     0,     0,     0,     0,     0,     0,   173,
     103,   104,   105,   106,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   124,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   125,
     103,   104,   105,   106,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   126,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   127,   103,   104,   105,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   137,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   163,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   164,
     103,   104,   105,   106,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   165,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   166,   103,   104,   105,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   186,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   103,   104,
     105,   106,   107,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   103,   104,   105,   106,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       0,    93,     6,    23,    24,    29,    42,     7,    28,    44,
      45,    46,     0,    33,    19,     6,     6,    53,    54,    55,
      56,    57,    58,    14,    35,    36,    26,    49,    52,    40,
      41,    42,    43,    44,    45,    46,    72,    73,    74,    49,
      49,     9,    10,    11,    12,    45,    56,    52,    58,    51,
      49,    53,    56,     9,    10,    11,    12,    50,    94,    59,
      96,    97,    98,    99,    50,    51,     6,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     172,   117,    50,    50,    51,   121,     3,     4,     5,     6,
       7,     8,    49,    52,    50,    50,    51,    49,    55,    56,
      17,    18,     9,    10,    11,    12,   126,   127,     9,    10,
      11,    12,    13,    49,    31,    32,    50,    51,    49,   155,
      42,    43,    44,    45,    46,    49,    43,    54,    49,    54,
      47,    54,    49,    49,   170,    54,    49,    54,    49,    49,
      55,     6,    54,   179,   180,   181,    30,     6,    57,   169,
      54,   187,    55,    23,     6,    54,    54,     9,    10,    11,
      12,    55,    20,    15,    16,    56,   186,    19,    49,    21,
      22,   171,    49,   193,    26,    27,    28,     6,    50,    50,
       9,    10,    11,    12,     7,    18,    15,    16,    29,    45,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      -1,    53,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    43,    -1,    -1,    -1,    47,    -1,    49,    50,
      17,    18,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    57,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    57,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    33,    34,    35,    36,    37,    38,    54,
      40,    41,    42,    43,    44,    45,    46,    -1,    33,    34,
      35,    36,    37,    38,    54,    40,    41,    42,    43,    44,
      45,    46,    25,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    60,    61,    62,    63,
      66,     6,    14,     0,    62,     6,    49,    49,    49,    50,
      64,    65,    66,    50,    50,    64,    52,    67,    50,    51,
       6,    67,    67,    50,     6,    15,    16,    19,    21,    22,
      26,    27,    28,    53,    66,    68,    69,    71,    72,    67,
      65,    67,    49,    55,    56,    49,    49,    49,    49,    49,
      54,    54,     3,     4,     5,     6,     7,     8,    17,    18,
      31,    32,    43,    47,    49,    54,    74,     6,    56,    53,
      69,    54,    54,    50,    73,    74,    74,    74,    74,    74,
      74,    74,    66,    49,    56,    58,    49,    49,    49,    49,
      74,    74,    74,    33,    34,    35,    36,    37,    38,    40,
      41,    42,    43,    44,    45,    46,    54,    55,    57,    54,
      50,    51,    54,    57,    50,    50,    50,    50,     6,    50,
      73,    74,    30,    74,    74,    74,    74,    50,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,     6,    54,    74,    55,    54,    54,    67,    67,
      23,    50,    57,    50,    50,    50,    50,    55,    74,    20,
      49,    29,    52,    54,    19,    67,    74,    66,    73,    49,
      24,    56,    53,    74,    74,    74,    50,    25,    70,    57,
      67,    74,    50,    50,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     6,     5,     6,     5,
       5,     1,     3,     2,     1,     1,     1,     1,     3,     2,
       1,     2,     2,     2,     4,     7,     5,     5,     5,     7,
      11,     5,    13,     2,     2,     2,     3,     5,     4,     0,
       2,     2,     4,    10,     8,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: function_list  */
#line 54 "parser.y"
                  { root = (yyvsp[0].nPtr); }
#line 1494 "y.tab.c"
    break;

  case 3: /* function_list: function  */
#line 58 "parser.y"
             { (yyval.nPtr) = oprNode(';', 1, (yyvsp[0].nPtr)); }
#line 1500 "y.tab.c"
    break;

  case 4: /* function_list: function_list function  */
#line 59 "parser.y"
                             { (yyval.nPtr) = oprNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1506 "y.tab.c"
    break;

  case 5: /* function: main_func  */
#line 63 "parser.y"
              { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1512 "y.tab.c"
    break;

  case 6: /* function: type IDENTIFIER '(' param_list ')' block  */
#line 64 "parser.y"
                                               { (yyval.nPtr) = funcNode((yyvsp[-5].iValue), (yyvsp[-4].sValue), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1518 "y.tab.c"
    break;

  case 7: /* function: type IDENTIFIER '(' ')' block  */
#line 65 "parser.y"
                                    { (yyval.nPtr) = funcNode((yyvsp[-4].iValue), (yyvsp[-3].sValue), NULL, (yyvsp[0].nPtr)); }
#line 1524 "y.tab.c"
    break;

  case 8: /* function: TYPE_VOID IDENTIFIER '(' param_list ')' block  */
#line 66 "parser.y"
                                                    { (yyval.nPtr) = funcNode(4, (yyvsp[-4].sValue), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1530 "y.tab.c"
    break;

  case 9: /* function: TYPE_VOID IDENTIFIER '(' ')' block  */
#line 67 "parser.y"
                                         { (yyval.nPtr) = funcNode(4, (yyvsp[-3].sValue), NULL, (yyvsp[0].nPtr)); }
#line 1536 "y.tab.c"
    break;

  case 10: /* main_func: TYPE_VOID MAIN '(' ')' block  */
#line 71 "parser.y"
                                 { (yyval.nPtr) = funcNode(4, strdup("main"), NULL, (yyvsp[0].nPtr)); }
#line 1542 "y.tab.c"
    break;

  case 11: /* param_list: param  */
#line 75 "parser.y"
          { (yyval.nPtr) = oprNode(',', 1, (yyvsp[0].nPtr)); }
#line 1548 "y.tab.c"
    break;

  case 12: /* param_list: param_list ',' param  */
#line 76 "parser.y"
                           { (yyval.nPtr) = oprNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1554 "y.tab.c"
    break;

  case 13: /* param: type IDENTIFIER  */
#line 80 "parser.y"
                    { (yyval.nPtr) = declNode((yyvsp[-1].iValue), (yyvsp[0].sValue), NULL); }
#line 1560 "y.tab.c"
    break;

  case 14: /* type: TYPE_NUMBER  */
#line 84 "parser.y"
                { (yyval.iValue) = 0; }
#line 1566 "y.tab.c"
    break;

  case 15: /* type: TYPE_DECIMAL  */
#line 85 "parser.y"
                   { (yyval.iValue) = 1; }
#line 1572 "y.tab.c"
    break;

  case 16: /* type: TYPE_TRUTH  */
#line 86 "parser.y"
                 { (yyval.iValue) = 2; }
#line 1578 "y.tab.c"
    break;

  case 17: /* type: TYPE_STRING  */
#line 87 "parser.y"
                  { (yyval.iValue) = 3; }
#line 1584 "y.tab.c"
    break;

  case 18: /* block: '{' stmt_list '}'  */
#line 91 "parser.y"
                      { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1590 "y.tab.c"
    break;

  case 19: /* block: '{' '}'  */
#line 92 "parser.y"
              { (yyval.nPtr) = oprNode(';', 0); }
#line 1596 "y.tab.c"
    break;

  case 20: /* stmt_list: stmt  */
#line 96 "parser.y"
         { (yyval.nPtr) = oprNode(';', 1, (yyvsp[0].nPtr)); }
#line 1602 "y.tab.c"
    break;

  case 21: /* stmt_list: stmt_list stmt  */
#line 97 "parser.y"
                     { (yyval.nPtr) = oprNode(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1608 "y.tab.c"
    break;

  case 22: /* stmt: var_decl ';'  */
#line 101 "parser.y"
                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1614 "y.tab.c"
    break;

  case 23: /* stmt: arr_decl ';'  */
#line 102 "parser.y"
                   { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1620 "y.tab.c"
    break;

  case 24: /* stmt: IDENTIFIER '=' expr ';'  */
#line 103 "parser.y"
                              { (yyval.nPtr) = oprNode('=', 2, idNode((yyvsp[-3].sValue)), (yyvsp[-1].nPtr)); }
#line 1626 "y.tab.c"
    break;

  case 25: /* stmt: IDENTIFIER '[' expr ']' '=' expr ';'  */
#line 104 "parser.y"
                                           { (yyval.nPtr) = oprNode('=', 2, arrayAccessNode((yyvsp[-6].sValue), (yyvsp[-4].nPtr)), (yyvsp[-1].nPtr)); }
#line 1632 "y.tab.c"
    break;

  case 26: /* stmt: WRITE '(' expr ')' ';'  */
#line 105 "parser.y"
                             { (yyval.nPtr) = oprNode(WRITE, 1, (yyvsp[-2].nPtr)); }
#line 1638 "y.tab.c"
    break;

  case 27: /* stmt: WRITELINE '(' expr ')' ';'  */
#line 106 "parser.y"
                                 { (yyval.nPtr) = oprNode(WRITELINE, 1, (yyvsp[-2].nPtr)); }
#line 1644 "y.tab.c"
    break;

  case 28: /* stmt: IF '(' expr ')' block  */
#line 107 "parser.y"
                                      { (yyval.nPtr) = oprNode(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1650 "y.tab.c"
    break;

  case 29: /* stmt: IF '(' expr ')' block ELSE block  */
#line 108 "parser.y"
                                       { (yyval.nPtr) = oprNode(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1656 "y.tab.c"
    break;

  case 30: /* stmt: IF '(' expr ')' block ELSE IF '(' expr ')' block  */
#line 109 "parser.y"
                                                       { (yyval.nPtr) = oprNode(IF, 3, (yyvsp[-8].nPtr), (yyvsp[-6].nPtr), oprNode(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr))); }
#line 1662 "y.tab.c"
    break;

  case 31: /* stmt: WHILE '(' expr ')' block  */
#line 110 "parser.y"
                               { (yyval.nPtr) = oprNode(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1668 "y.tab.c"
    break;

  case 32: /* stmt: FOR '(' type IDENTIFIER FROM '(' expr TO expr opt_step ')' ')' block  */
#line 111 "parser.y"
                                                                           {
        (yyval.nPtr) = forNode((yyvsp[-10].iValue), (yyvsp[-9].sValue), (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
    }
#line 1676 "y.tab.c"
    break;

  case 33: /* stmt: BREAK ';'  */
#line 114 "parser.y"
                { (yyval.nPtr) = oprNode(BREAK, 0); }
#line 1682 "y.tab.c"
    break;

  case 34: /* stmt: CONTINUE ';'  */
#line 115 "parser.y"
                   { (yyval.nPtr) = oprNode(CONTINUE, 0); }
#line 1688 "y.tab.c"
    break;

  case 35: /* stmt: RETURN ';'  */
#line 116 "parser.y"
                 { (yyval.nPtr) = oprNode(RETURN, 0); }
#line 1694 "y.tab.c"
    break;

  case 36: /* stmt: RETURN expr ';'  */
#line 117 "parser.y"
                      { (yyval.nPtr) = oprNode(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 1700 "y.tab.c"
    break;

  case 37: /* stmt: IDENTIFIER '(' arg_list ')' ';'  */
#line 118 "parser.y"
                                      { (yyval.nPtr) = oprNode('C', 2, idNode((yyvsp[-4].sValue)), (yyvsp[-2].nPtr)); }
#line 1706 "y.tab.c"
    break;

  case 38: /* stmt: IDENTIFIER '(' ')' ';'  */
#line 119 "parser.y"
                             { (yyval.nPtr) = oprNode('C', 1, idNode((yyvsp[-3].sValue))); }
#line 1712 "y.tab.c"
    break;

  case 39: /* opt_step: %empty  */
#line 123 "parser.y"
                { (yyval.nPtr) = conNodeNumber(1); }
#line 1718 "y.tab.c"
    break;

  case 40: /* opt_step: STEP expr  */
#line 124 "parser.y"
                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1724 "y.tab.c"
    break;

  case 41: /* var_decl: type IDENTIFIER  */
#line 128 "parser.y"
                    { (yyval.nPtr) = declNode((yyvsp[-1].iValue), (yyvsp[0].sValue), NULL); }
#line 1730 "y.tab.c"
    break;

  case 42: /* var_decl: type IDENTIFIER '=' expr  */
#line 129 "parser.y"
                               { (yyval.nPtr) = declNode((yyvsp[-3].iValue), (yyvsp[-2].sValue), coerceReadForType((yyvsp[-3].iValue), (yyvsp[0].nPtr))); }
#line 1736 "y.tab.c"
    break;

  case 43: /* arr_decl: type '[' ']' IDENTIFIER '=' NEW type '[' expr ']'  */
#line 133 "parser.y"
                                                      { (yyval.nPtr) = arrayDeclNodeNew((yyvsp[-9].iValue), (yyvsp[-6].sValue), (yyvsp[-1].nPtr)); }
#line 1742 "y.tab.c"
    break;

  case 44: /* arr_decl: type '[' ']' IDENTIFIER '=' '{' arg_list '}'  */
#line 134 "parser.y"
                                                   { (yyval.nPtr) = arrayDeclNodeInit((yyvsp[-7].iValue), (yyvsp[-4].sValue), (yyvsp[-1].nPtr)); }
#line 1748 "y.tab.c"
    break;

  case 45: /* arg_list: expr  */
#line 138 "parser.y"
         { (yyval.nPtr) = oprNode(',', 1, (yyvsp[0].nPtr)); }
#line 1754 "y.tab.c"
    break;

  case 46: /* arg_list: arg_list ',' expr  */
#line 139 "parser.y"
                        { (yyval.nPtr) = oprNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1760 "y.tab.c"
    break;

  case 47: /* expr: NUMBER_LITERAL  */
#line 143 "parser.y"
                   { (yyval.nPtr) = conNodeNumber((yyvsp[0].iValue)); }
#line 1766 "y.tab.c"
    break;

  case 48: /* expr: DECIMAL_LITERAL  */
#line 144 "parser.y"
                      { (yyval.nPtr) = conNodeDecimal((yyvsp[0].dValue)); }
#line 1772 "y.tab.c"
    break;

  case 49: /* expr: TRUTH_LITERAL  */
#line 145 "parser.y"
                    { (yyval.nPtr) = conNodeTruth((yyvsp[0].bValue)); }
#line 1778 "y.tab.c"
    break;

  case 50: /* expr: STRING_LITERAL  */
#line 146 "parser.y"
                     { (yyval.nPtr) = strNode((yyvsp[0].sValue), false); }
#line 1784 "y.tab.c"
    break;

  case 51: /* expr: FSTRING_LITERAL  */
#line 147 "parser.y"
                      { (yyval.nPtr) = strNode((yyvsp[0].sValue), true); }
#line 1790 "y.tab.c"
    break;

  case 52: /* expr: IDENTIFIER  */
#line 148 "parser.y"
                 { (yyval.nPtr) = idNode((yyvsp[0].sValue)); }
#line 1796 "y.tab.c"
    break;

  case 53: /* expr: IDENTIFIER '[' expr ']'  */
#line 149 "parser.y"
                              { (yyval.nPtr) = arrayAccessNode((yyvsp[-3].sValue), (yyvsp[-1].nPtr)); }
#line 1802 "y.tab.c"
    break;

  case 54: /* expr: IDENTIFIER '.' LENGTH  */
#line 150 "parser.y"
                            { (yyval.nPtr) = oprNode(LENGTH, 1, idNode((yyvsp[-2].sValue))); }
#line 1808 "y.tab.c"
    break;

  case 55: /* expr: TO_DECIMAL '(' expr ')'  */
#line 151 "parser.y"
                              { (yyval.nPtr) = castNode(1, (yyvsp[-1].nPtr)); }
#line 1814 "y.tab.c"
    break;

  case 56: /* expr: TO_NUMBER '(' expr ')'  */
#line 152 "parser.y"
                             { (yyval.nPtr) = castNode(0, (yyvsp[-1].nPtr)); }
#line 1820 "y.tab.c"
    break;

  case 57: /* expr: READ '(' expr ')'  */
#line 153 "parser.y"
                        { (yyval.nPtr) = oprNode(READ, 1, (yyvsp[-1].nPtr)); }
#line 1826 "y.tab.c"
    break;

  case 58: /* expr: READLINE '(' expr ')'  */
#line 154 "parser.y"
                            { (yyval.nPtr) = oprNode(READLINE, 1, (yyvsp[-1].nPtr)); }
#line 1832 "y.tab.c"
    break;

  case 59: /* expr: IDENTIFIER '(' arg_list ')'  */
#line 155 "parser.y"
                                  { (yyval.nPtr) = oprNode('C', 2, idNode((yyvsp[-3].sValue)), (yyvsp[-1].nPtr)); }
#line 1838 "y.tab.c"
    break;

  case 60: /* expr: IDENTIFIER '(' ')'  */
#line 156 "parser.y"
                         { (yyval.nPtr) = oprNode('C', 1, idNode((yyvsp[-2].sValue))); }
#line 1844 "y.tab.c"
    break;

  case 61: /* expr: expr '+' expr  */
#line 157 "parser.y"
                    { (yyval.nPtr) = oprNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1850 "y.tab.c"
    break;

  case 62: /* expr: expr '-' expr  */
#line 158 "parser.y"
                    { (yyval.nPtr) = oprNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1856 "y.tab.c"
    break;

  case 63: /* expr: expr '*' expr  */
#line 159 "parser.y"
                    { (yyval.nPtr) = oprNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1862 "y.tab.c"
    break;

  case 64: /* expr: expr '/' expr  */
#line 160 "parser.y"
                    { (yyval.nPtr) = oprNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1868 "y.tab.c"
    break;

  case 65: /* expr: expr '%' expr  */
#line 161 "parser.y"
                    { (yyval.nPtr) = oprNode('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1874 "y.tab.c"
    break;

  case 66: /* expr: expr EQ expr  */
#line 162 "parser.y"
                   { (yyval.nPtr) = oprNode(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1880 "y.tab.c"
    break;

  case 67: /* expr: expr NE expr  */
#line 163 "parser.y"
                   { (yyval.nPtr) = oprNode(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1886 "y.tab.c"
    break;

  case 68: /* expr: expr '<' expr  */
#line 164 "parser.y"
                    { (yyval.nPtr) = oprNode('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1892 "y.tab.c"
    break;

  case 69: /* expr: expr '>' expr  */
#line 165 "parser.y"
                    { (yyval.nPtr) = oprNode('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1898 "y.tab.c"
    break;

  case 70: /* expr: expr LE expr  */
#line 166 "parser.y"
                   { (yyval.nPtr) = oprNode(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1904 "y.tab.c"
    break;

  case 71: /* expr: expr GE expr  */
#line 167 "parser.y"
                   { (yyval.nPtr) = oprNode(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1910 "y.tab.c"
    break;

  case 72: /* expr: expr AND expr  */
#line 168 "parser.y"
                    { (yyval.nPtr) = oprNode(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1916 "y.tab.c"
    break;

  case 73: /* expr: expr OR expr  */
#line 169 "parser.y"
                   { (yyval.nPtr) = oprNode(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1922 "y.tab.c"
    break;

  case 74: /* expr: '!' expr  */
#line 170 "parser.y"
               { (yyval.nPtr) = oprNode('!', 1, (yyvsp[0].nPtr)); }
#line 1928 "y.tab.c"
    break;

  case 75: /* expr: '-' expr  */
#line 171 "parser.y"
                            { (yyval.nPtr) = oprNode(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1934 "y.tab.c"
    break;

  case 76: /* expr: '(' expr ')'  */
#line 172 "parser.y"
                   { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1940 "y.tab.c"
    break;


#line 1944 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 175 "parser.y"


void yyerror(char *s) {
    fprintf(stderr, "Line %d: %s\n", lineno, s);
}
