#include<stdio.h>
#include<string.h>
main()
{
char str[50],rev[50] ;
int i,j,k,a,p,q;
printf("\nenter the string     ");
scanf(" %s",str);
a=strlen(str);//
printf(" the length of the string is=  %d",a);//

for(i=0; str[i]!='\0';i++)
k=i;
for(j=0; j<=i; j++)
{
rev[j]=str[k];
k--;
}
printf("\nthe reverse string is=    %s    ",rev);
}
