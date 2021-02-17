package day4;


import java.util.Deque;
import java.util.LinkedList;

public class MaximumInEachKWindow {


    //T.C - O(n)
    public static void printMaximum(int [] arr, int k) {

        Deque<Integer> deque = new LinkedList<>();

        int i;
        for(i = 0; i < k; i++) {

            while(!deque.isEmpty() && arr[i] >= arr[deque.peekLast()]) {
                deque.removeLast();
            }

            deque.addLast(i);
        }


        for(; i < arr.length; i++) {


            System.out.println(arr[deque.peek()]);


            //remove the elements from start which are outside of window

            if(!deque.isEmpty() && deque.peek() <= i - k) {
                deque.removeFirst();
            }


            while(!deque.isEmpty() && arr[i] >= arr[deque.peekLast()]) {
                deque.removeLast();
            }

            deque.addLast(i);
        }

        System.out.println(arr[deque.peek()]);


    }

    public static void main(String[] args) {

        int [] arr = {7, 6, 5, 4, 3, 2, 1};

        printMaximum(arr, 3);

    }
}
