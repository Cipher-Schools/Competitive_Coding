package day17;

/**
 * @author amgarg
 */
public class UniquePath {


    private int totalPaths = 0;

    public int getPaths(int m, int n) {
        moveHelper(m, n, 0, 0);
        return totalPaths;
    }

    private void moveHelper(int m, int n, int i, int j) {

        if(i >= m) {
            return;
        }

        if(j >= n) {
            return;
        }

        if(i == m - 1 && j == n - 1) {
            totalPaths++;
            return;
        }

        moveHelper(m, n, i + 1, j);
        moveHelper(m, n, i, j + 1);
    }

    public static void main(String[] args) {

    }
}
