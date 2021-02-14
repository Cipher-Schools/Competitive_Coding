package day2;


public class Nqueen {


    public static boolean placeQueens(int[][] grid, int i) { // i = 1, grid.length = 4

        if (i == grid.length) {
            //Print the grid
            for (int row = 0; row < grid.length; row++) {
                for (int col = 0; col < grid[0].length; col++) {
                    System.out.print(grid[row][col] + "   ");
                }
                System.out.println();
            }
            return true;
        }

        for (int k = 0; k < grid[0].length; k++) {
            if (isSafeToPlace(grid, i, k)) {
                grid[i][k] = 1;
                boolean isPlaced = placeQueens(grid, i + 1);
                if (isPlaced) {
                    return true;
                }
                //backtrack step
                grid[i][k] = 0;
            }
        }
        return false;


    }

    private static boolean isSafeToPlace(int[][] grid, int i, int k) { // i = 1, k = 0

        for (int row = 0; row < i; row++) {
            if (grid[row][k] == 1) {
                return false;
            }
        }

        int x = i;
        int y = k;

        //Check for left diagonal
        while (x >= 0 && y >= 0) {
            if (grid[x][y] == 1) {
                return false;
            }
            x--;
            y--;
        }

        x = i;
        y = k;
        while (x >= 0 && y < grid.length) {
            if (grid[x][y] == 1) {
                return false;
            }
            x--;
            y++;
        }

      return true;
    }


    public static void main(String[] args) {


        int n = 1;
        int [][] grid = new int[1][1];

        placeQueens(grid, 0);


    }
}
