package day12;

import day11.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author amgarg
 */
public class BurnTheTree {


    private static Queue<TreeNode> queue = new LinkedList<>();

    private static int burningTree(TreeNode root, int targetNode) {
        if (root == null)
            return 0;
        if (root.data == targetNode) {
            System.out.println(root.data);
            if (root.left != null)
                queue.offer(root.left);
            if (root.right != null)
                queue.offer(root.right);
            return 1;
        }

        int left = burningTree(root.left, targetNode);
        if (left == 1) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode current = queue.poll();
                System.out.print(current.data + " ");
                if (current.left != null)
                    queue.offer(current.left);
                if (current.right != null)
                    queue.offer(current.right);
            }
            if (root.right != null) {
                queue.offer(root.right);
            }
            System.out.println(root.data);
            return 1;
        }

        int right = burningTree(root.right, targetNode);
        if (right == 1) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode current = queue.poll();
                System.out.print(current.data + " ");
                if (current.left != null)
                    queue.offer(current.left);
                if (current.right != null)
                    queue.offer(current.right);
            }
            if (root.left != null) {
                queue.offer(root.left);
            }
            System.out.println(root.data);
            return 1;
        }
        return 0;
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

        burningTree(root, 4);


        while(!queue.isEmpty()) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode current = queue.poll();
                System.out.print(current.data + " ");
                if (current.left != null)
                    queue.offer(current.left);
                if (current.right != null)
                    queue.offer(current.right);
            }
            System.out.println();
        }
    }
}
