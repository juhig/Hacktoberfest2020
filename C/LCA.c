//Lowest Common Ancestor of two nodes
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}


struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);


    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);


    return node;
}
struct node *lca(struct node *root,int a,int b)
{
  struct node * left,*right;
  if(root==NULL)
    return root;
  if(root->key==a||root->key==b)
    return root;
  left=lca(root->left,a,b);
  right=lca(root->right,a,b);
  if(left && right)
    return root;
  else
    {
      if(left)
        return left;
      else if(right)
        return right;
    }

}

int main()
{
    int data;
    printf("\n\t Enter nodes press -1 to stop");
    struct node *root=NULL;
    while(1)
    {
      printf("\n\t Enter node ");
      scanf("%d",&data);
      if(data==-1)
        break;
      root=insert(root,data);
    }


    // print inoder traversal of the BST
    inorder(root);
    int a,b;
    char ch='y';
    

    while(ch=='y' || ch=='Y')
    {
    	printf("\n\t Enter two nodes to find lca: ");
    	scanf("%d %d",&a,&b);
    	struct node* temp=lca(root,a,b);
    	if(temp)
    	{
      		printf("LCA of %d and %d is: %d",a,b,temp->key);
    	}
    	else
        	printf("\n\tLCA of %d and %d doesn't exist",a,b);
	printf("\n\tDo you want to check LCA of two nodes again: ");
	getchar();
    	scanf("%c",&ch);

    }
    return 0;
 }
