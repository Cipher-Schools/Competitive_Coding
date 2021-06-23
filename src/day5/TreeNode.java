package day5;


import java.util.Scanner;

public class TreeNode {

    public int data;

    public TreeNode left;

    public  TreeNode right;

    TreeNode next;

    public TreeNode(int data) {
        this.data = data;
    }


    public static void takeInput(TreeNode root) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Is left child of node available " + root.data);
        boolean isLeft = sc.nextBoolean();

        if(isLeft) {
            System.out.println("Enter the left child for " + root.data);
            int data = sc.nextInt();
            TreeNode node = new TreeNode(data);
            root.left = node;
            takeInput(root.left);
        }

        System.out.println("Is Right child of node available " + root.data);
        boolean isRight = sc.nextBoolean();

        if(isRight) {
            System.out.println("Enter the Right child for " + root.data);
            int data = sc.nextInt();
            TreeNode node = new TreeNode(data);
            root.right = node;
            takeInput(root.right);
        }
    }
}
