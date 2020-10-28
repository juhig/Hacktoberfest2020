import java.util.ArrayList;
import java.util.List;
public class AdjacencyMatrix {
 int n;
 boolean[][] a;
 AdjacencyMatrix(int n0) {
 n = n0;
 a = new boolean[n][n];
 }
 public void addEdge(int i, int j) {
 a[i][j] = true;
 }
 public void removeEdge(int i, int j) {
 a[i][j] = false;
 }
 public boolean hasEdge(int i, int j) {
 return a[i][j];
 }
 //Mengetahui darimana arah ingoing edge
 List<Integer> outEdges(int i) {
 List<Integer> edges = new ArrayList<Integer>();
 for (int j = 0; j < n; j++)
 if (a[i][j]) edges.add(j);
 return edges;
 }

 //Mengetahui kemana arah outgoing edge
 List<Integer> inEdges(int i) {
 List<Integer> edges = new ArrayList<Integer>();
 for (int j = 0; j < n; j++)
 if (a[j][i]) edges.add(j);
 return edges;
 }
 public void printMatrix(){
 for (int i =0; i<a.length; i++){
 for(int j = 0; j<a[0].length; j++)
 System.out.print(a[i][j] + " ");
 System.out.println();
  }
 }
}

public class Main {
    public static void main(String[] args) {
    AdjacencyMatrix myMatrix = new AdjacencyMatrix(4);
   
    myMatrix.addEdge(0,1);
    myMatrix.addEdge(1,0);
    myMatrix.addEdge(1,2);
    myMatrix.addEdge(1,3);
    myMatrix.addEdge(2,3);
    myMatrix.printMatrix();
    System.out.println(myMatrix.inEdges(3));
    System.out.println(myMatrix.outEdges(3));
   }
   