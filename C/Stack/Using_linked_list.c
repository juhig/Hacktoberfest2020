#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top=0;
void push()
{
    struct node *newnode;
    int x,i;
    printf("How many push you want to make?\n");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    struct node *temp;
    if(top==0)
    {
        printf("Underflow\n");
    }
    else
    {
        temp=top;
        printf("poped element is %d\n",temp->data);
        top=top->next;
        free(temp);   
    }   
}
void peek()
{
    if(top==0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Topmost element is %d",top->data);  
    }
}
void display()
{
    struct node *traverse;
    traverse=top;
    if(top==0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements of Stack are\n");
        while(traverse!=0)
    {
        printf("%d\n",traverse->data);
        traverse=traverse->next;
    }
        
    }
}

void main()
{
     int a;

    while(a!=5)
    {
        printf("\nType 1 to push\nType 2 to Display\nType 3 to pop\nType 4 to peek\nType 5 to exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
        push();
        break;
        
        case 2:
        display();
        break;
        
        case 3:
        pop();
        break;

        case 4:
        peek();
        break;

        case 5:
        printf("Exited\n");
        break;

        default:
        printf("Wrong Choice!!");
        }
    }
}
