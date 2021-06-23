package day5;


public class LargestSum {


    //T.C - O(N)
    public static int max = 0;
    public static int maximumSum(TreeNode root)  {

        if(root == null) {
            return  0;
        }
        int leftSum = maximumSum(root.left);
        int rightSum = maximumSum(root.right);

        max = Math.max(max, leftSum + rightSum + root.data);

        return leftSum + rightSum + root.data;
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(-10);

        TreeNode.takeInput(root);

        int max_sum = maximumSum(root);

        System.out.println(max);
    }
}
