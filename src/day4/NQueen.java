package day4;

/**
 * 1. Place the queen row wise in the hope of reaching to the solution
 *
 * 2. Do the recursive call with changed state of board for rest of the board
 *
 * 3. If we reach to the solution, print the board
 *   else backtrack (restore to it's original state)
 */
public class NQueen {


    public static  boolean placeQueens(int [][] board, int row) {

        if(row == board.length) {
            //Print the board
            printBoard(board);

            System.out.println();
            System.out.println();
            return false;
        }

        for(int currentCellIndex = 0; currentCellIndex < board.length; currentCellIndex++) {

            if (isSafeToplace(board, row, currentCellIndex)) {
                board[row][currentCellIndex] = 1;

                boolean canPlaceQueens = placeQueens(board, row + 1);
                if (canPlaceQueens) {
                    return true;
                }
                //backtrack
                board[row][currentCellIndex] = 0;
            }
        }
        return  false;
    }

    private static void printBoard(int[][] board) {

        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[0].length; col++) {
                System.out.print(board[row][col] + "  ");
            }
            System.out.println();
        }
    }

    private static boolean isSafeToplace(int[][] board, int currentRow, int currentCellIndex) {
        for(int row = 0; row < currentRow; row++) {
            if(board[row][currentCellIndex] == 1) {
                return false;
            }
        }


        int x = currentRow;
        int y = currentCellIndex;

        //above left diagonal
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 1) {
                return false;
            }
            x--;
            y--;
        }

         x = currentRow;
         y = currentCellIndex;

        while(x >= 0 && y < board.length) {
            if(board[x][y] == 1) {
                return false;
            }
            x--;
            y++;
        }
        return true;

    }


    public static void main(String[] args) {

        int n = 4;

        int [][] board = new int[4][4];

        placeQueens(board, 0);
    }
}
