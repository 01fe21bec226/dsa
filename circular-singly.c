#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node *node;
node tail=NULL;
node getnode()
{
    node newnode;
    newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
        exit(0);
        printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
void insertEnd()
{
    node newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        tail->link=newnode;
    }
    else if(tail->link==tail)
    {
        tail->link=newnode;
        newnode->link=tail;
    }
    else
    {
        newnode->link=tail->link->link;
        tail->link->link=newnode;
        tail=tail->link;
    }
}
void insertFront()
{
    node newnode=getnode();
     if(tail==NULL)
    {
        tail=newnode;
        tail->link=newnode;
    }
    else if(tail->link==tail)
    {
        newnode->link=tail;
        tail->link=newnode;
        tail=newnode;

    }
    else 
    {
        newnode->link=tail->link->link;
        tail->link->link=newnode;
    }
}
void delFront()
{
    if(tail==NULL)
    {
        printf("nothing to delete\n");

    }
    else if(tail->link==tail)
    {
        tail=NULL;
        printf("deleted last element\n");
    }
   
    else
    {
      
        tail->link->link=tail->link->link->link;
        
    }

}
void delEnd()
{
     if(tail==NULL)
    {
        printf("nothing to delete\n");

    }
    else if(tail->link==tail)
    {
        tail=NULL;
        printf("deleted last element\n");
        return;
    }
    
    else
    {
        node cur;
        cur=tail;
        while(cur->link!=tail)
        {
            cur=cur->link;
        }
        tail->link=tail->link->link;
        tail=cur;
    }
}
void display()
{
    if(tail==NULL)
    {
        printf("nothing\n");
        return;
    }
    node cur;
    for(cur=tail->link->link;cur!=tail->link;cur=cur->link)
    {
        printf("%d->",cur->data);
    }
    printf("%d\n",cur->data);
}
int main()
{
    int temp;
    while(1)
    {
        printf("enter option\n1-insert front\t2-inf\t3-delf\t4-inend\t5-display\t6-exit\n");
        scanf("%d",&temp);
        switch(temp)
        {
            case 1:insertFront();
            break;
            case 2:insertEnd();
            break;
            case 3:delEnd();
            break;
            case 4:delFront();
            break;
            case 5:display();
            break;
            case 6:exit(0);
            break;
        }
       
    }
    printf("\n************\n****nullbite****\n*************\n");
     return 0;
}
