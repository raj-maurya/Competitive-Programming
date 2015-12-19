#include<stdio.h>
main()
{
	int a[20][3],b[20][20],p[10],q[10],r[10],n,i,j,k=0,g;
	printf("no of rows in compact");
	scanf("%d",&n);


	for(i=0;i<n;i++)
    {
	for(j=0;j<3;j++)
      {
	scanf("%d",&a[i][j]);
      }
    }


 for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
      {
	printf("\t%d",a[i][j]);
      }
	printf("\n");
    }



 for(i=1;i<n;i++)
    {
        for(j=0;j<3;j++)
      {
        p[k]=i;
	q[k]=j;
	r[k]=a[i][j];
	k++;
      }
         
    }
g=k;



for(i=0;i<g;i++)
    {
        for(j=0;j<a[0][1];j++)
      {
        if(b[i][j]|=0)
  {
        b[i][j]=0;
  }
      }

    }




k=0;
for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
      {
        b[p[k]][q[k]]=r[k];
	k++;
      }
        
    }
    
      
  
  
      

    
for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
      {
    	printf("\t%d",b[i][j]);
      }
	printf("\n");

    }

}
