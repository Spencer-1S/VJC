%{
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
%}

%union {
    long iValue;
    double dValue;
    bool bValue;
    char *sValue;
    nodeType *nPtr;
}

%token <iValue> NUMBER_LITERAL
%token <dValue> DECIMAL_LITERAL
%token <bValue> TRUTH_LITERAL
%token <sValue> IDENTIFIER STRING_LITERAL FSTRING_LITERAL

%token TYPE_NUMBER TYPE_DECIMAL TYPE_TRUTH TYPE_STRING TYPE_VOID
%token MAIN WRITE WRITELINE READ READLINE IF ELSE WHILE FOR FROM TO STEP
%token BREAK CONTINUE RETURN NEW LENGTH TO_DECIMAL TO_NUMBER
%token EQ NE LE GE AND OR

%nonassoc IFX
%nonassoc ELSE

%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS

%type <nPtr> program function_list function main_func param_list param
%type <nPtr> stmt_list stmt expr var_decl block arr_decl opt_step arg_list
%type <iValue> type

%%

program:
    function_list { root = $1; }
    ;

function_list:
    function { $$ = oprNode(';', 1, $1); }
    | function_list function { $$ = oprNode(';', 2, $1, $2); }
    ;

function:
    main_func { $$ = $1; }
    | type IDENTIFIER '(' param_list ')' block { $$ = funcNode($1, $2, $4, $6); }
    | type IDENTIFIER '(' ')' block { $$ = funcNode($1, $2, NULL, $5); }
    | TYPE_VOID IDENTIFIER '(' param_list ')' block { $$ = funcNode(4, $2, $4, $6); }
    | TYPE_VOID IDENTIFIER '(' ')' block { $$ = funcNode(4, $2, NULL, $5); }
    ;

main_func:
    TYPE_VOID MAIN '(' ')' block { $$ = funcNode(4, strdup("main"), NULL, $5); }
    ;

param_list:
    param { $$ = oprNode(',', 1, $1); }
    | param_list ',' param { $$ = oprNode(',', 2, $1, $3); }
    ;

param:
    type IDENTIFIER { $$ = declNode($1, $2, NULL); }
    ;

type:
    TYPE_NUMBER { $$ = 0; }
    | TYPE_DECIMAL { $$ = 1; }
    | TYPE_TRUTH { $$ = 2; }
    | TYPE_STRING { $$ = 3; }
    ;

block:
    '{' stmt_list '}' { $$ = $2; }
    | '{' '}' { $$ = oprNode(';', 0); }
    ;

stmt_list:
    stmt { $$ = oprNode(';', 1, $1); }
    | stmt_list stmt { $$ = oprNode(';', 2, $1, $2); }
    ;

stmt:
    var_decl ';' { $$ = $1; }
    | arr_decl ';' { $$ = $1; }
    | IDENTIFIER '=' expr ';' { $$ = oprNode('=', 2, idNode($1), $3); }
    | IDENTIFIER '[' expr ']' '=' expr ';' { $$ = oprNode('=', 2, arrayAccessNode($1, $3), $6); }
    | WRITE '(' expr ')' ';' { $$ = oprNode(WRITE, 1, $3); }
    | WRITELINE '(' expr ')' ';' { $$ = oprNode(WRITELINE, 1, $3); }
    | IF '(' expr ')' block %prec IFX { $$ = oprNode(IF, 2, $3, $5); }
    | IF '(' expr ')' block ELSE block { $$ = oprNode(IF, 3, $3, $5, $7); }
    | IF '(' expr ')' block ELSE IF '(' expr ')' block { $$ = oprNode(IF, 3, $3, $5, oprNode(IF, 2, $9, $11)); }
    | WHILE '(' expr ')' block { $$ = oprNode(WHILE, 2, $3, $5); }
    | FOR '(' type IDENTIFIER FROM '(' expr TO expr opt_step ')' ')' block {
        $$ = forNode($3, $4, $7, $9, $10, $13);
    }
    | BREAK ';' { $$ = oprNode(BREAK, 0); }
    | CONTINUE ';' { $$ = oprNode(CONTINUE, 0); }
    | RETURN ';' { $$ = oprNode(RETURN, 0); }
    | RETURN expr ';' { $$ = oprNode(RETURN, 1, $2); }
    | IDENTIFIER '(' arg_list ')' ';' { $$ = oprNode('C', 2, idNode($1), $3); }
    | IDENTIFIER '(' ')' ';' { $$ = oprNode('C', 1, idNode($1)); }
    ;

opt_step:
    /* empty */ { $$ = conNodeNumber(1); }
    | STEP expr { $$ = $2; }
    ;

var_decl:
    type IDENTIFIER { $$ = declNode($1, $2, NULL); }
    | type IDENTIFIER '=' expr { $$ = declNode($1, $2, coerceReadForType($1, $4)); }
    ;

arr_decl:
    type '[' ']' IDENTIFIER '=' NEW type '[' expr ']' { $$ = arrayDeclNodeNew($1, $4, $9); }
    | type '[' ']' IDENTIFIER '=' '{' arg_list '}' { $$ = arrayDeclNodeInit($1, $4, $7); }
    ;

arg_list:
    expr { $$ = oprNode(',', 1, $1); }
    | arg_list ',' expr { $$ = oprNode(',', 2, $1, $3); }
    ;

expr:
    NUMBER_LITERAL { $$ = conNodeNumber($1); }
    | DECIMAL_LITERAL { $$ = conNodeDecimal($1); }
    | TRUTH_LITERAL { $$ = conNodeTruth($1); }
    | STRING_LITERAL { $$ = strNode($1, false); }
    | FSTRING_LITERAL { $$ = strNode($1, true); }
    | IDENTIFIER { $$ = idNode($1); }
    | IDENTIFIER '[' expr ']' { $$ = arrayAccessNode($1, $3); }
    | IDENTIFIER '.' LENGTH { $$ = oprNode(LENGTH, 1, idNode($1)); }
    | TO_DECIMAL '(' expr ')' { $$ = castNode(1, $3); }
    | TO_NUMBER '(' expr ')' { $$ = castNode(0, $3); }
    | READ '(' expr ')' { $$ = oprNode(READ, 1, $3); }
    | READLINE '(' expr ')' { $$ = oprNode(READLINE, 1, $3); }
    | IDENTIFIER '(' arg_list ')' { $$ = oprNode('C', 2, idNode($1), $3); }
    | IDENTIFIER '(' ')' { $$ = oprNode('C', 1, idNode($1)); }
    | expr '+' expr { $$ = oprNode('+', 2, $1, $3); }
    | expr '-' expr { $$ = oprNode('-', 2, $1, $3); }
    | expr '*' expr { $$ = oprNode('*', 2, $1, $3); }
    | expr '/' expr { $$ = oprNode('/', 2, $1, $3); }
    | expr '%' expr { $$ = oprNode('%', 2, $1, $3); }
    | expr EQ expr { $$ = oprNode(EQ, 2, $1, $3); }
    | expr NE expr { $$ = oprNode(NE, 2, $1, $3); }
    | expr '<' expr { $$ = oprNode('<', 2, $1, $3); }
    | expr '>' expr { $$ = oprNode('>', 2, $1, $3); }
    | expr LE expr { $$ = oprNode(LE, 2, $1, $3); }
    | expr GE expr { $$ = oprNode(GE, 2, $1, $3); }
    | expr AND expr { $$ = oprNode(AND, 2, $1, $3); }
    | expr OR expr { $$ = oprNode(OR, 2, $1, $3); }
    | '!' expr { $$ = oprNode('!', 1, $2); }
    | '-' expr %prec UMINUS { $$ = oprNode(UMINUS, 1, $2); }
    | '(' expr ')' { $$ = $2; }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Line %d: %s\n", lineno, s);
}
