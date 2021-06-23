package day8;


public class NthFibonacciNumber {


    // 2^n
    public static int fibUsingRecursion(int n) {
        if(n < 2) {
            return n;
        }

        int smallOutput1 = fibUsingRecursion(n- 1);
        int smallOutput2 = fibUsingRecursion(n- 2);

        return smallOutput1 + smallOutput2;
    }


    //Recursion +  Memoziation
    //O(n)
    public static int topDownFib(int n, int dpMemory[]) {


        if(n == 0 || n == 1) {
            dpMemory[n] = n;
            return n;
        }

        //Asking the past
        if(dpMemory[n] != - 1) {
            return dpMemory[n];
        }

        int smallOutput1 = topDownFib(n- 1, dpMemory);
        int smallOutput2 = topDownFib(n- 2, dpMemory);

        dpMemory[n] = smallOutput1 + smallOutput2;

        return dpMemory[n];

    }



    //Tabulation
    public static int bottomUp(int n) {

        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


    public static void main(String[] args) {

        int dp[] = new int[101];
        for(int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }


        System.out.println(bottomUp(1));


        System.out.println(fibUsingRecursion(1));
    }



}
