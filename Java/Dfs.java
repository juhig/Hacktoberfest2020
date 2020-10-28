import java.io.*;
import java.util.*;


class Dfs
{
    private int vertices;
    LinkedList<Integer> adjacencyList[];
    private List<Integer> visitedNodes = new ArrayList<Integer>();
    boolean visited[];

    Dfs(int v)
    {
        //create adjacencyList object
        adjacencyList = new LinkedList[v]; //length of the nodes;
        vertices = v; //to reuse v
        for(int i=0;i<v;i++)
        {
            adjacencyList[i] = new LinkedList<Integer>(); //create a node for each vertex
        }
        visited = new boolean[vertices];
    }
    void addEdge(int source, int target)
    {
        adjacencyList[source].add(target);//find the source node and add a link
        //System.out.println(adjacencyList[source]); // shows all by=ut first node
    }

    void dfsTraversal(int source)
    {
        visited[source] = true;
        visitedNodes.add(source);

        System.out.print(visitedNodes);

        Iterator<Integer> node = adjacencyList[source].listIterator();

        while(node.hasNext())
        {
            source = node.next();
            if(!visited[source])
                dfsTraversal(source);
        }

        //visit unrelated nodes

        for(int i = 0;i<vertices;i++)
        {
            if(!visited[i])
                dfsTraversal(i);
        }
    }

}

/*The given is used to traverse a graph in dfs
INPUT:
        g.addEdge(0,1);
	    g.addEdge(0, 3);
        g.addEdge(0, 4);
        g.addEdge(1, 4);
        g.addEdge(2, 0);
        g.addEdge(4, 5);
        g.addEdge(5, 0);
        g.addEdge(5, 1);
        g.dfsTraversal(0);
        
  OUTPUT:
        [0][0, 1][0, 1, 4][0, 1, 4, 5][0, 1, 4, 5, 2][0, 1, 4, 5, 2, 3]
    
*/
