#include<stdio.h>

int main()
{

 int a[1000],b,t,i;
scanf("%d",&t);
for( i=0; i<t; i++)
{ 
scanf("\n%d",&a[i]);
}
for(i=0; i<t;i++)
if(a[i]%2==0)
{
b=a[i]/2 +1;
printf("\n%d",b);
}
else
{
b=(a[i]+1)/2 ;
printf("\n%d",b);
}

return 0;
}

