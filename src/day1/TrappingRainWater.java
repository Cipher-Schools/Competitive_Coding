package day1;

/**
 *
 * T.C = O(n)
 * S.C = O(n)
 * create left  and right side array with size n
 *
 * fill the left the array from 1 to n - 1 (Inclusive)
 *    if(input[i] > left [i - 1]) {
 *        left[i] = input[i];
 *    } else {
 *         left[i] = left[i - 1];
 *    }
 *
 *   fill the right the array from n - 1 to 0 (Inclusive)
 *      if(input[i] > right[i + 1]) {
 *         right[i] = input[i];
 *     } else {
 *           right[i] = right[i + 1];
 *     }
 *
 *     int totalWater = 0;
 *
 *     Traverse the main array and for every element
 *      totalWater = totalWater + (min(left[i], right[i]) - current element);
 *
 *
 */
public class TrappingRainWater {

    public static int totalWater(int [] arr) {

        int [] left = new int[arr.length];
        int [] right = new int [arr.length];

        //fill left array

        left[0] = arr[0];
        for(int i = 1; i < arr.length; i++) {
            left[i] = Math.max(left[i - 1], arr[i]);
        }

        right[arr.length - 1] = arr[arr.length - 1];
        for(int i = arr.length - 2; i >= 0; i--) {
            right[i] = Math.max(right[i  + 1], arr[i]);
        }

        int totalWater = 0;

        for(int i = 0; i < arr.length; i++) {
            totalWater  += Math.min(left[i], right[i]) - arr[i];
        }

        return totalWater;
    }


    public static void main(String[] args) {

        int [] arr = {3, 1, 0, 5, 2, 2};

        System.out.println(totalWater(arr));
    }
}
