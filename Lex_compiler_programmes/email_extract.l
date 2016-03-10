%{
#include<stdio.h>
#include<string.h>
char star[500];
extern FILE *yyin, *yyout;

//int x;
int k=0;
%}
x "rajkmaurya111@gmail.com"

%%
{x}  {k++; fprintf(yyout," %s ",star); printf("%s", yytext);}
.

%%

main()
{


yyin=fopen("email.txt", "r");
yylex();
fclose(yyin);

yyout=fopen("email_output.txt", "w");

fprintf(yyout,"hello %d %s ",k, yytext);

printf(" total email matched %d", k);
//fclose(yyout);

} 
