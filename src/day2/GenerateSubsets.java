package day2;


import java.util.ArrayList;

public class GenerateSubsets {


    public static void generateAllSubsets(int [] arr, int begining, ArrayList<Integer> ans) {


        for(int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i));
        }
        System.out.println();


        for(int i = begining; i < arr.length; i++) {
            ans.add(arr[i]);
            generateAllSubsets(arr, i + 1, ans);
            ans.remove(ans.size() - 1);
        }
    }


    public static void main(String[] args) {

        int arr[] = {4,5,6};
        generateAllSubsets(arr, 0, new ArrayList<>());
    }
}
