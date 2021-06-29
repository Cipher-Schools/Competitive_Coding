package day5;


import java.util.ArrayList;

public class GenerateSubSets {


    public static void  generateAllSubSets(int [] arr, ArrayList<Integer> ans, int begin) {


        printArrayList(ans);

        for (int i = begin; i < arr.length; i++) {
            ans.add(arr[i]);
            generateAllSubSets(arr, ans, i + 1);
            //backtrack
            ans.remove(ans.size() - 1);
        }
    }

    private static void printArrayList(ArrayList<Integer> ans) {
        for (int num : ans) {
            System.out.print(num + " ");
        }

        System.out.println();
    }


    public static void main(String[] args) {
        int arr [] = {1,2,3};

        generateAllSubSets(arr, new ArrayList<>(), 0);
    }
}
