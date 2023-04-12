//doubly link list
#include<stdio.h>
int insert_front();
int insert_end();
int insert_random();
int delete_front();
int delete_end();
int delete_random();
int display();
struct node
{
    int val;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*temp=NULL;
int insert_front()
{
    int data;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("\n Nothing to print.");
    }
    else if(head==NULL)
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        ptr->next=head;
        ptr->prev=NULL;
        head=ptr;
    }
}
int insert_end()
{
    int data;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("\n Nothing to print.");
    }
    else if(head==NULL)
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        ptr->prev=temp->next;
        ptr->next=NULL;
    }
}
int display()
{
struct node *ptr;
ptr=head;
    if(ptr==NULL)
    {
        printf("\n Link list is Empty.");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n %d",ptr->val);
            ptr=ptr->next;
        }
    }
}
int main()
{
    int ch;
    do
    {
    printf("\n Enter your choice \n 1)Insert at begging \n 2)Insert at End \n 3)Display \n 4)Exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        insert_front();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        display();
        break;
    default :
        printf("\n Enter valid choice.");
    }
    }
    while(ch!=4);
}
