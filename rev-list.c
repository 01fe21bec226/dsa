#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *Node;
Node getNode()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
    if(newnode==NULL)
        exit(0);
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
Node inend(Node head)
{
    Node cur;
    Node newnode;
    newnode=getNode();

    if(head==NULL)
    {
     head=newnode;

    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    // printf("%d\n",cur->data);
    }

    return head;
}

void printList(Node head)
{
     Node cur=head;
    while(cur!=NULL)
        {
            printf("%d-->",cur->data);
            cur=cur->link;
        }
}
void revList(Node head)
{
    Node c1,c2;
    int temp;
    //c1=head;
    for(c1=head;c1->link!=NULL;c1=c1->link)
    {
        for(c2=c1->link;c2!=NULL;c2=c2->link)
        {
            temp=c1->data;
            c1->data=c2->data;
            c2->data=temp;
        }
    }
}
int main()
{
    int n;
    Node head=NULL;
    while(1)
    {
        printf("enter choice\n1: insert\t2: rev\t3:display\t4:exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:head=inend(head);
            break;
            case 2:revList(head);
            break;
            case 3:printList(head);
            break;
            case 4: exit(0);
            break;
        }
    }
     printf("\n************\n****nullbite****\n*************\n");
    return 0;
}
