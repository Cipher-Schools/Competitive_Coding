package day6;


import day5.TreeNode;
import day5.TreeUse;

public class BSTOperations {

    //Average T.C - O(log n)
    public static TreeNode deleteNode(TreeNode root, int deleteKey) { //21, 23

        if(root == null) {
            return  null;
        }
        if(deleteKey < root.data) {
            root.left = deleteNode(root.left, deleteKey);
        } else if (deleteKey > root.data) {
            root.right = deleteNode(root.right, deleteKey);
        } else {
            if (root.left != null && root.right != null) { // 2 Children
                int leftMax = max(root.left);  //11
                root.data = leftMax;
                root.left = deleteNode(root.left, leftMax);
                return  root;
            } else if(root.left != null) {
                return root.left;
            } else if(root.right != null) {
                return root.right;
            }
            return null;
        }
        return root;
    }

    private static int max(TreeNode root) {
        while(root.right != null) {
           root = root.right;
        }
        return root.data;
    }


    public static TreeNode insertNode(TreeNode root, int value) {

        if(root == null) {
            TreeNode node = new TreeNode(value);
            return  node;
        }
        if(value <= root.data) {
            root.left = insertNode(root.left, value);
        } else {
            root.right = insertNode(root.right, value);
        }
        return root;
    }

    public static boolean searchNode(TreeNode root, int  target) {

        if(root == null) {
            return  false;
        }

        if(root.data == target) {
            return true;
        }

        if(target <= root.data) {
            boolean isAvailableInLeft = searchNode(root.left, target);

            if(isAvailableInLeft) {
                return true;
            }
        } else {
            boolean isAvailableInRight = searchNode(root.right, target);

            if(isAvailableInRight) {
                return true;
            }
        }
        return false;
    }




    public static void main(String[] args) {

        TreeNode root = new TreeNode(15);

        insertNode(root, 10);
        insertNode(root, 20);
        insertNode(root, 6);
        insertNode(root, 11);
        insertNode(root, 16);
        insertNode(root, 23);

        TreeUse.levelOrderTraversalUsingQueue(root);

        System.out.println();

        System.out.println(searchNode(root, 23));

        deleteNode(root, 20);


        TreeUse.levelOrderTraversalUsingQueue(root);

        System.out.println();


        deleteNode(root, 10);


        TreeUse.levelOrderTraversalUsingQueue(root);

        System.out.println();







    }

}
