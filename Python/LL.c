#include<stdio.h>
#include<conio.h>
typedef struct node
{
	int info;
	struct node *next;
} node;
node* create()
{
	node *head=NULL,*temp,*last;
	int val;
	do
	{
	printf("Enter the info vale ");
	scanf("%d",&val);
	temp=(node*)malloc(sizeof(node));
	temp->info=val;
	temp->next=NULL;
	if(head==NULL)
	{
		last=head=temp;
	}
	else	
	{
		last->next=temp;
		last=temp;
	}
	}while(val!=-1);	
return head;
}

node* traverse(node *head)
{
node *pr;
pr=head;
while(pr->next!=NULL)
	{printf("-> %d",pr->info);
	 pr=pr->next;
	}
}

void main()
{
	int choise;
	prinf("\t Enter your choise");
	printf("1 create Node \n");
	printf("2 traverse Node \n");
	printf("3 Maximum Value in a Node \n");	
	printf("4 exit");
	switch(choise)
		{
			case 1: create();
		}
}
	