package day9;


public class WordSearch {


   //  M^2 * N^2
    public static boolean isExist(char[][] grid, String word) {


        boolean[][] visited = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (word.charAt(0) == grid[i][j] && search(grid, word, i, j, 0, visited)) {
                    return  true;
                }
            }
        }
        return  false;
    }


    private static boolean search(char[][] grid, String word, int i, int j, int index, boolean[][] visited) {

        if (index == word.length()) {
            return true;
        }

        if (i >= grid.length || i < 0 || j >= grid[i].length || j < 0 || grid[i][j] != word.charAt(index) ||
                visited[i][j]) {
            return false;
        }

        visited[i][j] = true;

        if (search(grid, word, i - 1, j, index + 1, visited) ||
                search(grid, word, i + 1, j, index + 1, visited)
                || search(grid, word, i, j - 1, index + 1, visited) ||
                search(grid, word, i, j + 1, index + 1, visited)) {
            return true;
        }

        visited[i][j] = false;

        return false;

    }


    public static void main(String[] args) {


        char[][] grid = { { 'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S' },
                { 'G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K' },
                { 'I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E' } };



        System.out.print(isExist(grid, "ANT"));

    }
}
