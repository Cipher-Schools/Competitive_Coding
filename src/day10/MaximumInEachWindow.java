package day10;


import java.util.Deque;
import java.util.LinkedList;

public class MaximumInEachWindow {

    /**
     * T.C - O(nk) where n is the number of elements in an array
     * S.C - O(n) where n is the number of elements in an array
     * @param arr
     * @param k
     */
    public static void printMaximum(int [] arr, int k) {
        Deque<Integer> deque = new LinkedList<>();

        int currentIndex  = 0;
        for(currentIndex = 0; currentIndex < k; currentIndex++) {

            while(!deque.isEmpty() && arr[currentIndex] >= arr[deque.peekLast()]) {
                deque.removeLast();
            }
            deque.addLast(currentIndex);
        }

        for(; currentIndex < arr.length; currentIndex++) {
            System.out.println(arr[deque.peek()]);

            while(!deque.isEmpty() && deque.peek() <= currentIndex - k) {
                deque.removeFirst();
            }

            while(!deque.isEmpty() && arr[currentIndex] >= arr[deque.peekLast()]) {
                deque.removeLast();
            }

            deque.addLast(currentIndex);
        }

        System.out.println(arr[deque.peek()]);

        while(!deque.isEmpty()) {
            deque.removeLast();
        }
    }

    public static void main(String[] args) {

        int [] arr = {1,2,3,4,5,6,7,8};

        printMaximum(arr, 3);
    }
}
