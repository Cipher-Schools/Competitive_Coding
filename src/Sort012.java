/**
 * Use three pointers
 *
 * left = 0
 * right = length - 1;
 * mid = 0;
 *
 *
 * run a loop from mid to high
 *
 *      if(a[mid] == 0) {
 *          swap with left
 *          left++;
 *          mid++;
 *      } else id( a[mid] == 1) {
 *          mid++;
 *      } else  {
 *          swap with right
 *          right--;
 *      }
 */
public class Sort012 {


    public static void sorting(int [] arr) {
        int left = 0;
        int right = arr.length - 1;
        int mid = 0;
        while(mid <= right) {
            if(arr[mid] == 0) {
                int temp = arr[left];
                arr[left] = arr[mid];
                arr[mid] = temp;
                left++;
                mid++;
            } else if(arr[mid] == 1) {
                mid++;
            } else {
                int temp = arr[mid];
                arr[mid] = arr[right];
                arr[right] = temp;
                right--;
            }
        }
    }


    private static void printArray(int [] arr) {
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "   ");
        }
    }

    public static void main(String[] args) {


        int [] arr = {0, 2, 1, 1, 2, 1, 0, 0, 2, 1, 0, 1, 2, 0, 0, 1, 2};

        sorting(arr);

        printArray(arr);


    }
}
