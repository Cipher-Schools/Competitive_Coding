package day18;



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


/**
 * 0 - blocked
 * 1 - human
 * 2 - Zombie
 */
public class MakingZombies {



    public static int makingZombies(int [][] matrix) {

        Queue<Position> queue = new LinkedList<>();

        int totalCreatures = 0;
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j  < matrix[i].length; j++) {
                if(matrix[i][j] == 1 || matrix[i][j] == 2) {
                    totalCreatures++;
                }
                if(matrix[i][j] == 2) {
                    queue.add(new Position(i, j));
                }
            }
        }

        int zombies = 0;

        int time = 0;

        while (!queue.isEmpty()) {

            int size = queue.size();

            zombies  = zombies + size;

            if(zombies == totalCreatures) {
                return time;
            }

            time++;

            for(int i = 0; i < size; i++) {
                Position p = queue.poll();

                //Going down
                if(p.x + 1 < matrix.length && matrix[p.x + 1][p.y] == 1){
                    matrix[p.x + 1][p.y] = 2;
                    queue.add(new Position(p.x + 1, p.y));
                }

                //Going Up
                if(p.x - 1 >= 0 && matrix[p.x - 1][p.y] == 1) {
                    matrix[p.x - 1][p.y] = 2;
                    queue.add(new Position(p.x - 1, p.y));
                }

                //Going left
                if(p.y - 1 >= 0 && matrix[p.x][p.y - 1] == 1) {
                    matrix[p.x][p.y - 1] = 2;
                    queue.add(new Position(p.x, p.y - 1));
                }

                //Going right
                if(p.y  + 1 < matrix[0].length && matrix[p.x][p.y + 1] == 1) {
                    matrix[p.x][p.y + 1] = 2;
                    queue.add(new Position(p.x, p.y + 1));
                }
            }
        }
        return  -1;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows");

        int rows = sc.nextInt();

        System.out.println("Enter number of cols");

        int cols = sc.nextInt();

        int [][] matrix = new int[rows][cols];

        for(int i = 0; i  < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int value = sc.nextInt();
                matrix[i][j] = value;
            }
        }

        System.out.println(makingZombies(matrix));
    }

}
