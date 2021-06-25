package day3;

import java.util.ArrayList;

/**
 * @author amgarg
 */
public class PrintKeyPadCombinations {


    public static String getValue(char c) {

        if(c == '1') {
            return "abc";
        }

        if(c == '2') {
            return "def";
        }

        if(c == '3') {
            return "ghi";
        }

        return null;
    }

    private static ArrayList<String> helper(String input) {


        if(input.length() == 0) {
            ArrayList<String> emptyList = new ArrayList<>();
            emptyList.add("");
            return emptyList;
        }


        String firstCharacterValue = getValue(input.charAt(0));

        ArrayList<String> smallerProblemCombinations = getAllCombinations(input.substring(1)); //null


        ArrayList<String> ans = new ArrayList<>();

        for(int i = 0; i < firstCharacterValue.length(); i++) {
            for(int j = 0; j < smallerProblemCombinations.size(); j++) {
                String combination = firstCharacterValue.charAt(i) + smallerProblemCombinations.get(j);
                ans.add(combination);
            }
        }

        return ans;
    }


    public static ArrayList<String> getAllCombinations(String input) {

        if(input.length() == 0) {
            return new ArrayList<>();
        }

        return  helper(input);
    }


    public static void main(String[] args) {

        ArrayList<String> ans = getAllCombinations("123");



        for(String combination : ans) {
            System.out.println(combination);
        }
    }
}
