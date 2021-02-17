package day5;


public class ConstructBinaryTree {


    public static TreeNode constructTree(int [] inorder, int [] preorder, int preorderIndex, int inStart, int inEnd) {


        if(inStart > inEnd) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[preorderIndex]);

        int inorderIndex = -1;
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == preorder[preorderIndex]) {
                inorderIndex = i;
                break;
            }
        }

        int leftSubTreeSize = inorderIndex - inStart;

        root.left = constructTree(inorder, preorder, preorderIndex + 1, inStart, inorderIndex - 1);
        root.right = constructTree(inorder, preorder, preorderIndex + leftSubTreeSize + 1,
                inorderIndex + 1, inEnd);

        return root;
    }




    public static void main(String[] args) {



        int [] inorder = {4,2, 5, 1,3};
        int preOrder[] = {1,2,4,5,3};

      TreeNode root =  constructTree(inorder, preOrder, 0, 0, inorder.length - 1);

      TreeUse.levelOrderTraversalUsingQueue(root);



    }
}
