%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "y.tab.h"

void yyerror(char *);
int lineno = 1;
%}

%option noyywrap

%x COMMENT

%%

"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"       { BEGIN(INITIAL); }
<COMMENT>\n         { lineno++; }
<COMMENT>.          { /* ignore */ }

"//"[^\n]*          { /* ignore single-line comments */ }

[ \t\r]+            { /* ignore whitespace */ }
\n                  { lineno++; }

"number"            { return TYPE_NUMBER; }
"decimal"           { return TYPE_DECIMAL; }
"truth"             { return TYPE_TRUTH; }
"string"            { return TYPE_STRING; }
"void"              { return TYPE_VOID; }

"main"              { return MAIN; }
"write"             { return WRITE; }
"writeline"         { return WRITELINE; }
"read"              { return READ; }
"readline"          { return READLINE; }

"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"from"              { return FROM; }
"to"                { return TO; }
"step"              { return STEP; }
"break"             { return BREAK; }
"continue"          { return CONTINUE; }
"return"            { return RETURN; }
"new"               { return NEW; }

"true"              { yylval.bValue = true; return TRUTH_LITERAL; }
"false"             { yylval.bValue = false; return TRUTH_LITERAL; }

"to_decimal"        { return TO_DECIMAL; }
"to_number"         { return TO_NUMBER; }

"=="                { return EQ; }
"!="                { return NE; }
"<="                { return LE; }
">="                { return GE; }
"&&"                { return AND; }
"||"                { return OR; }

"length"            { return LENGTH; }

[0-9]+\.[0-9]+       {
    yylval.dValue = atof(yytext);
    return DECIMAL_LITERAL;
}

[0-9]+               {
    yylval.iValue = atol(yytext);
    return NUMBER_LITERAL;
}

f\"([^\\\n\"]|\\.)*\" {
    yytext[yyleng - 1] = '\0';
    yylval.sValue = strdup(yytext + 2);
    return FSTRING_LITERAL;
}

\"([^\\\n\"]|\\.)*\" {
    yytext[yyleng - 1] = '\0';
    yylval.sValue = strdup(yytext + 1);
    return STRING_LITERAL;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sValue = strdup(yytext);
    return IDENTIFIER;
}

.                   { return (unsigned char)yytext[0]; }
%%
