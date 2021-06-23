package doubts;


import java.util.Scanner;

public class KSmallestElementInMatrix {


    //Space - O(1)
    public static int kSmallest(int [][] matrix, int k) {

        int cols = matrix[0].length;
        int rows = matrix.length;

        int low = matrix[0][0];
        int high = matrix[rows - 1][cols - 1];

        while(low < high) {
            int  mid = (low + high) / 2;
            int count = getCountSmallerEquals(matrix, mid);

            if(count >= k) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return  low;
    }

    /**
     * This function will be giving us the count the number
     * of element that are less than and equals to passed target
     * @return
     */
    private static int getCountSmallerEquals(int [][] matrix, int target)  {

        int cols = matrix[0].length;
        int rows = matrix.length;
        int count = 0;

        int row = rows -1;
        int col = 0;

        while(row >= 0 && col < cols) {

            if(matrix[row][col] <= target) {
                col++;
                count = count + (row + 1);
            } else {
                row--;
            }
        }
        return count;
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


        System.out.println("Enter the value to be searched");

        int target = sc.nextInt();

        System.out.println(kSmallest(matrix, target));


    }
}
