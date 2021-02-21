package day9;


import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Position {

    int x;
    int y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class MakeZombies {


    //O(m *n)
    public static int makingZombies(int[][] grid) {

        Queue<Position> q = new LinkedList<>();

        int totalCreatures = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1 || grid[i][j] == 2) {
                    totalCreatures++;
                }
                if (grid[i][j] == 2) {
                    q.add(new Position(i, j));
                }
            }
        }

        int time = 0;

        int zombies = 0;


        while (!q.isEmpty()) {

            int size = q.size();

            zombies += size;

            if (zombies == totalCreatures) {
                return time;
            }

            time++;

            for (int i = 0; i < size; i++) {

                //Position of zombie
                Position p = q.poll();

                //Down
                if (p.x + 1 < grid.length && grid[p.x + 1][p.y] == 1) {
                    grid[p.x + 1][p.y] = 2;
                    q.add(new Position(p.x + 1, p.y));
                }

                //Up
                if(p.x - 1 >= 0 && grid[p.x -1][p.y] == 1) {
                    grid[p.x - 1][p.y] = 2;
                    q.add(new Position(p.x - 1, p.y));
                }


                //Left
                if(p.y - 1 >=0 && grid[p.x][p.y - 1] == 1) {
                    grid[p.x][p.y - 1] = 2;
                    q.add(new Position(p.x , p.y - 1));
                }

                //Right
                if(p.y + 1 < grid[0].length && grid[p.x][p.y + 1] == 1) {
                    grid[p.x][p.y + 1] = 2;
                    q.add(new Position(p.x , p.y  + 1));
                }
            }

        }

        return  -1;
    }

    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows");
        int r = sc.nextInt();
        System.out.println("Enter number of cols");
        int c = sc.nextInt();
        int [][] matrix = new int[r][c];

        for(int i = 0; i < r; i++) {
            System.out.println("Enter elements for row" + i);
            for(int j = 0; j  < c; j++) {
                int element = sc.nextInt();
                matrix[i][j] = element;
            }
        }

        System.out.print(makingZombies(matrix));
    }
}
