package day11;

/**
 * @author amgarg
 */
public class HeightOfTree {


    public static int getHeight(TreeNode root) {

        if (root == null) {
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);

        int finalHeight = Math.max(leftHeight, rightHeight);
        return finalHeight + 1;
    }


    static  int max_diameter = 0;
    public static int getDiameter(TreeNode root) {

        if (root == null) {
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);

        max_diameter  = Math.max(max_diameter, 1 + leftHeight + rightHeight);

        int finalHeight = Math.max(leftHeight, rightHeight);
        return finalHeight + 1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.left.right.right = new TreeNode(6);
        root.left.right.right.left = new TreeNode(7);

        System.out.println(getDiameter(root));

    }
}
