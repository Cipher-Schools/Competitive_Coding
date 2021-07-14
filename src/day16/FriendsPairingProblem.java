package day16;

/**
 * @author amgarg
 */
public class FriendsPairingProblem {


    public static int getCount(int n) {
        int [] dp = new int[n + 1];

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <=n; i++) {
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {

        System.out.println(getCount(5));
    }
}
