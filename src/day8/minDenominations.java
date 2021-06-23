package day8;


public class minDenominations {



    //2^n
    public static int minCoinsUsingRecursion(int [] denominations, int amount) {


        if(amount == 0) {
            return 0;
        }

        int finalAns = Integer.MAX_VALUE;

        for(int i = 0; i < denominations.length; i++) {

            int currentDenomination = denominations[i];

            int remainingAmount = amount - currentDenomination;

            if(remainingAmount >= 0) {
                int smallAns = minCoinsUsingRecursion(denominations, remainingAmount); //0

                finalAns = Math.min(finalAns, smallAns + 1); //2
            }
        }

        return finalAns;
    }



    //N^2
    public static int minDenominationsUsingDynamic(int [] denominations, int amount) {

        int dp[][] = new int[amount + 1][denominations.length + 1];


        for(int i = 0; i <= amount; i++) {
            dp[i][0] = i;
        }

        //Filling the table
        for(int i = 1; i <= amount; i++) {
            for(int j = 1; j <= denominations.length; j++) {
                if(denominations[j - 1] <= i) {
                    int remainingAmount = i - denominations[j - 1];
                    int pastCoins = dp[remainingAmount][j];

                    int considerCurrentCoin = 1 + pastCoins;  //1
                    int notConsideringCurrentCoin = dp[i][j - 1]; //0

                    int minCoins = Math.min(considerCurrentCoin, notConsideringCurrentCoin);

                    //Save it memory
                    dp[i][j] = minCoins;
                } else {
                    //Not Considering this coin
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        for(int i = 0; i <= amount; i++) {
            for(int j = 0; j <= denominations.length; j++) {
                System.out.print(dp[i][j] + "   ");
            }
            System.out.println();
        }
        return dp[amount][denominations.length];
    }


    public static void main(String[] args) {

        int [] deno = {10,3,5};

        int amount = 10;

        System.out.println(minCoinsUsingRecursion(deno, amount));

        System.out.println(minDenominationsUsingDynamic(deno, amount));
    }
}
