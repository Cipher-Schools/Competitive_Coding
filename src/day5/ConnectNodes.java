package day5;


public class ConnectNodes {


    //T.C - O(n)
    //SC - Constant
    public static void connectLevel(TreeNode root) {


        while(root != null) {
            TreeNode dummyTreeNode = new TreeNode(Integer.MIN_VALUE);
            TreeNode childNode = dummyTreeNode;

            while (root != null) {
                if (root.left != null) {
                    childNode.next = root.left;
                    childNode = childNode.next;
                }

                if (root.right != null) {
                    childNode.next = root.right;
                    childNode = childNode.next;
                }
                root = root.next;
            }
            root = dummyTreeNode.next;
        }
    }


    public static void printTree(TreeNode root) {
        if(root == null) {
            return;
        }

        TreeNode temp = root;
        while(temp != null) {
            System.out.print(temp.data + "  ");
            temp = temp.next;
        }
        System.out.println();
        if(root.left != null) {
            printTree(root.left);
        } else {
            printTree(root.right);
        }

    }




    public static void main(String[] args) {


        TreeNode root = new TreeNode(1);

        TreeNode.takeInput(root);

        connectLevel(root);

        printTree(root);


    }
}
