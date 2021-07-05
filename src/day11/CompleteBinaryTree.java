package day11;

/**
 * @author amgarg
 */
public class CompleteBinaryTree {

    /**
     * T.C - O(n) where n is the number of nodes
     * @param root
     * @return
     */
    public static int countNodes(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int leftNodes = countNodes(root.left);
        int rightNodes = countNodes(root.right);

        return 1 + leftNodes + rightNodes;
    }

    public static boolean isCompleteBinaryTreeHelper(TreeNode root, int index, int numberOfNodes) {

        if(root == null) {
            return true;
        }

        if (index >= numberOfNodes) {
            return false;
        }

        boolean isLeftCompleteBinaryTree = isCompleteBinaryTreeHelper(root.left, 2 * index + 1, numberOfNodes);
        boolean isRightCompleteBinaryTree = isCompleteBinaryTreeHelper(root.right, 2 * index + 2, numberOfNodes);

        return isLeftCompleteBinaryTree && isRightCompleteBinaryTree;

    }

    public static boolean isCompleteBinaryTree(TreeNode root) {
        return isCompleteBinaryTreeHelper(root, 0, countNodes(root));
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(18);
        root.left = new TreeNode(15);
        root.left.left = new TreeNode(40);
        root.left.left.left = new TreeNode(30);
        root.left.left.right = new TreeNode(50);

        root.left.right = new TreeNode(50);

        root.left.right.left = new TreeNode(80);
        root.left.right.right = new TreeNode(100);

        root.right = new TreeNode(20);
        root.right.left = new TreeNode(100);
        root.right.right = new TreeNode(200);


        root.right.left.right = new TreeNode(15);


        System.out.println(isCompleteBinaryTree(root));


    }
}
