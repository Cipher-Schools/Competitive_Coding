package day2;

/**
 * @author amgarg
 */
public class SearchInSortedMatrix {


    /**
     * int currentElement = Considering the top right corner
     * <p>
     * if(currentElement == elementToBeSearched) {
     * return true;
     * }
     * <p>
     * if(currentElement > elementToBeSearched) {
     * go left
     * } else {
     * go downward
     * }
     *
     * @param matrix
     * @param targetValue
     * @return
     */

    public static boolean isExist(int[][] matrix, int targetValue) {


        int i = 0;
        int j = matrix[0].length - 1;


        //i - representing number of rows
        //j - representing number of cols
        while (i < matrix.length && j >= 0) {
            int currentElement = matrix[i][j];

            if (currentElement == targetValue) {
                return true;
            }
            if (currentElement > targetValue) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }




    public static void main(String[] args) {

        int[][] matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};


        System.out.println(isExist(matrix, 8));

        System.out.println(isExist(matrix, -1));
    }
}