package day3;

/**
 * @author amgarg
 */
public class MaximumElement {


    public static int findMaximum(int []arr, int index) {
        if(index < 0) {
            return Integer.MIN_VALUE;
        }

        int temp = findMaximum(arr, index - 1);
        int max = Math.max(temp, arr[index]);

        return max;
    }


    public static void main(String[] args) {
        int arr [] = {5,2 ,17, 13, 12, 15};

        System.out.println(findMaximum(arr, arr.length - 1));
    }
}
