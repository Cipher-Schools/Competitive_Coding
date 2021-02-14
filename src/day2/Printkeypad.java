package day2;


import java.util.ArrayList;

public class Printkeypad {


    public static String getValue(char c) {

        if (c == '1') {
            return "abc";
        }
        if (c == '2') {
            return "def";
        }
        if(c == '3') {
            return "ghi";
        }

        return "";
    }


    public static ArrayList<String> getAllCombinations(String input) { //2

        if(input.length() == 0) {

            ArrayList<String> emptyList = new ArrayList<>();
            emptyList.add("");
            return emptyList;
        }

        String firstCharacterValue = getValue(input.charAt(0)); //def

        ArrayList<String> smallerproblemCombinations = getAllCombinations(input.substring(1)); // empty

        ArrayList<String> ans = new ArrayList<>();

        //n
        for(int i = 0; i < firstCharacterValue.length(); i++) {
            for(int j = 0; j < smallerproblemCombinations.size(); j++) {
                String output = firstCharacterValue.charAt(i) + smallerproblemCombinations.get(j);
                ans.add(output);
            }
        }
        return  ans;
    }


    public static void main(String[] args) {

        ArrayList<String> ans = getAllCombinations("123");


        for(String s : ans) {
            System.out.println(s);
        }
    }
}
