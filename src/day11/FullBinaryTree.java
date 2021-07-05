package day11;

/**
 * @author amgarg
 */
public class FullBinaryTree {

    public static boolean isFullBinaryTree(TreeNode root) {


        if (root == null) {
            return true;
        }

        if (root.left == null && root.right == null) {
            return true;
        }

        if (root.left != null && root.right != null) {
            boolean isLeftFullBinaryTree = isFullBinaryTree(root.left);

            boolean isRightFullBinaryTree = isFullBinaryTree(root.right);

            return isLeftFullBinaryTree && isRightFullBinaryTree;
        }

        return false;

    }


    public static void main(String[] args) {

        TreeNode root = new TreeNode(18);
        root.left = new TreeNode(15);
        root.left.left = new TreeNode(40);
        root.left.left.left = new TreeNode(30);
        root.left.left.right = new TreeNode(50);

        root.left.right = new TreeNode(50);

        root.right = new TreeNode(20);
        root.right.right = new TreeNode(100);

        System.out.println(isFullBinaryTree(root));
    }
}
