#include<stdio.h>
    int main()
    {
    int a;
    float b;
    scanf("%d%f",&a,&b);
     
    if(a%5==0 && 0.5<=b-a)
    printf("%0.2f",b-a-0.5);
    else
    printf("%0.2f",b);
     
    return(0);
    }

