package day2;


import java.util.ArrayList;
import java.util.List;

public class Permutation {


    //T.C = O(2^n)
    public static void generatePermutation(int[] arr, ArrayList<Integer> ans) { //123

        if (ans.size() == arr.length) {
            //print the ans
            System.out.println();
            for (int i = 0; i < ans.size(); i++) {
                int element = ans.get(i);
                System.out.print(element + "  ");
            }

          return;
        }

        for (int i = 0; i < arr.length; i++) {

            if (ans.contains(arr[i])) {
                continue;
            }
            ans.add(arr[i]);
            generatePermutation(arr, ans);
            ans.remove(ans.size() - 1);
        }
    }

    public static void main(String[] args) {

        int arr[] = {4,5,6};
        generatePermutation(arr, new ArrayList<>());
    }
}
