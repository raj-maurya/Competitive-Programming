%{

int c=0;
%}

%%

to   c++;

(.|\n);
%%
main()
{
 yylex();
printf("Count of letter 'to' = %d\n",c); 
return 0;
}
