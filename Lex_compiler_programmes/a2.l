%{
    int icount=0,factcount=0;
%}

%%

fact    factcount++;
i         icount++;
(.|\n)    ;

%%
main()
{
    yylex();
    printf("Count of \"fact\"= %d \nCount of letter 'i' = %d\n",factcount,icount);   
    return 0;
}
