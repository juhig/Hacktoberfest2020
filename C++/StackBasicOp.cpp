#include <iostream>

using namespace std;
#define MAX 8
int stack[MAX];
char charstack[MAX];
int top = -1, TOP = -1;

void push(void);
void pop(void);
int peek(void);
int isfull(int);
int isempty(int);
int pushchar(void);
void popchar(void);
void peekchar(void);

int main()
{
    int ch, n=1;
    char ans;
    cout<<"\n Stack Operation Menu:\n 1. Push integer\n 2. Pop integer\n 3. Peek integer\n 4. Push character\n 5. Pop character\n 6. Peek character\n 7. Exit\n";
    while (n==1)
    {
        cout<<"\n Which operation do you want to perform: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                int result = peek();
                if (result == -1)
                {
                    cout<<" Stack is Empty!\n";
                }
                else
                    cout<<" The top element is: "<< result <<endl;
                break;
            }
            case 4:
            {
                int Result = pushchar();
                if (Result == 0)
                {
                    cout<<" OVERFLOW! Stack is Full.\n";
                }
                else
                {
                    char s;
                    cout<<" Enter the character to be inserted: ";
                    cin>>s;
                    charstack[TOP] = s;
                    cout << s << " inserted successfully\n";
                }
                break;
            }
            case 5:
            {
                popchar();
                break;
            }
            case 6:
            {
                peekchar();
                break;
            }
            case 7:
            {
                exit(0);
            }
            default:
                cout<<" Choose from Operation 1-6 !!\n";
                break;
        }
        cout<<"\n Do you want to continue? (y/n): ";
        cin >>ans;
        if(ans=='y'||ans=='Y')
            n=1;
        else 
            n=0;
    }
    return 0;
}

void push()
{
    int ele;
    top++;
    if (isfull(top))
        cout<<" OVERFLOW! Stack is Full.\n";

    else
    {
        cout <<" Enter the element to be inserted: ";
        cin >>ele;
        stack[top] = ele;
        cout << ele << " inserted successfully\n";
    }
}

void pop()
{
    if (isempty(top))
    {
        cout<<" UNDERFLOW! Stack is Empty.\n";
    }
    else
    {
        cout << " Top element: " << stack[top]<<" deleted successfully\n ";
            top--;
    }
}

int peek()
{
    if (isempty(top))
        return -1;

    else
        return stack[top];
}

int pushchar()
{
    TOP++;
    if (isfull(TOP))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void popchar()
{
    if (isempty(TOP))
    {
        cout<<" UNDERFLOW! Stack is Empty.\n";
    }
    else
    {
        cout << " Top element: " << charstack[TOP] <<" deleted successfully\n";
        TOP--;
    }
}

void peekchar()
{
    if (isempty(TOP))
        cout<<" Stack is Empty.\n";

    else
        cout<<" The top element is: "<<charstack[TOP]<<endl;
}

int isfull(int Top)
{
    if (Top == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(int Top)
{
    if (Top == -1)
        return 1;

    else
        return 0;
}
