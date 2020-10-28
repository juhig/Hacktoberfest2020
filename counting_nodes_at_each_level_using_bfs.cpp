
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n)  for(ll i = 0; i < (n); ++i)
#define rep1(i,n)  for(ll i = 1;i <= (n); ++i)
#define pb push_back
#define M 1000000007
class Graph
{
int V;
list<int>*adj;
	public:
			Graph(int V)
			{
				this->V=V;
				adj=new list<int>[V];	
			}	
			void addEdge(int u,int v)
			{
				adj[u].pb(v);
				adj[v].pb(u);
			}
			void bfs(int s,int l)
			{
				vector<bool>visited(V,false);
				int level[V]={0};
				list<int>queue;
				visited[s]=true;
				queue.push_back(s);
				level[s]=0;
				while(!queue.empty())
				{
					s=queue.front();
					queue.pop_front();	
				for(auto i=adj[s].begin();i!=adj[s].end();++i)
				{
					if(!visited[*i])
					{
						level[*i]=level[s]+1;
						visited[*i]=true;
						queue.push_back(*i);
					}
				}
				
			}
			int count=0;
			for(int i=0;i<V;i++)
			{
				if(level[i]==l)
				count++;
			}
			cout<<count;
			}
};
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
			Graph g(6);
			g.addEdge(0,1);
			g.addEdge(0,2);
			g.addEdge(1,3);
			g.addEdge(2,4);
			g.addEdge(2,5);
			int level=1;
			g.bfs(0,1);
	return 0;
}
