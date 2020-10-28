// C++ program for expression tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define maxsize 500
// An expression tree node
struct ExTree
{
	char value;
	struct ExTree* left, *right;
};
int top=-1;
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' )
		return true;
	return false;
}

// Utility function to do inorder traversal
void inorder(struct ExTree *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

// A utility function to create a new node
struct ExTree* newNode(int v)
{
	struct ExTree*temp =(struct ExTree*)malloc(sizeof(struct ExTree));
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}
struct ExTree** createStack()
{
  struct ExTree **stack=(struct ExTree **)malloc(maxsize*sizeof(struct ExTree *));
  //front =0;
  //rear=0;
	top=0;
  return stack;
}
void push(struct ExTree**stack,struct ExTree* newnode)
{
  if(top==maxsize-1)
  {
    return;
  }
//  if((rear+1)<maxsize)
    stack[top]=newnode;
    top++;
}
struct ExTree * pop(struct ExTree **stack)
{
  if(top==-1)
  {
    printf("\nstack is empty");
    exit(1);
  }
  struct ExTree * del=stack[top-1];
  top--;
  return del;
}


// Returns root of constructed tree for given
// postfix expression
struct ExTree* constructTree(char postfix[])
{
	struct ExTree ** st=createStack();
	struct ExTree *t, *t1, *t2;

	// Traverse through every character of
	// input expression
	for (int i=0; i<strlen(postfix); i++)
	{
		// If operand, simply push into stack
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			push(st,t);
		}
		else // operator
		{
			t = newNode(postfix[i]);

			// Pop two top nodes
			//t1 = st.top(); // Store top
			//st.pop();	 // Remove top
      t1=pop(st);
			//t2 = st.top();
			//st.pop();
      t2=pop(st);

			// make them children
			t->right = t1;
			t->left = t2;

			// Add this subexpression to stack
			push(st,t);
		}
	}

	// only element will be root of expression
	// tree
	//t = st.top();
	//st.pop();
  t=pop(st);
	return t;
}

// Driver program to test above
int main()
{
	//char postfix[] = "ab+ef*g*-";
	char*postfix=(char*)malloc(maxsize*sizeof(char));
	char*myStack=(char*)malloc(maxsize*sizeof(char));
	int top1=-1,count=0;
	printf("\n\t Enter postfix expression: ");
	scanf("%s",postfix);
	for(int i = 0; postfix[i] != '\0'; i++)
    	{
                 if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '/' && postfix[i] != '*')
                 {
			if(top1==maxsize-1)
			{
				printf("\n\t Stack is Full");
				return 0;
			}
			else
			{
				top1++;
				myStack[top1]=postfix[i];
				count++;
			}

                 }

                 else
                 {
                       	if(count>= 2)
                        {//Pop(&num2,&myStack);
				top1--;
                               	count--;
			}

                        else
                        {
                                printf("Invalid postfix expression\n");
                                //ClearStack(&myStack);
				return 0;
                                break;
                        }
                 }
    	}

	struct ExTree* r = constructTree(postfix);
	printf("infix expression is \n");
	inorder(r);
	return 0;
}
