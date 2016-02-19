%{

int e=0;

%}

x      [a-z A-Z 0-9]*@[a-z][.][a-z]{3,3}

%%
x e++;

%%

main()
{
yylex();
printf(" The no of emails in text file are= %d", e);


return 0;
}
