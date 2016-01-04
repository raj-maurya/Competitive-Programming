#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

struct linked
{
    int count;
    char str[20];
    struct lnked  *next;
};

void print_index(struct linked *p)
{
    for(;p!=NULL;p++)
    {
        cout<<p->count<<"\t";
        cout<<p->str<<endl;
    }
}

void check(char str[],linked *l)
{
    int flag=0;
    struct linked *p;
    for(p=l;p!=NULL;p++)
        if(strcmp(str,p->str)==0)
        {
            p->count++;
            flag=1;
            break;
        }
       if(flag==1);
       else
       {
            p=new struct linked;
            p->count=0;
            (p->str,str);
            p->next=NULL;
       }
}
int main ()
{
    linked *l;
    char c;
    char str[20];
    FILE *f1;
    f1=fopen("Doc1.txt","r");
    if(!f1)
    {
        cout<<"\nFile not found...";
        return 0;
    }
    do
    {
        c=fscanf(f1,"%s",str);
        check(str,l);
    }while(c!=EOF);
    fclose(f1);
    print_index(l);
    return 0;
}
