#include<stdio.h>

#define MAX_SIZE 50

int uni[MAX_SIZE],set1[MAX_SIZE],set2[MAX_SIZE];
int bitstringset1[MAX_SIZE],bitstringset2[MAX_SIZE],unionarray[MAX_SIZE],intersectionarray[MAX_SIZE];
int num,num1,num2,i,temp,exists,j=0,choice;

int isElementInSet(int element,int set[],int setSize);
void union_bitsring();
void intersection_bitstring();

void main()
{
printf("\nenter the size of the universal set: \n");
scanf("%d",&num);

while(num<=0 || num>MAX_SIZE)
{
    printf("\ninvalid size...\n");
    scanf("%d",&num);
}

printf("\nenter the elements of the universal set: \n");
for(j=0;j<num;)
{
    exists=0;
    printf("\nenter element %d: \n",j+1);
    scanf("%d",&temp);


if (isElementInSet(temp,uni,j))
{
    printf("\nelement already exist...\n");
    
}
else{
    uni[j]=temp;
    j++;
}
}

printf("\n------universal set------\n");
for(i=0;i<num;i++)
{
    printf("%d \n" ,uni[i]);
}

j=0;
printf("\nenter the size of set1: \n");
scanf("%d",&num1);

while(num1<=0 || num1>50 )
{
    printf("\ninvalid size...\n");
    scanf("%d",&num1);
}

printf("\nenter the elements of set1: \n");
for(j=0;j<num1;)
{
    exists=0;
    printf("\nenter element %d: \n",j+1);
    scanf("%d",&temp);


if (isElementInSet(temp,set1,j))
{
    printf("\nelement already exists...\n");
    
}
else
{
    set1[j]=temp;
    j++;
}
}

printf("\n------set 1------\n");
for(i=0;i<num1;i++)
{
    printf("%d \n",set1[i]);
}

j=0;
printf("\nenter the size of set2: \n");
scanf("%d",&num2);

while(num2<=0 || num2>50 )
{
    printf("\ninvalid size...\n");
    scanf("%d",&num2);
}

printf("\nenter the elements of set2: \n");
for(j=0;j<num2;)
{
    exists=0;
    printf("\nenter element %d: \n",j+1);
    scanf("%d",&temp);


if (isElementInSet(temp,set2,j))
{
    printf("\nelement already exists...\n");

}
else
{
    set2[j]=temp;
    j++;
}
}
printf("\n------set 2------\n");
for(i=0;i<num2;i++)
{
    printf("%d \n",set2[i]);
}

for(i=0;i<num;i++)
{
    bitstringset1[i]=isElementInSet(uni[i],set1,num1);
    bitstringset2[i]=isElementInSet(uni[i],set2,num2);
}

printf("\n------bitstring 1------\n");
for(i=0;i<num;i++)
{
    printf("%d",bitstringset1[i]);
}


printf("\n------bitstring 2------\n");
for(i=0;i<num;i++)
{
    printf("%d",bitstringset2[i]);
}

do
{
    printf("\nenter your choice: \n 1.union\n 2.intersection\n 3.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {

     case 1:
        union_bitsring();
        break;

     case 2:
        intersection_bitstring();
        break;

     case 3:
        printf("Exiting...\n");
        break;

     default:
        printf("invalid choice\n");
    }
}while (choice!=3);
}

int isElementInSet(int element,int set[],int setSize)
{
    for(int i=0;i<setSize;i++)
    {
        if(set[i]==element)
        {
            return 1;
        }
    }
    return 0;
}

void union_bitsring()
{
    printf("\nunion of bitstrings is: \n");
    for(i=0;i<num;i++)
    {
        unionarray[i]=bitstringset1[i] | bitstringset2[i];
        printf("%d",unionarray[i]);
    }
}

void intersection_bitstring()
{
    printf("\nintersection of bitstrings is: \n");
    for(i=0;i<num;i++)
    {
        intersectionarray[i]=bitstringset1[i] & bitstringset2[i];
        printf("%d",intersectionarray[i]);
    }
}
