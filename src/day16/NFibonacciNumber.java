package day16;


public class NFibonacciNumber {


    public static int fibUsingRecursion(int n) {
        if(n < 2) {
            return n;
        }

        System.out.println(n - 1);

        int smallOutput1 = fibUsingRecursion(n - 1);

        System.out.println(n - 2);
        int smallOutput2 = fibUsingRecursion(n - 2);

        return (smallOutput1 + smallOutput2);
    }



    public static int fibUsingTopDown(int n, int dpMemory[]) {

        if(n == 0 || n == 1) {
            dpMemory[n] = n;
            return n;
        }

        if(dpMemory[n] != -1) {
            return dpMemory[n];
        }

        int smallOutput1 = fibUsingTopDown(n - 1, dpMemory);
        int smallOutput2 = fibUsingTopDown(n - 2, dpMemory);

        dpMemory[n] = smallOutput1 + smallOutput2;

        return  dpMemory[n];

    }

    public static int fibUsingBottomUp(int n) {

        int [] dpMemory = new int[n + 1];

        dpMemory[0] = 0;
        dpMemory[1] = 1;

        for(int i = 2; i <= n; i++) {
            dpMemory[i] = dpMemory[i - 1] + dpMemory [i - 2];
        }

        return dpMemory[n];

    }


    public static void main(String[] args) {

        int [] dp = new int[101];

        for(int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }

        //System.out.println(fibUsingRecursion(100));
     //   System.out.println(fibUsingTopDown(100, dp));

        System.out.println(fibUsingBottomUp(4));


   }




}
