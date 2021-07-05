package day11;

/**
 * @author amgarg
 */
public class PerfectBinaryTree {


    private static int deepestLevel(TreeNode root) {

        int deepLevel = 0;

        while(root != null) {
            deepLevel++;
            root = root.left;
        }
        return deepLevel;
    }


    public static boolean isPerfectHelper(TreeNode root, int currentLevel, int deepestLevel) {

        if(root.left == null && root.right == null) {
            if(currentLevel == deepestLevel) {
                return true;
            }
            return false;
        }

        if(root.left != null && root.right != null) {
            boolean isLeftPerfectBinaryTree = isPerfectHelper(root.left, currentLevel + 1, deepestLevel);
            boolean isRightPerfectBinary = isPerfectHelper(root.right, currentLevel + 1, deepestLevel);

            return  isLeftPerfectBinaryTree && isRightPerfectBinary;
        }

        return false;
    }

    public static boolean isPerfectBinaryTree(TreeNode root) {
        int deepestLevel = deepestLevel(root);

        return isPerfectHelper(root, 1, deepestLevel);
    }


    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);
        root.right.right.right = new TreeNode(8);

        System.out.println(isPerfectBinaryTree(root));

    }
}
