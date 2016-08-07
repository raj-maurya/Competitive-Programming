#include<stdio.h>
int main()
{
int  n,k,i,p=0,t;
scanf("%d%d",&n,&k);
for(i=0; i<n; i++)
{
scanf("%d",&t);
if(t%k==0)
p=p+1;
}
printf("%d",p);
return 0;
}
