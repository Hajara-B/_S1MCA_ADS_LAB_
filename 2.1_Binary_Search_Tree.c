#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
}

*root,*temp;

struct Node*createNode()
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the node: \n");
    scanf("%d",&newNode->data);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node*insertion(struct Node*root,struct Node*newNode)
{
    if(root==NULL)
    {
        return newNode;
    }
    if(newNode->data>root->data)
    {
        root->right=insertion(root->right,newNode);
    }
    else
    {
        root->left=insertion(root->left,newNode);
    }
        return root;
}

struct Node*left_most(struct Node*current)
{
    while(current && current->left !=NULL)
    {
        current=current->left;
    }
    return current;
}

struct Node*deletion(struct Node*root,int del)
{
    if(root==NULL)
    {
        return root;
    }
    if(del>root->data)
    {
        root->right=deletion(root->right,del);
    }
    else if(del<root->data)
    {
        root->left=deletion(root->left,del);
    }
    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp==root->left;
            free(root);
            return temp;
        }
        else
        {
            temp=left_most(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
        return root;
    }
}

void search(struct Node*root,int s_value)
{
    if(root==NULL)
    {
        printf("%d is not present in the tree.\n",s_value);
    }
    else
    {
        if(s_value==root->data)
        {
            printf("%d is present in the tree.\n",s_value);
        }
        else if(s_value>root->data)
        {
            search(root->right,s_value);
        }
        else
        {
            search(root->left,s_value);
        }
    }
}

void inorder_traversal(struct Node*root)
{
    if(root!=NULL)
    {
    inorder_traversal(root->left);
    printf("%d",root->data);
    inorder_traversal(root->right);
    }
}
void preorder_traversal(struct Node*root)
{
    if(root!=NULL)
    {
      printf("%d",root->data);
      preorder_traversal(root->left);
      preorder_traversal(root->right);
    }
}
void postorder_traversal(struct Node*root)
{
    if(root!=NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d",root->data);
    }
}

void traversal(struct Node*root)
{
    int choice;
    printf("\n------ENTER YOUR CHOICE------\n 1-> INORDER-TRAVERSAL\n 2-> PREORDER-TRAVERSAL\n 3->POSTORDER-TRAVERSAL\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        inorder_traversal(root);
        break;

        case 2:
        preorder_traversal(root);
        break;

        case 3:
        postorder_traversal(root);
        break;

    }
}

int main()
{
    int choice,newNode,del,s_value;
    do
    {
    printf("\n------ENTER YOUR CHOICE------\n 1-> INSERTION\n 2-> DELETION\n 3->SEARCHING\n 4->TRAVERSAL\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        root=insertion(root,createNode());
        break;

        case 2:
        printf("Enter the node to be delete: \n");
        scanf("%d",&del);
        root=deletion(root,del);
        break;

        case 3:
        printf("Enter the node to be search: \n");
        scanf("%d",&s_value);
        search(root,s_value);
        break;

        case 4:
        traversal(root);
        break;
    }    
    }
    while (choice<5);
    }


