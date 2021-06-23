package day7;


import java.util.PriorityQueue;
import java.util.Scanner;

class ArrayContainer implements Comparable<ArrayContainer> {

    int arr[];
    int index;

    public ArrayContainer(int[] arr, int index) {
        this.arr = arr;
        this.index = index;
    }

    @Override
    public int compareTo(ArrayContainer o) {
        return this.arr[this.index] - o.arr[o.index];
    }
}

public class MergeKSortedArrays {


    //O(nlogn)
    public static int[] mergeArrays(int [][] matrix) {

        int total = 0;
        PriorityQueue<ArrayContainer> pq = new PriorityQueue<>();

        for(int i = 0; i < matrix.length; i++) {
            ArrayContainer arrayContainer = new ArrayContainer(matrix[i], 0);
            pq.add(arrayContainer);
            total = total + matrix[i].length;
        }

        int resultant[] = new int[total];
        int resultIndex = 0;

        while(!pq.isEmpty()) {
            ArrayContainer arrayContainer = pq.poll(); //log n

            resultant[resultIndex] = arrayContainer.arr[arrayContainer.index];
            resultIndex++;

            if (arrayContainer.index < arrayContainer.arr.length - 1) {
                ArrayContainer nextArrayContainer =
                        new ArrayContainer(arrayContainer.arr, arrayContainer.index + 1);
                pq.add(nextArrayContainer); // log n
            }
        }

        return  resultant;
    }


    public static void main(String[] args) {


        int [] arr1 = {1, 3, 5};
        int [] arr2 = {2,4,6,8};
        int [] arr3 = {9,15, 18, 20};

        int [] result = mergeArrays(new int[][] {arr1, arr2, arr3});

        for(int i = 0; i < result.length; i++) {
            System.out.print(result[i] + "  ");
        }
    }

}
