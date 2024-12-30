#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head=NULL;
void createList()
{
if (head==NULL)  
{
int n;
printf("\nEnter the number of nodes: ");
scanf("%d",&n);
if(n!=0)
{
int data;
struct node*newnode;
struct node*temp;
newnode=malloc(sizeof(struct node));
newnode->next=NULL;
head=newnode;
temp=head;
printf("\nEnter number to be inserted:\n");
scanf("%d",&data);
head->data=data;
for(int i=2;i<=n;i++)
{
newnode=malloc(sizeof(struct node));
newnode->next=NULL;
temp->next=newnode;
printf("\nEnter number to be inserted: ");
scanf("%d",&data);
newnode->data=data;
temp=temp->next;
}
}
printf("\nThe list is created\n");
}
else
printf("\nThe list is already created\n");  
}
void traverse()
{
struct node*current;
if(head=NULL)
{
    printf("\nThe list is empty");
}
else
{
    current=head;
    while(current!=NULL)
    {
        printf("Data=%d\n",current->data);
        current=current->next;
    }
}
}
void insertAtFront()
{
    int num;
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}
void insertAtEnd()
{
    int num;
    struct node*newnode,*current;
    newnode=malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
}
void insertAtPosition()
{
    int pos,num,i=1;
    struct node*newnode,*current;
    newnode=malloc(sizeof(struct node));
    printf("enter the position: ");
    scanf("%d",&pos);
    printf("enter the number to be inserted: ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    current=head;
    while(i<pos-1)
    {
    current=current->next;
    i++;
    }
    newnode->next=current->next;
    current->next=newnode;
}
void deleteFront()
{
    struct node*temp;
    if(head=NULL)
    {
        printf("the list is empty");
    }
    else
    {
    temp=head;
    head=head->next;
    free(temp);
    }
}
void deleteEnd()
{
    struct node*temp,*current;
    if(head=NULL)
    {
        printf("the list is empty");
    }
    else
    {
        current=head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        temp=current->next;
        current->next=NULL;
        free(temp);
    }        
}
void deletePosition()
{
    int pos,i=1;
    struct node*temp,*current;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("enter the position of the element to be deleted: ");
        scanf("%d",&pos);
        temp=malloc(sizeof(struct node));
        current=head;
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
            temp=current->next;
            current->next=temp->next;
            free(temp);

        }
}
void search()
{
    int key,found=-1;
    struct node*current=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("enter the element to be search: ");
        scanf("%d",&key);
        while(current!=NULL)
        {
            if (current->data==key)
            {
                found=1;
                break;
            }
            else
            {
                  current=current->next;

            }
        }
      
        if(found==1)
        {
            printf("yes,%d is present in the list",key);
        }
        else
        {
                    printf("no,%d is present in the list",key);

        }

    }
    
    
}
int main()
{
    createList();
    int choice;
    while(1)
    {
        printf("\n1.to display the elements\n");
        printf("2.insert at front\n");
        printf("3.insert at end\n");
        printf("4.insert at any position\n");
        printf("5.delete at front\n");
        printf("6.delete at end\n");
        printf("7.delete at any position\n");
        printf("8.to search\n");
        printf("9.exit\n");
        printf("enter your choice: \n");
        scanf("%d",&choice);
    switch(choice)
    {
        case1:traverse();
               break;
        case2:insertAtFront();
               break;
        case3:insertAtEnd();
               break;
        case4:insertAtPosition();
               break;
        case5:deleteFront();
               break;
        case6:deleteEnd();
               break;
        case7:deletePosition();
               break;
        case8:search();
               break;
        case9:exit(1);
               break;
        default:printf("invalid position");
    }
    }
    return 0;
}

       

