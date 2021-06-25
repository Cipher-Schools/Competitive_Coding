package day4;


public class LargestNumberAfterKSwaps {


    static String max  = "0";

    public static String swap(String s, int i, int j) {

        char ith = s.charAt(i);
        char jth = s.charAt(j);

        String left = s.substring(0, i);
        String middle = s.substring(i + 1, j);
        String right = s.substring(j + 1);


        return  left + jth + middle + ith + right;
    }
    public static void findMaximum(String string, int k) {

        if(Integer.parseInt(string) > Integer.parseInt(max)) {
            max = string;
        }

        if(k == 0) {
            return;
        }

        for(int i = 0;  i < string.length(); i++) {
            for(int j = i + 1; j < string.length(); j++) {

                if(string.charAt(i) < string.charAt(j)) {
                    string = swap(string, i, j);
                    findMaximum(string, k - 1);
                    //backtrack to its original state
                    string = swap(string, i, j);
                }
            }
        }
    }


    public static void main(String[] args) {

        String s = "254";

        int k = 2;

        findMaximum(s, k);

        System.out.println(max);
    }
}
