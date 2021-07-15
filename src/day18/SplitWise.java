package day18;

/**
 * @author amgarg
 */
public class SplitWise {


    public static int minimum(int[] arr, int n)
    {
        int index = 0;
        int m = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < m)
            {
                m = arr[i];
                index = i;
            }
        }
        return index;
    }

    public static int maximum(int[] arr, int n)
    {
        int index = 0;
        int m = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > m)
            {
                m = arr[i];
                index = i;
            }
        }
        return index;
    }
    public static int[][] minCashFlow(int[][] transaction, int n)
    {
        int [] netAmount = new int[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                netAmount[i] += (transaction[j][i] - transaction[i][j]);
            }
        }

        int numberOfZero = 0;

        for (int i = 0; i < n; i++)
        {
            if (netAmount[i] == 0)
            {
                numberOfZero += 1;
            }
        }

        int[][] answer = new int[n][n];

        while (numberOfZero != n)
        {
            int minAmountIdx = minimum(netAmount, n);
            int maxAmountIdx = maximum(netAmount, n);

            //If  reciever wants more money than sender has
            if (netAmount[maxAmountIdx] > Math.abs(netAmount[minAmountIdx]))
            {
                answer[minAmountIdx][maxAmountIdx] = Math.abs(netAmount[minAmountIdx]);
                netAmount[maxAmountIdx] = netAmount[maxAmountIdx] - Math.abs(netAmount[minAmountIdx]);
                netAmount[minAmountIdx] = 0;
            }

            //If reciever wants less money than sender wants to send
            else if (netAmount[maxAmountIdx] < Math.abs(netAmount[minAmountIdx]))
            {
                answer[minAmountIdx][maxAmountIdx] = netAmount[maxAmountIdx];
                netAmount[minAmountIdx] = netAmount[minAmountIdx] + netAmount[maxAmountIdx];
                netAmount[maxAmountIdx] = 0;
            }
            else
            {
                answer[minAmountIdx][maxAmountIdx] = Math.abs(netAmount[minAmountIdx]);
                netAmount[maxAmountIdx] = 0;
                netAmount[minAmountIdx] = 0;
                numberOfZero += 1;
            }

            numberOfZero += 1;
        }

        return answer;
    }


    public static void main(String[] args) {


        int [][] matrix = { {0, 100, 0, 200},
               { 0, 0, 300, 0},
                {0 ,0, 0, 200},
                {0 ,0 ,0, 0}};

        int[][] answer = minCashFlow(matrix, 4);


        for(int i = 0; i < answer.length; i++) {
            for(int j = 0; j < answer[0].length; j++) {
                System.out.print(answer[i][j] +  "  ");
            }
            System.out.println();
        }


    }
}
