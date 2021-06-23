package day7;


import java.util.HashMap;

public class MinimumWindow {


    //O(n)
    public static int findMinimumWindow(String s, String p) {


        HashMap<Character, Integer> pMap = new HashMap<>();

        for (int i = 0; i < p.length(); i++) {
            if (pMap.containsKey(p.charAt(i))) {
                int count = pMap.get(p.charAt(i));
                count++;
                pMap.put(p.charAt(i), count);
            } else {
                pMap.put(p.charAt(i), 1);
            }
        }

        int start = 0;
        int index = 0;
        int targetCount = p.length();
        int matchingCount = 0;
        HashMap<Character, Integer> sMap = new HashMap<>();
        int ansSize = 0;

        while (index < s.length()) {

            char ch = s.charAt(index);
            sMap.put(ch, sMap.getOrDefault(ch, 0) + 1);

            if (sMap.getOrDefault(ch, 0) <= pMap.getOrDefault(ch, 0)) {
                matchingCount++;
            }

            while (start < index && matchingCount == targetCount) {

                int tempAns = s.substring(start, index + 1).length();
                if (ansSize == 0 || tempAns < ansSize)
                    ansSize = tempAns;

                char beginCharacter = s.charAt(start);

                if(sMap.getOrDefault(beginCharacter, 0) == 1) {
                    sMap.remove(beginCharacter);
                } else {
                    sMap.put(beginCharacter, sMap.get(beginCharacter) - 1);
                }
                if(sMap.getOrDefault(beginCharacter, 0) < pMap.getOrDefault(beginCharacter, 0)) {
                    matchingCount--;
                }
                start++;
            }
            index++;
        }
        return  ansSize;
    }


    public static void main(String[] args) {

        String s = "avcgdjrtbacb";
        String p  = "ab";

        System.out.print(findMinimumWindow(s, p));
    }
}
