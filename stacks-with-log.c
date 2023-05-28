#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//////////////////
//nullbitedev///
//////////////////
struct st
{
    int data[100];
    int top;
};

void push(struct st *sp,int n);
int pop(struct st *sp);
void display(struct st *sp);
int main()
{
    int x,f,a[100000],l,u;
    struct st s;
    struct st *sp;
    sp=&s;
    sp->top=-1;
    printf("enter the limit in which numbers to be generated in order of lower-uptrer limit");
    scanf("%d%d",&l,&u);
    printf("enter the number of random numbers to be generated\n");
    scanf("%d",&x);
    FILE *i=fopen("input2.txt","w");
    srand(time(0));
    for(f=0;f<x;f++)
    {
        a[f]=(rand()%(u-l+1))+l;
        fprintf(i,"%d ",a[f]);
        printf("%d ",a[f]);
    }
    fclose(i);
    int c=0;
    int ch,n,e,k,d,z;
    FILE *st = fopen("st.txt", "w");
    fclose(st);
    FILE *p = fopen("push.txt", "w");
    fclose(p);
    FILE *ptr = fopen("pop.txt", "w");
    fclose(ptr);
    FILE *o = fopen("opr.txt", "w");
    fclose(o);
    while(1)
    {
        printf("\n1:PUSH\t 2:POP\t 3:DISPLAY\t 4:EXIT");
        printf("\nenter the number\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:c=c+1;
                   printf("c %d\n",c);
                i=fopen("input2.txt","r");
                e=0;
                while(fscanf(i,"%d",&n)!=EOF)
                {
                    e++;
                    if(e==c)
                    {
                        z=n;
                         printf("%d ",z);
                         push(sp,z);
                    }
                }
                fclose(i);
            break;
           case 2: k=pop(sp);
                    d=d+1;
                    if(k==-1)
                        printf("st underflow\n");
                    else
                        printf("poptred: %d",k);
            break;
           case 3: display(sp);
           break;
           case 4: exit(0);
           break;
        }
    }
  printf("\n***************\n******nullbitedev******\n*****************\n);
}

void push(struct st *sp,int n)
{
    FILE *st=fopen("st.txt","a");
    FILE *p=fopen("push.txt","a");
    FILE *o=fopen("opr.txt","a");
    sp->top++;
    sp->data[sp->top]=n;
    fprintf(st,"%d ",n);
    fprintf(p,"%d ",n);
    fprintf(o,"pushed: %d\n ",n);
    fclose(st);
    fclose(p);
    fclose(o);
}
int pop(struct st  *sp)
{
    int n,g;
    FILE *ptr=fopen("pop.txt","a");
    FILE *o=fopen("opr.txt","a");
    if(sp->top==-1)
        return -1;
    else
    {
        n=sp->data[sp->top];
        g=n;
        fprintf(ptr,"%d ",g);
        fprintf(o,"poptred: %d\n ",n);
        fclose(ptr);
    fclose(o);
        sp->top--;
        return n;
    }
}
//////////////////
////nullbitedev///
//////////////////
void display(struct st  *sp)
{
    int i;
    if(sp->top==-1)
                   printf("st is empty\n");
                else
                 {
                   for(i=sp->top;i>=0;i--)
                     {
                       printf("->%d",sp->data[i]);
                     }
                 }

}
