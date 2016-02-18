%{
int c=0;

%}
%%

to c++;
%%

main()
{
yylex();
printf("the Count='%d'", c);
return 0;
}
