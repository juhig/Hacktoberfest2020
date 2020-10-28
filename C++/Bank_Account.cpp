#include <iostream>

using namespace std;
class Bank_Acnt
{
    char name[30];
    long int acc_no;
    char type[10];
    float balance;

public:

    Bank_Acnt(char a[10]="Savings",float b=0)
    {
       type[10]=a[10];
       balance=b;
    }

    void initialise()
    {
        cout<<"Enter your name :";
        cin>>name;
        cout<<"\nEnter your account no :";
        cin>>acc_no;
        cout<<"\nEnter your account type(savings,current,fixed deposit) :";
        cin>>type;
        cout<<"\n Enter your balance :";
        cin>>balance;
    }

    void deposit()
    {
        float b;
        cout<<"\nEnter the amount to be deposited :";
        cin>>b;
        balance+=b;
    }

    void withdraw()
    {
        float b;
        char q='y';
        do
        {
            cout<<"\nEnter the withdrawal amount :";
            cin>>b;
            if(b>balance)
                cout<<"\n SORRY!!!!!!!,The withdrawal amount is greater than the balance";
            else
                 {
                     balance-=b;
                  cout<<"\n The balance is :"<<balance;
                 }
            cout<<"\n Want to enter again(y/n)";
            cin>>q;


        }
        while(q=='y'|| q=='Y');

    }

    void info()
    {
        cout<<"\nYour Info";
        cout<<"\nYour Name -\t"<<name;
        cout<<"\nYour Balance-\t"<<balance;
    }
};

int main()
{
    Bank_Acnt b1;
    Bank_Acnt b2("fixed",10000);
    b2.initialise();
    b2.deposit();
    b2.withdraw();
    b2.info();

    return 0;
}
