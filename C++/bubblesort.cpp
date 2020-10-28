include <iosteam>

int main()
{
 int a[];
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
{
 cin>>a[i];
}
for(int i=0;i<n;i++)
{
 for(int j=i+1;j<n;j++)
{
 #sorting ascending order
 if(a[i]>a[j])
{
 int t=a[i];
 a[i]=a[j];
 a[j]=t;
}
}
}
for(int i=0;i<n;i++)
{
 cout<<a[i];
}