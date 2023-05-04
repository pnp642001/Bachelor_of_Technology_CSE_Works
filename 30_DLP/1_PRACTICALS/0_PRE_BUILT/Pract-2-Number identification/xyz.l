bin (0|1)*
oct  [0-7]
char [A-Za-z]*
dec  [0-9]*
digit [0-9]
float {digit}+("."{digit}+)?
expo {digit}+("."{digit}+)?("E"("+"|"-")?{digit}+)?
hex  [0-9a-fA-f]+
%%
{bin} printf("\nEntered input is a binary number");
{oct} printf("\nEntered input is a Octal number");
{char} printf("\nEntered input is Char");
{dec} printf("\nEntered input is decimal number");
{float} printf("\nEntered input is float number");
{expo}  printf("\nEntered input is expo. number");
{hex} printf("\nEntered input is hex number");
%%
int yywrap()
{
  return 1;
}
int main()
{
  printf("Program by : \nPARTH PATEL\n19DCS098\n");
  printf("Enter the number to identify it's data-type:");
  yylex();
  return 0;
  }
