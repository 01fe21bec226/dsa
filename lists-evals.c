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
Node inFirst(Node head)
{
    Node curhead;
    Node newnode;
    newnode=getNode();
    newnode->link=head;
    head=newnode;
    return head;
}
Node delend(Node head)
{
    if(head==NULL)
    {
        printf("nothing to del\n");

    }
    else if(head->link==NULL)
    {
        head=NULL;
    }
    else
    {
        Node cur=head;
        for(cur=head;cur->link->link!=NULL;cur=cur->link);
        cur->link=NULL;
    }
    return head;
}
Node delFirst(Node head)
{
    if(head==NULL)
    {
        printf("nothing to del\n");

    }
    else
    {
        head=head->link;
    }
}
Node delPos(Node head)
{
    Node cur;
    int pos,i;
    printf("enter pos\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        head=delFirst(head);
        return head;
    }
    for(cur=head,i=1; cur->link!=NULL&&i<pos-1; i++,cur=cur->link);
    cur->link=cur->link->link;
    return head;
}
Node insertPos(Node head)
{
    int pos,i;
    printf("enter the position\n");
    scanf("%d",&pos);
    //Node newnode=getNode();
    if(pos==1)
    {
        head=inFirst(head);
        return head;
    }
    Node cur;
    for(cur=head,i=1; cur->link!=NULL&&i<pos-1; i++,cur=cur->link);
    Node newnode=getNode();
    newnode->link=cur->link->link;
    cur->link->link=newnode;
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
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  printf("\n************\n****nullbite****\n*************\n");
    int n;
    Node head=NULL;
    while(1)
    {
        printf("enter choice\n1: insert end\t2:insert front\t3:insert pos\t4:del end\t5:del front\t6:del pos\t7: display\t8:exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:  head=inend(head);
            break;
            case 2: head=inFirst(head);
            break;
            case 3:  head=insertPos(head);
            break;
            case 4: head=delend(head);
            break;
            case 5:  head=delFirst(head);
            break;
            case 6: head=delPos(head);
            break;
            case 7:  printList(head);
            break;
            case 8: return 0;
            break;

        }

    }
   
    return 0;
}
