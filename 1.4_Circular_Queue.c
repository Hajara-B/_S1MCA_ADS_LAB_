#include<stdio.h>
#include<stdlib.h>
int q[50],size;
int rear=-1;
int front=-1;
int i;
void enqueue();
void dequeue();
void display();
int main()
{
printf("Enter the size of the array: ");
scanf("%d",&size);
printf("enter the array elements: ");
for(i=0;i<size;i++)
{
printf("%d",q[i]);
}
while(1)
{
int ch; 
printf("Enter your choice:1.enqueue\n2.dequeue\n3.display\n4.exit");
scanf("%d",&ch);
switch(ch);
{
case1:enqueue();
       break;
case2:dequeue();
       break;
case3:display();
       break;
case4:exit(0);
       break;
}
return 0;
}
}
void enqueue()
{
printf("enter the element to be inserted: ");
scanf("%d",&item);
if((rear+1)%size==front)
{
printf("overflow");
}
else if(front==-1)&&(rear==-1)
{
front=0
rear==0;
q[rear]=item;
}
else
{
rear=rear+1%size;
q[rear]=item;
}
}
void dequeue()
{
if(front==rear==-1)
{
printf("underflow");
}
else if(front==rear)
{
printf("the deleted element is %d",q[front]);
rear=-1;
front=-1;
}
else
{
printf("the deleted element is %d",q[front]);
front++;
}
}
void display()
{
int i;
if(front==rear==-1)
{
printf("underflow");
}
else
{
for(i=front;i<=rear;i++)
{
printf("%d",q[i]);
}
}
}