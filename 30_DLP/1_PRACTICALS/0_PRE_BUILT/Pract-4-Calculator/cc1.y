%{
   #include<stdio.h>
   #include<ctype.h>
   #define YYSTYPE double
%}

%token NUM

%left '+' '-'
%left '*' '/'

%%
S :S E '\n' {printf("Ans:%g  \n Enter next exp.=",$2);}
|S '\n'
|
|error '\n' {yyerror("Error:Enter another exp."); yyerrok;}
;

E : E'+'E {$$=$1+$3;}
| E'-'E   {$$=$1-$3;}
| E'*'E   {$$=$1*$3;}
| E'/'E   {$$=$1/$3;}
| NUM
;
%%
#include "lex.yy.c"
int main()
{
  printf("Enter the exp.=");
  yyparse();
  return 0;
}
yyerror(char *s)
{
 printf("%s \n",s);
 exit(1);
}