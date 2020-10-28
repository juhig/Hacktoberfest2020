#include <bits/stdc++.h>
using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

class Graph
{
    int V;
    list<int> *adj;
    bool DFSUtil(int v, int color[]);

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w);
    void DFS();
};

// Constructor
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// Utility function to add an edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int u, int color[])
{
    // GRAY :  This vertex is being processed (DFS
    //         for this vertex has started, but not
    //         ended (or this vertex is in function
    //         call stack))
    color[u] = GRAY;
    cout << u << " ";
    for (auto v : adj[u])
    {
        if (color[v] == WHITE)
            DFSUtil(v, color)
    }
    // Mark this vertex as processed
    color[u] = BLACK;
}

void Graph::DFS()
{
    // Initialize color of all vertices as WHITE
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;

    // Do a DFS traversal beginning with all
    // vertices
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
            DFSUtil(i, color)
}

// Driver code to test above
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.DFS();
    return 0;
}
