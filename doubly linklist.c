#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lptr;
    int data;
    struct node *rptr;
}*new=NULL,*head=NULL,*tail=NULL,*temp=NULL,*l=NULL,
*r=NULL;
void insert_first(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->lptr=NULL;
    new->rptr=NULL;
    if(head==NULL)
    {
        head=tail=l=r=new;
    }
    else
    {
        head->lptr=new;
        new->rptr=head;
        new->lptr=NULL;
        head=l=new;
    }
}
void insert_last(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->lptr=NULL;
    new->rptr=NULL;
    if(head==NULL)
    {
        head=tail=l=r=new;
    }
    else
    {
        tail->rptr=new;
        new->lptr=tail;
        new->rptr=NULL;
        tail=r=new;
    }
}
void delete(int x)
{
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            if(temp==head)
            {
                head=head->rptr;
                head->lptr=NULL;
            }
            else if(temp==tail)
            {
                tail=tail->lptr;
                tail->rptr=NULL;
            }
            else
            {
                temp->lptr->rptr=temp->rptr;
                temp->rptr->lptr=temp->lptr;
            }
            free(temp);
            return ;
        }
        temp=temp->rptr;
    }
    printf("%d element not Found!!",x);
}
void insert_ord(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->lptr=NULL;
    new->rptr=NULL;
    if(head==NULL)
    {
        head=tail=new;
        return ;
    }
    if(new->data <= head->data)
    {
        new->rptr=head;
        head->lptr=new;
        new->lptr=NULL;
        head=new;
        return ;
    }
    temp=head;
    while(temp!=NULL && new->data >= temp->data)
    {
        temp=temp->rptr;
    }
    if(temp==NULL)
    {
        tail->rptr=new;
        new->lptr=tail;
        tail=new;
        return ;
    }
    temp->lptr->rptr=new;
    new->rptr=temp;
    new->lptr=temp->lptr;
    return ;
}
int count()
{
    int count=0;
    temp=head;
    if(head==NULL)
    {
        return count;
    }
    while(temp->rptr != NULL && temp!=tail)
    {
        count++;
        temp=temp->rptr;
    }
    if(temp==tail)
        count++;
    return count;
    }
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->rptr;
    }
}
int main()
{
    int ch,n,m,del,od;
    while(1)
    {
        printf("\n1:insert at first\n2:insert at last\n3:insert at order sequeance\n4:delete\n5:display\n6:count node\n7:exit\n");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter your ele :");
            scanf("%d",&n);
            insert_first(n);
            break;
            case 2:
            printf("Enter your ele :");
            scanf("%d",&m);
            insert_last(m);
            break;
            case 3:
            printf("ENter element :");
            scanf("%d",&od);
            insert_ord(od);
            break;
            case 4:
            printf("ENter ele that you want to delete :");
            scanf("%d",&del);
            delete(del);
            break;
            case 5:
            display();
            break;
            case 6:
            n=count();
            printf("Your list has %d nodes",n);
            break;
            case 7:
            return 0;
            break;
            default:
            printf("Enter valid number....");
            break;
        }
    }
}

