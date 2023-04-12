#include<stdio.h>
int ins_front();
int ins_rear();
int ins_between();
int del_front();
int del_rear();
int del_between();
int disp();
int count();
struct node
{
    int val;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*last=NULL;
int main()
{
    int ch;
    do
    {
        printf("\n Enter your choice:\n 1)insert in front \n 2)insert in rear \n 3)insert in between \n 4)delete at front\n 5)delete at rear \n 6)delete in between \n 7)display \n 8)count \n 9)exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            ins_front();
            break;
  /*      case 2:
            ins_rear();
            break;
        case 3:
            ins_between();
            break;
        case 4:
            del_front();
            break;
        case 5:
            del_rear();
            break;
        case 6:
            del_between();
            break;          */
        case 7:
            disp();
            break;
  //      case 8:
   //         count();
   //         break;
        case 9:
            printf("\n THANK YOU.");
            break;
        default :
            printf("\n ENTER VALID CHOICE.");
            break;
    }

    }while(ch!=9);

}
int ins_front()
{
    struct node *ptr;
    int data;
    ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->next=NULL;
    ptr->prev=NULL;
    if(ptr==NULL)
        printf("\n Link list is underflow");
    else
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        if(head==NULL)
        {
            ptr->prev=head;
            ptr->next=last;
            head=last=ptr;
        }
        else
        {
            ptr->next=ptr;
            ptr->prev=head;
            head=ptr;
        }
    }
}
int disp()
{
    struct node *ptr=NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(head==NULL)
        printf("\n Link list is empty.");
    else
    {
        ptr=head;
        printf("\n printing values...");
        while(ptr->next!=last)
        {
            printf("\n%d",ptr->val);
            ptr=ptr->next;
        }
    }
}
