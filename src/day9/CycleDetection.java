package day9;


import java.util.ArrayList;

public class CycleDetection {


    public static boolean isCycleAvailable(ArrayList<Integer> adjancyList[], int V) {


        boolean marked[] = new boolean[V];
        for (int i = 0; i < V; i++) {
            if (!marked[i])
                if (helper(adjancyList, i, marked, -1)) {
                    return true;
                }
        }
        return false;
    }


    private static boolean helper(ArrayList<Integer> adjancyList[], int source,
                                  boolean[] marked, int parent) {

        marked[source] = true;
        // System.out.print(v + " ");

        ArrayList<Integer> neighbours = adjancyList[source]; // 4, 3, 2
        for (Integer node : neighbours) {
            if (!marked[node]) {
                if (helper(adjancyList, node, marked, source)) {  //2 //4
                    return true;
                }
            } else if (node != parent) {  //2 //4
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

    }
}
