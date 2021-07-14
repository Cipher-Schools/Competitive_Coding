package day18;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * @author amgarg
 */
public class Graph {

    int v;

    private ArrayList<Integer> adjancyList[];

    Graph(int V) {
        this.v = V;

        adjancyList = new ArrayList[v];

        for(int i = 0; i < v; i++) {
            adjancyList[i] = new ArrayList<>();
        }
    }

    public void addEdge(int source, int destination) {
        adjancyList[source].add(destination);
        adjancyList[destination].add(source);
    }


    public void dfs() {
        boolean marked [] = new boolean[this.v];

        for(int i = 0; i < v; i++) {
            if(!marked[i]) {
                dfsHelper(i, marked);
            }
        }
    }

    private void dfsHelper(int v, boolean[] marked) {
        marked[v] = true;
        System.out.println(v + "  ");
        ArrayList<Integer> neighbours = adjancyList[v];

        for(Integer vertex : neighbours) {
            if(!marked[vertex]) {
                dfsHelper(vertex, marked);
            }
        }
    }


    public void bfs() {
        boolean marked [] = new boolean[this.v];

        for(int i = 0; i < v; i++) {
            if(!marked[i]) {
                bfsHelper(i, marked);
            }
        }

    }

    private void bfsHelper(int v, boolean[] marked) {
        Queue<Integer> q = new LinkedList<>();

        marked[v] = true;

        q.add(v);

        while(!q.isEmpty()) {

            int vertex = q.poll();

            System.out.println(vertex + " ");

            for(Integer neighbourVertex : adjancyList[vertex]) {
                if(!marked[neighbourVertex]) {
                    marked[neighbourVertex] = true;
                    q.add(neighbourVertex);
                }
            }
        }
    }

    public static void main(String[] args) {

        Graph graph = new Graph(11);

        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(3, 10);
        graph.addEdge(2, 4);
        graph.addEdge(4, 5);
        graph.addEdge(5, 6);
        graph.addEdge(6, 7);
        graph.addEdge(6, 8);
        graph.addEdge(9, 6);

        graph.dfs();


        System.out.println("The below output will be based on bfs");

        graph.bfs();

    }



}
