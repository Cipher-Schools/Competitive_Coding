package day1;


/**
 * 1. Assuming first k - 1 elements are smallest
 * <p>
 * 2. Let's start iteration from k element,
 * currentElement = array[k]
 * <p>
 * 2.1 let's find out max of 0..K, store it max along with it's index
 * 2.2 if(currentElement < max) {
 * do something with this window
 * <p>
 * shift one element to the left side till we reach to maxPosition
 * }
 */
public class KSmallestElements {


    //S.c - O(1)
    //T.C - O(nk) in worst case
    public static void kElements(int[] arr, int k) {

        int n = arr.length;
        for (int index = k; index < arr.length; index++) { //n
            int currentElement = arr[index];

            int max = arr[k - 1];
            int maxPosition = k - 1;
            for (int reverseIndex = k - 2; reverseIndex >= 0; reverseIndex--) { //k time
                if (arr[reverseIndex] > max) {
                    max = arr[reverseIndex];
                    maxPosition = reverseIndex;
                }
            }

            if (currentElement < max) {

                while (maxPosition < k - 1) { //  k times
                    arr[maxPosition] = arr[maxPosition + 1];
                    maxPosition++;
                }

                arr[k - 1] = currentElement;
            }
        }

        for (int i = 0; i < k; i++) {
            System.out.print(arr[i] + "  ");
        }
    }

    public static void main(String[] args) {


        int[] arr = {50, 50, 100, 30};

        kElements(arr, 2);

    }


}
