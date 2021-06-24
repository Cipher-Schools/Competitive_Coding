package day3;


public class Factorial {


    public static int fact(int n) {

        if(n == 1 || n == 0) {
            return 1;
        }

        int recursionAns = fact(n - 1); //1

        int biggerProblemAns = recursionAns * n; //1 * 2

        return biggerProblemAns;
    }

    public static int factUsingTailCall(int number, int ans) {

        if(number == 1) {
            return ans;
        }

        return factUsingTailCall(number - 1, ans * number);
    }


    public static void main(String[] args) {

        System.out.println(factUsingTailCall(5, 1));
    }
}
