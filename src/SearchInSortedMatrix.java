import java.util.Scanner;

public class SearchInSortedMatrix {

    public static boolean isExist(int [][] matrix, int targetValue) {

        //Start from top right
        //if greater than target go to left
        //if smaller then go to down

        int i = 0;
        int j = matrix[0].length - 1;

        while (i < matrix.length && j >= 0) {
            if(matrix[i][j] == targetValue) {
                return true;
            }

            if(matrix[i][j] > targetValue) {
                j--; //left column
            } else {
                i++; // next row
            }
        }

        return false;
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

        System.out.println(isExist(matrix, target));
    }
}
