#include<stdio.h>
#include<stdlib.h>

int a[50],size=0;

void insertion(int ins,int pos)
{
	if(pos<1 || pos>size+1)
	{
		printf("invalid position\n");
	}
	else
	{
		for(int i=size;i>=pos;i--)
		{
			a[i]=a[i-1];
		}
		a[pos-1]=ins;
		size++;
	}
}

void deletion(int pos)
{
	if(pos<1 || pos>size)
	{
		printf("invalid position\n");
	}
	else
	{
		for(int i=pos-1;i<size-1;i++)
		{
			a[i]=a[i+1];
		}
		size--;
	}
}

void sort()
{
	int temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}

	}
}

int search(int value)
{
	int pos=0;
	for(int i=0;i<size;i++)
	{
		if(a[i]==value)
		{
			return i;
		}
	}
	return -1;
}

void display()
{
	printf("------ARRAY ELEMENTS------\n");
	for(int i=0;i<size;i++)
	{
		printf("%d \n",a[i]);
	}
}

int main()
{
	int ins,pos,value,choice;
	while(1)
	{
		printf("enter your choice\n 1.insert\n 2.delete\n 3.sort\n 4.search\n 5.dispaly\n 6.exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			printf("enter the element to insert: ");
			scanf("%d",&ins);
			printf("enter the position to insert: ");
			scanf("%d",&pos);
			insertion(ins,pos);
			break;

			case 2:
			printf("enter the position to delete: ");
			scanf("%d",&pos);
			deletion(pos);
			break;

			case 3:
			sort();
			break;

			case 4:
			printf("enter the element to search: ");
			scanf("%d",&value);
			pos=search(value);
			if(pos==-1)
			{
				printf("element not found\n");
			}
			else
			{
				printf("element found at %d th position\n",pos+1);
			}
			break;

			case 5:
			display();
			break;

			case 6:
			exit(0);

			default:
			printf("invalid choice\n");		
		}
	}
}
