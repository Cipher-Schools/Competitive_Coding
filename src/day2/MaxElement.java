package day2;


public class MaxElement {

    public static int findMaximum(int [] arr, int index ) { //0


        if(index == arr.length - 1) {
            return arr[index];
        }

        int smallerProblemMax = findMaximum(arr, index + 1);

        int max = Math.max(arr[index], smallerProblemMax);

        return max;



    }

    public static void main(String[] args) {

        int [] arr = {5, 7, 1, 4, 3};

        System.out.println(findMaximum(arr, 0));
    }
}
