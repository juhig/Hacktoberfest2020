/* Given a list of contacts which exist in a phone directory and a query string str.
The task is to implement search query for the phone directory.
Run a search query for each prefix p of the query string str(i.e from  index 1 to str length) that prints
all the distinct recommended contacts which have the same prefix as our query (p) in lexicographical order. 
Please refer the explanation part for better understanding.

NOTE: If there is no match between query and contacts , print "0".
*/

/* Explanation :
By running the query on contact list, we get, 
Suggestions based on "m" are: 
mongroovetest mondaytesting monkeytest 
Suggestions based on "mo" are:
mongroovetest mondaytesting monkeytest
Suggestions based on "mon" are:
mongroovetest mondaytesting monkeytest
Suggestions based on "monk" are:
monkeytest
No Results Found for "monka", So print "0".
No Results Found for "monkat", So print "0".    
*/








#define ll long long
using namespace std;
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
    for(int i=0;i<26;i++)
    child[i]=NULL;
        isEnd=false;
    }
};
void insert(TrieNode* root,string &key)
{ TrieNode* curr=root;
    for(int i=0;i<key.size();i++)
    {  int index=key[i]-'a';
        if(curr->child[index]==NULL)
        curr->child[index]=new TrieNode();
        curr=curr->child[index];
    }
    curr->isEnd=true;
}
int islastNode(TrieNode* root)
{
    for(int i=0;i<26;i++)
    {
        if(root->child[i])
        return 0;
    }
    return 1;
}
void partialsearch(TrieNode* curr,string key)
{
    if(curr->isEnd)
    {
        cout<<key<<' ';
    }
    if(islastNode(curr))
    return;
    for(int i=0;i<26;i++)
    {
        
        if(curr->child[i]!=NULL)
        {
           key.push_back(i+97);
           partialsearch(curr->child[i],key);
           key.pop_back();
           
        }
    }
    return;
}
int search(TrieNode* root,string &key)
{
    TrieNode *curr=root;
  
    for(int i=0;i<key.size();i++)
    {
        int index=key[i]-'a';
        if(curr->child[index]==NULL)
        return 0;
        curr=curr->child[index];
    }
    bool end=(curr->isEnd==true);
    bool last=islastNode(curr);
    if(end&& last)
    {cout<<key; return -1;}
    if(!last)
    {partialsearch(curr,key);
    return 1;}
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       string s;
       TrieNode* root=new TrieNode();
       for(int i=0;i<n;i++)
       {
            
            cin>>s; 
            insert(root,s);
       }
       string s1;
       cin>>s1;
       for(int i=1;i<=s1.length();i++)
       {
           string str=s1.substr(0,i);
           int temp=search(root,str);
           if(!temp)
           cout<<temp;
       cout<<endl;
       }
    }
	//code
	return 0;
}
