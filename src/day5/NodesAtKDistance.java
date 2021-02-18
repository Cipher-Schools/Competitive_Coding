package day5;


import java.util.ArrayList;

public class NodesAtKDistance {

    static ArrayList<TreeNode> path = new ArrayList<>();

    public static void printNodesAtKLevel(TreeNode root, int targetNode, int k) {


        getPath(root, targetNode);

      for(TreeNode treeNode : path) {
          System.out.print(treeNode.data +"   ");
      }
      System.out.println();

        for(int i = 0; i < path.size(); i++) {
            printNodesDownAtKLevel(path.get(i),
                    k - i, i == 0 ? null : path.get(i - 1));
        }
    }


    private  static boolean getPath(TreeNode root, int targetNode) {

        if(root == null) {
            return false;
        }

        if(root.data == targetNode) {
            path.add(root);
            return true;
        }


        boolean isFindLeft = getPath(root.left, targetNode);
        if(isFindLeft) {
            path.add(root);
            return true;
        }

        boolean isFindRight = getPath(root.right, targetNode);
        if(isFindRight) {
            path.add(root);
            return true;
        }

        return false;
    }

    private static void printNodesDownAtKLevel(TreeNode node, int currentLevel, TreeNode obstacle) {

        if(node == null || currentLevel < 0 || node == obstacle) {
            return;
        }

        if(currentLevel == 0) {
            System.out.println(node.data);
            return;
        }

        printNodesDownAtKLevel(node.left, currentLevel - 1, obstacle);
        printNodesDownAtKLevel(node.right, currentLevel - 1, obstacle);

    }


    public static void main(String[] args) {


        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(6);
        root.left.left.left = new TreeNode(5);
        root.left.left.right = new TreeNode(4);

        root.right.right = new TreeNode(10);

        printNodesAtKLevel(root, 2, 2);
    }
}
