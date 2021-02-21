package day9;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph {

    private int V;


    private ArrayList<Integer> adjancyList[];


    public int getV() {
        return V;
    }

    public ArrayList<Integer>[] getAdjancyList() {
        return adjancyList;
    }

    Graph(int V) {
        this.V = V;

        adjancyList = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adjancyList[i] = new ArrayList<>();
        }
    }

    public void addEgde(int source, int destination) {
        adjancyList[source].add(destination);
        adjancyList[destination].add(source);
    }


    public void dfs() {

        boolean marked[] = new boolean[this.V];
        for (int i = 0; i < V; i++) {
            if (!marked[i])
                helper(i, marked);
            System.out.println();
        }
    }


    public void bfs() {

        boolean marked[] = new boolean[this.V];
        for (int i = 0; i < V; i++) {
            if (!marked[i])
                bfsHelper(i, marked);
        }

    }

    private void bfsHelper(int v, boolean[] marked) {
        Queue<Integer> q = new LinkedList<>();

        marked[v] = true;

        q.add(v);

        while(!q.isEmpty()) {
            int vertex = q.poll();
            System.out.print(vertex + " ");
            ArrayList<Integer> neighbours = adjancyList[v];

            for (Integer node : neighbours) {
                if (!marked[node]) {
                    marked[node] = true;
                    q.add(node);
                }
            }
        }
    }

    private void helper(int v, boolean[] marked) {

        marked[v] = true;
        System.out.print(v + " ");

        ArrayList<Integer> neighbours = adjancyList[v];
        for (Integer node : neighbours) {
            if (!marked[node]) {
                helper(node, marked);
            }
        }
    }


    public static void main(String[] args) {

        Graph g = new Graph(3);

        g.addEgde(0, 2);
        g.addEgde(1, 2);

        g.dfs();

        g.bfs();
    }


}
