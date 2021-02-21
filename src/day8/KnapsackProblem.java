package day8;


public class KnapsackProblem {




    //2^n
    public  static int knapsackMemoziation(int [] wts, int [] vals, int  N, int W, int [][] dp) {

        if (N == 0 || W == 0) {
            return 0;
        }

        if(dp[N][W] != -1) {
            return dp[N][W];
        }


        if (wts[N - 1] <= W) {
            int remainingCapacity = W - wts[N - 1];
            int considerItem =   vals[N - 1] + knapsackMemoziation(wts, vals, N - 1, remainingCapacity, dp);
            int notConsiderItem = knapsackMemoziation(wts, vals, N - 1, W, dp);
            dp[N][W] = Math.max(considerItem, notConsiderItem);
        } else {
            int notConsiderItem = knapsackMemoziation(wts, vals, N - 1, W, dp);
            dp[N][W] = notConsiderItem;
        }
        return dp[N][W];
    }



    //N^2
    public static int maxProfitUsingDynamicApproach(int[] wts, int[] values, int N, int W) {

        int [][] dpMemory = new int[N + 1][W + 1];


        for(int i = 1; i < dpMemory.length; i++) {
            for(int j = 1; j < dpMemory[0].length; j++) {
                if(j >= wts[i -1]) {

                    int pickItemProfit = 0;
                    int non_pickItemProfit = 0;

                    int remainingCapacity = j - wts[i - 1];
                    pickItemProfit = values [i - 1] + dpMemory[i - 1][remainingCapacity];
                    non_pickItemProfit = dpMemory[i - 1][j];
                    dpMemory[i][j] = Math.max(pickItemProfit, non_pickItemProfit);
                } else {
                    //don't pick
                    dpMemory[i][j] = dpMemory[i - 1][j];
                }
            }
        }

       /* for(int i = 0; i < dpMemory.length; i++) {
            for(int j = 0; j < dpMemory[0].length; j++) {
                System.out.print(dpMemory[i][j] + "   ");
            }
            System.out.println();
        }*/
        return dpMemory[N][W];
    }


    public static int maxTarget(int[] wts, int[] values, int N, int W) {

        if (N == 0 || W == 0) {
            return 0;
        }

        int pick = 0;
        int dont_pick = 0;

        if (wts[N - 1] <= W) {
            int remainingCapacity = W - wts[N - 1];
            pick = values[N - 1] + maxTarget(wts, values, N - 1, remainingCapacity);
        } else {
            dont_pick = 0 + maxTarget(wts, values, N - 1, W);
        }

        int maxTarget = Math.max(pick, dont_pick);
        return maxTarget;
    }


    public static void main(String[] args) {

        int val[] = { 60, 100, 120 };
        int wt[] = { 10, 20, 30 };
        int W = 50;

        int [][] dp = new int[val.length + 1] [W + 1];

        for(int i = 0; i < dp.length; i++) {
            for(int j = 0; j < dp[i].length; j++) {
                dp[i][j] = -1;
            }
        }

       System.out.println(maxTarget(wt, val, val.length, W));


       System.out.println(knapsackMemoziation(wt, val, val.length, W, dp));

        System.out.println(maxProfitUsingDynamicApproach(wt, val, val.length, W));


    }

}
