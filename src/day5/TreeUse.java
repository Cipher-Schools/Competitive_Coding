package day5;


import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class TreeUse {


    public static void inorderIterative(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();

        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            TreeNode node = stack.pop();
            System.out.println(node.data);
            root = node.right;
        }
    }

    public static void levelOrderTraversal(TreeNode root) {
        int height = getHeight(root);


        for (int i = 1; i <= height; i++) {
            printlevel(root, 1, i);
        }
    }

    private static void printlevel(TreeNode root, int currentLevel, int targetLevel) {

        if(root == null) {
            return;
        }
        if(currentLevel == targetLevel) {
            System.out.println(root.data);
            return;
        }

        printlevel(root.left, currentLevel + 1, targetLevel);
        printlevel(root.right, currentLevel + 1, targetLevel);

    }


    public static void levelOrderTraversalUsingQueue(TreeNode root) {

        Queue<TreeNode> queue = new LinkedList<>();

        queue.add(root);

        helper(queue);
    }

    private static void helper(Queue<TreeNode> currentQueue) {


        if(currentQueue.isEmpty()) {
            return;
        }

        Queue<TreeNode> queueForNextLevel = new LinkedList<>();

        while(!currentQueue.isEmpty()) {

            TreeNode node = currentQueue.poll(); //deque

            System.out.print(node.data +"  ");

            if(node.left != null) {
                queueForNextLevel.add(node.left);
            }

            if(node.right != null) {
                queueForNextLevel.add(node.right);
            }
        }

        System.out.println();

        helper(queueForNextLevel);
    }

    private static int getHeight(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }


    public static void inorderTraversal(TreeNode root) {

        if (root == null) {
            return;
        }
        inorderTraversal(root.left);
        System.out.println(root.data);
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);

        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);

        inorderTraversal(root);

        System.out.println();

        inorderIterative(root);

        System.out.println();

        levelOrderTraversal(root);

        System.out.println();


        levelOrderTraversalUsingQueue(root);
    }
}
