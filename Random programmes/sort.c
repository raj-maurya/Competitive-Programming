#include<stdio.h>

int main()
{
int a[5],i,pass,hold;
printf("enter the 5 elements");
for(i=0; i<5; i++)
{
scanf("%d",&a[i]);
}

for(pass=0; pass<5; pass++)
{

for(i=0; i<5-1; i++)
{
if(a[i]>a[i+1])
{
 hold=a[i];
a[i]=a[i+1];
a[i+1]=hold;
}
}
}
for(i=0; i<5; i++)
{
printf("%d",a[i]);
}
}
