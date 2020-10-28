import java.util.*;

/**
 Topological sort example problem. Link: https://leetcode.com/problems/course-schedule/
*/

class TopSort {
    
    static boolean canFinish(int numCourses, int[][] prerequisites) {        
        HashMap<Integer, List<Integer>> adjList = new HashMap<>();
        int[] indegree = new int[numCourses];
        
        for (int[] pair: prerequisites) {
            int to = pair[0];
            int from = pair[1];
            List<Integer> list = adjList.getOrDefault(from, new ArrayList<>());
            
            list.add(to);
            adjList.put(from, list);
            indegree[to]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }
        
        int count = 0;
        while (!queue.isEmpty()) {
            count++;
            
            int node = queue.poll();
            if (adjList.containsKey(node)) {
                for (int nei : adjList.get(node)) {
                    indegree[nei]--;
                    if (indegree[nei] == 0) {
                        queue.add(nei);
                    }
                }
            }
        }
        
        return count == numCourses;
    }

    public static void main(String args[]) { 
        int numCourses = 2;
        int[][] prerequisites = {{1,0}, {0,1}};
        
        System.out.println("Answer: " +  canFinish(numCourses, prerequisites));  
    }   
}
