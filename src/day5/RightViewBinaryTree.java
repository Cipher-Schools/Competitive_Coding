package day5;


public class RightViewBinaryTree {


    static int alreadyTraversedLevel  = 0;

    public static void printRightView(TreeNode root, int currentLevel) {

        if(root == null) {
            return;
        }

        if(currentLevel > alreadyTraversedLevel) {
            System.out.println(root.data);
            alreadyTraversedLevel = currentLevel;
        }

        printRightView(root.right, currentLevel + 1);
        printRightView(root.left, currentLevel + 1);
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);

        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);

        printRightView(root, 1);
    }
}
