#include<iostream>
#include<string.h>
using namespace std;
class parse
{
int nt,t,m[20][20],i,s,n,p1,q,k,j;
char p[30][30],n1[20],t1[20],ch,b,c,f[30][30],fl[30][30];
public:
int scant(char);
int scannt(char);
void process();
void input();
};

int parse::scannt(char a)
{
int c=-1,i;
for(i=0;i<nt;i++)
{
if(n1[i]==a)
{
return i;
}
}
return c;
}

int parse::scant(char b)
{
int c1=-1,j;
for(j=0;j<t;j++)
{
if(t1[j]==b)
{
return j;
}
}
return c1;
}


void parse::input()

{
cout<<"Enter the number of productions:";
cin>>n;
cout<<"Enter the productions one by one"<<endl;
for(i=0;i<n;i++)
cin>>p[i];
nt=0;
t=0;
}

void parse::process()
{
for(i=0;i<n;i++)
{
if(scannt(p[i][0])==-1)
n1[nt++]=p[i][0];
}
for(i=0;i<n;i++)
{
for(j=3;j<strlen(p[i]);j++)
{
if(p[i][j]!='e')
{
if(scannt(p[i][j])==-1)
{
if((scant(p[i][j]))==-1)
t1[t++]=p[i][j];
}
}
}
}
t1[t++]='$';
for(i=0;i<nt;i++)
{
for(j=0;j<t;j++)
m[i][j]=-1;
}
for(i=0;i<nt;i++)
{
cout<<"Enter first["<<n1[i]<<"]:";
cin>>f[i];
}

for(i=0;i<nt;i++)
{
cout<<"Enter follow["<<n1[i]<<"]:";
cin>>fl[i];
}
for(i=0;i<n;i++)
{
p1=scannt(p[i][0]);
if((q=scant(p[i][3]))!=-1)
m[p1][q]=i;
if((q=scannt(p[i][3]))!=-1)
{
for(j=0;j<strlen(f[q]);j++)
m[p1][scant(f[q][j])]=i;
}
if(p[i][3]=='e')
{
for(j=0;j<strlen(fl[p1]);j++)
m[p1][scant(fl[p1][j])]=i;
}
}
for(i=0;i<t;i++)
cout<<"\t"<<t1[i];
cout<<endl;
for(j=0;j<nt;j++)
{
cout<<n1[j];
for(i=0;i<t;i++)
{
cout<<"\t"<<" ";
if(m[j][i]!=-1)
cout<<p[m[j][i]];
}
cout<<endl;
}
}

int main()
{
parse p;
p.input();
p.process();
}
