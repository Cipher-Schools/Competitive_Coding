package day13;

import day11.TreeNode;

/**
 * @author amgarg
 */
public class BSTOperations {


    public static TreeNode deleteNode(TreeNode root, int deleteKey) {

        if (deleteKey < root.data) {
            root.left = deleteNode(root.left, deleteKey);
        } else if (deleteKey > root.data) {
            root.right = deleteNode(root.right, deleteKey);
        } else {
            if (root.left != null && root.right != null) { //2 Children
                int leftMaxium = max(root.left);
                root.data = leftMaxium;
                root.left = deleteNode(root.left, leftMaxium);
                return root;
            } else if (root.left != null) {
                return root.left;
            } else if (root.right != null) {
                return root.right;
            }
            //0 childeren
            return null;
        }
        return root;
    }

    public TreeNode insertIntoBST(TreeNode root, int targetVal) {

        if(root == null) {
            TreeNode newNode = new TreeNode(targetVal);
            return newNode;
        }
        if(root.data > targetVal) {

            root.left = insertIntoBST(root.left, targetVal);
            //root.left = newNode;
        } else {
            root.right = insertIntoBST(root.right, targetVal);
        }
        return root;
    }

    private static int max(TreeNode root) {
        while (root.right != null) {
            root = root.right;
        }
        return root.data;
    }


    public static void main(String[] args) {


    }

}
