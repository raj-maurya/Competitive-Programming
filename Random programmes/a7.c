#include<stdio.h>
typedef struct
{
int s,m,h;
}time ;
time input()
{
time x;
scanf("%d %d %d",&x.h,&x.m,&x.s);
return(x);
}
output(time x)
{
printf("%d %d %d",x.h,x.m,x.s);
}
time diff(time x,time y)
{
time t;
if(x.s<y.s)
{
x.m-=1;
x.s+=60;
}
t.s=x.s-y.s;
if(x.m<y.m)
{
x.h-=1;
x.m+=60;
}
t.m=x.m-y.m;
t.h=x.h-y.h;
return(t);
}
main()
{
time a,b,c;
a=input();
b=input();
c=diff(a,b);
output(c);
}
