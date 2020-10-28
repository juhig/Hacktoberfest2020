#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	//int freq;
	int height;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int key)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=key;
	//node->freq=0;
	node->height=1;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int height(struct Node *node)
{
	if(node==NULL)
		return 0;
	return node->height;
}

int max(int a,int b)
{
	return (a>b) ? a : b;
}

int getBalance(struct Node* node)
{
	if(node==NULL)
		return 0;
	return height(node->left)-height(node->right);
}

struct Node* rightRot(struct Node * node)
{
	struct Node* l=node->left;
	struct Node* r=l->right;

	l->right=node;
	node->left=r;

	node->height=max(height(node->left),height(node->right))+1;
	l->height=max(height(l->left),height(l->right))+1;
	return l;
}

struct Node* leftRot(struct Node *N)
{
	struct Node* r=N->right;
	struct Node *l=r->left;
	r->left=N;
	N->right=l;
	N->height=max(height(N->left),height(N->right))+1;
	r->height=max(height(r->left),height(r->right))+1;
	return r;
}

struct Node* insert(struct Node* node,int key)
{
	if(node==NULL)
	{
		return newNode(key);
	}
	if(node->data>key)
		node->left=insert(node->left,key);
	else if(node->data<key)
		node->right=insert(node->right,key);
	else
	{
		//node->freq+=1;
		return node;
	}
	node->height=1+max(height(node->left),height(node->right));
	int balance=getBalance(node);
	if(balance >1 && key<node->left->data)
	{
//		printf("\nThis is left left Rotation\n");
		return rightRot(node);
	}
	if(balance<-1 && key>node->right->data)
	{
//		printf("\nThis is right right Rotation\n");
		return leftRot(node);
	}
	if(balance>1 && key>node->left->data)
	{
//		printf("\nThis is left right Rotation\n");
		node->left=leftRot(node->left);
		return rightRot(node);
	}
	if(balance<-1 && key<node->right->data)
	{
//		printf("\nThis is right left Rotation\n");
		node->right=rightRot(node->right);
		return leftRot(node);
	}
	return node;
}

int inorder(struct Node* node,int *a,int i)
{
	if(node==NULL)
		return i;
	i=inorder(node->left,a,i);
	a[i]=node->data;
	i++;
	//printf("%d\t",node->data);
	i=inorder(node->right,a,i);
	return i;
}

struct Node* insertNodes(struct Node *root,int n)
{
	int data;
	while(n>0)
	{
		printf("\nEnter the data to be inserted\t");
		scanf("%d",&data);
		root=insert(root,data);
		n--;
	}
	return root;
}

void printArray(int *a,int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int mergeArray(int *c,int *a,int *b,int m,int n)
{
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			if(b[j]<a[i])
			{
				c[k]=b[j];
				j++;
			}
			else
			{
				c[k]=a[i];
				i++;
				j++;
			}
		}
		k++;
	}
	if(i!=m)
	{
		while(i<m)
		{
			c[k]=a[i];
			i++;
			k++;
		}
	}
	printf("\n");
	if(j!=n)
	{
		while(j<n)
		{
			c[k]=b[j];
			j++;
			k++;
		}
	}
	return k;
}

struct Node* arrayTree(int *a,int s,int e)
{
	if(s>e)
		return NULL;
	int m=(s+e)/2;
	struct Node *root=newNode(a[m]);
	root->left=arrayTree(a,s,m-1);
	root->right=arrayTree(a,m+1,e);
	return root;
}

void main()
{
	int m,n;
	struct Node *first=NULL,*second=NULL;
	printf("\nEnter the number of Nodes in 1st Tree\t");
	scanf("%d",&m);
	first=insertNodes(first,m);
	printf("\nEnter the number of Nodes in 2nd Tree\t");
	scanf("%d",&n);
	second=insertNodes(second,n);
	int *a=(int *)malloc(sizeof(int)*m);
	int *b=(int *)malloc(sizeof(int)*n);
	printf("\nInorder traversal of 1st Tree\n");
	inorder(first,a,0);
	printArray(a,m);
	printf("\nInorder traversal of 2nd Tree\n");
	inorder(second,b,0);
	printArray(b,n);
	int *c=(int *)malloc(sizeof(int)*(m+n));
	int k=mergeArray(c,a,b,m,n);
	c=(int *)realloc(c,sizeof(int)*(k-1));
//	printArray(c,k);
	struct Node* root=arrayTree(c,0,k);
	inorder(root,c,0);
	printf("\nThe Merge Tree is\n");
	printArray(c,k);
}
