import java.util.*;
import java.lang.*;

class Graph {
	static int V;
	static LinkedList<Integer> adjlist[];
	
	Graph(int v){
		V=v;
		adjlist=new LinkedList[v];
		for(int i=0;i<v;i++) {
			adjlist[i]=new LinkedList<Integer>();
		}
	}
	
	public static void AddEdge(int a,int b){
		adjlist[a].add(b);
	}
	
	public static void dfs(int a,int vis[]) {
		System.out.println(a);
		vis[a]=1;
		Stack st=new Stack();
		st.add(a);
		int l=adjlist[a].size();
		for(int i=0;i<l;i++) {
			int a1=adjlist[a].get(i);
			if(vis[a1]==0) {
				dfs(a1,vis);
			}
		}
	}
	
	public static void main(String args[]) {
		Scanner s=new Scanner(System.in);
		System.out.println("Enter number of nodes:");
		int n=s.nextInt();
		Graph g=new Graph(n);
		System.out.println("Enter number of edges:");
		int e=s.nextInt();
		for(int i=0;i<e;i++) {
			System.out.println("Enter edge:");
			int x=s.nextInt();
			int y=s.nextInt();
			g.AddEdge(x, y);
		}
		
		int vis[]=new int[n];
		dfs(0,vis);
	}
}
