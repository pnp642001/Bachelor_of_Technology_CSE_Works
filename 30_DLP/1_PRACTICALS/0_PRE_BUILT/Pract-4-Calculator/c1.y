%{
#include<ctype.h>
#include<stdio.h>
#define YYSTYPE double
%}
%token NUM

%left '+' '-'  
%left '*' '/'

%%

S : E '\n' { printf("Answer: %g \nEnter:\n", $1); }
;

E : E '+' E { $$ = $1 + $3;}
| E'-'E { $$=$1-$3;}
| E'*'E {$$=$1*$3;}
| E'/'E {$$=$1/$3;}
| NUM
;

%%

#include "lex.yy.c"

int main()
{
printf("\nPARTH PATEL\n19DCS098\n");
printf("Enter the expression: ");
yyparse();
}
yyerror (char * s)
{
printf ("% s \n", s);
exit (1);
}