package day2;


import java.util.Stack;

public class GeneratePaths {


    public static void generatePaths(int[][] matrix, int i, int j, Stack<Integer> path) {


        int m = matrix.length;
        int n = matrix[0].length;
        if ((i == m - 1) && (j == n - 1)) {
            //print the path
            path.add(matrix[i][j]);
            System.out.println(path);
            path.pop();
        }


        path.add(matrix[i][j]);




        //attempt to reach to solution
        //move to right
        if (j + 1 >= 0 && j + 1 < n) {
            generatePaths(matrix, i, j + 1, path);
        }


        //move to down
        if (i + 1 >= 0 && i + 1 < m) {
            generatePaths(matrix, i + 1, j, path);
        }

        path.pop();
    }


    public static void main(String[] args) {


        int[][] matrix = {{1, 2, 3}, {4, 5, 6,}, {7, 8, 9}};
        Stack<Integer> s = new Stack<>();

        generatePaths(matrix, 0, 0, s);
    }
}
