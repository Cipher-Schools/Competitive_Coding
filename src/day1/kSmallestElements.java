package day1;


/*
  Assume for first K elements are minimum elements



  Start from k to n {

   Try to find the maximum element of this window and store at max

     element = take the current element in this window
     if (max  > element) {


// Some computation

    Perform shifting of elements by one to left side in 0 to k -1 (Exclusive)


//Putting the element at hole
        arr[k - 1] = element
     }

  }
 */
public class kSmallestElements {

/*
 T.C = O(nk)
 S.C = O(1)
 */
    public static void printKSmallestElements(int [] arr, int k) {

        for(int i = k; i < arr.length; i++) {

            int max = arr[k -1];
            int max_position = k - 1;

            for(int j = k - 2; j >= 0 ; j--) {
                if(arr[j] > max) {
                    max = arr[j];
                    max_position = j;
                }
            }

            int currentElement = arr[i];

            if(max > currentElement) {

                int m = max_position;
                while(m < k - 1) {
                    arr[m] = arr[m + 1];
                    m++;
                }
                arr[k - 1] = currentElement;
            }
        }

        for(int i = 0; i < k; i++) {
            System.out.print(arr[i] + "  ");
        }

    }

    public static void main(String[] args) {


        int [] arr = {300, 400, 250, 100, 800};

        printKSmallestElements(arr, 3);

    }
}
