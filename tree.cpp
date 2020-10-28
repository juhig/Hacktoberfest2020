#include<bits/stdc++.h>
using namespace std;
long long cmp;
typedef long double ld;
#define int long long
#define out_of_reach ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define mod 1000000007
// -----------------------------------------------------------------
struct bstnode
{
int data;
bstnode* left;
bstnode* right;
};
bstnode* new_node(int value)
{
bstnode* temp = new bstnode();
temp -> left = NULL;
temp -> right = NULL;
temp -> data = value;
return temp;
}
bstnode* insert(bstnode* root,int value)
{
if(root == NULL)
return root = new_node(value);
if(value < root->data)
root->left = insert(root->left,value);
if(value > root->data)
root->right = insert(root->right,value);
return root;
}
bool search(bstnode* root , int value)
{
if(root == NULL)
return false;
if(root->data == value)
return true;
if(value < root->data)
return search(root->left , value);
if(value > root->data)
return search(root->right , value);
}
signed main()
{
int t;
cin>>t;
while(t--)
{
bstnode* root = NULL;
int n,m,i,j,x;
cin>>n>>m;
rep(i,n)
{ cin>>x;
root = insert(root , x);
}
for(i=0; i<m; i++)
{
cin>>x;
if(search(root , x))
cout<<"YES\n";
else
{
cout<<"NO\n";
root = insert(root,x);
}
}
}
return 0;
}
