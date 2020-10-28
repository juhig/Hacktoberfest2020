import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstSearch {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int computers = 7;
        int[][] computer = {{1,2} , {2,3} , {1,5} , {5,2} , {5,6} , {4,7}};

        boolean[] visit = new boolean[computers+1];
        int[][] connected = new int[computers+1][computers+1];

        for (int i = 0; i < computer.length; i++) {
            int[] j = computer[i];
            connected[j[0]][j[1]] = 1;
            connected[j[1]][j[0]] = 1;
        }

        System.out.println(bfs(1 , connected , computers, visit));
    }

    private static int bfs(int k, int[][] connected , int computers, boolean[] visit) {
        int cnt = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(k);
        while (!q.isEmpty()) {
            int x = q.poll();
            //System.out.println(x);
            visit[x] = true;
            for (int i = 1; i <= computers; i++) {
                if (connected[x][i] == 1 && !visit[i]) {
                    q.offer(i);
                    visit[i] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
