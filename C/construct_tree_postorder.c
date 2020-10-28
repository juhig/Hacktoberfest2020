//Construct a tree in postorder fashion.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
}

struct Node* getTree(int *a,int s,int e)                //construction of tree in postorder way!!
{
	int i;
	if(s>e)
	{
		return NULL;
	}
	struct Node *root=newNode(a[e]);
	for(i=e-1;i>s;i--)
	{
		if(a[e]>a[i])
			break;
	}
	root->right=getTree(a,i+1,e-1);
	root->left=getTree(a,s,i);
	return root;
}

void postorder(struct Node* root)                      //postorder traversal
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}

void getArray(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the array element\t");
		scanf("%d",&a[i]);
	}
}

void print(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void main()
{
	struct Node* root=NULL;
	int n;
	printf("\nEnter the number of nodes in tree\t");
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	printf("\nEnter the array elements as per postorder sequence\n");     //when you construct the tree  in postorder fashion and when you traverse it
	 																																			//in postorder way you will get the same result!!
	getArray(a,n);
	print(a,n);
	root=getTree(a,0,n-1);
	printf("\nAfter constructing tree using postorder traversal-(Postorder traversal)of tree is \n");
	postorder(root);
}
