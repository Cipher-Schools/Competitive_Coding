package day6;


import day5.TreeNode;
import day5.TreeUse;

class TreeNodeInfo {
     boolean isBst;

     int size;

     int min;

     int max;

     TreeNodeInfo() {
         min = Integer.MAX_VALUE;
         max = Integer.MIN_VALUE;
         isBst = true;
         size = 0;
     }
 }

public class LargestBst {


    public static  int largestBstSize(TreeNode root) {
        TreeNodeInfo treeNodeInfo = helper(root);
        return treeNodeInfo.size;
    }

    private static TreeNodeInfo helper(TreeNode root) {

        if(root == null) {
            return new TreeNodeInfo();
        }

        TreeNodeInfo leftTreeNodeInfo = helper(root.left);

        TreeNodeInfo rightTreeNodeInfo = helper(root.right);

        TreeNodeInfo result = new TreeNodeInfo();

        if(leftTreeNodeInfo.isBst == false || rightTreeNodeInfo.isBst == false ||
                (leftTreeNodeInfo.max > root.data || rightTreeNodeInfo.min <= root.data)) {
            result.isBst = false;
            result.size = Math.max(leftTreeNodeInfo.size, rightTreeNodeInfo.size);
            return result;
        }

           result.isBst = true;
           result.size = leftTreeNodeInfo.size + rightTreeNodeInfo.size + 1;
           if(root.left != null) {
               result.min = leftTreeNodeInfo.min;
           } else {
               result.min = root.data;
           }

        if(root.right != null) {
            result.max = rightTreeNodeInfo.max;
        } else {
            result.max = root.data;
        }

        return result;
    }


    public static void main(String[] args) {

        TreeNode root = new TreeNode(15);

        root.left = new TreeNode(7);

        root.right = new TreeNode(8);

        root.left.left = new TreeNode(6);

        root.left.right = new TreeNode(9);

        root.right.right = new TreeNode(5);

        root.right.left = new TreeNode(11);

        root.right.left.left = new TreeNode(9);

        root.right.left.right = new TreeNode(13);

        root.right.left.left.left = new TreeNode(7);
        root.right.left.left.right = new TreeNode(10);


        TreeUse.levelOrderTraversalUsingQueue(root);

        System.out.println();


        System.out.println(largestBstSize(root));

    }

}
