#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
int size;
void push(int stack[]);
void pop(int stack[]);
void peek(int stack[]);
void display(int stack[]);
int main()
{
int ch,i;
printf("enter the size of the array: ");
scanf("%d",&size);
if(size>SIZE)
{
printf("size exceeds");
}
else
printf("enter the elements of the array: ");
for(i=0;i<size;i++)
{
scanf("%d",&stack[i]);
top++;
}
while(1)
{
printf(" enter your choice:1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push(stack);
        break;
case 2: pop(stack);
        break;
case 3: peek(stack);
        break;
case 4: display(stack);
        break;
case 5: return 0;
        break;
default:printf("invalid choice");
        break;
}
}
}
void push(int stack[])
{
int x;
if(top>=SIZE-1)
{
printf("overflow");
}
else
{
printf("enter the element to be inserted: ");
scanf("%d",&x);
}
top++;
stack[top]=x;
}

void pop(int stack[])
{
int y;
if(top==-1)
{
printf("underflow");
}
else
{
y=stack[top];
top--;
printf("the popped element is %d\n",y);
}
}
void peek(int stack[])
{
printf("the peek element is %d",stack[top]);
}
void display(int stack[])
{
int i,size;
printf("the array elements are: ");
for(i=0;i<=top;i++)
{
printf("%d\n",stack[i]);
}
}