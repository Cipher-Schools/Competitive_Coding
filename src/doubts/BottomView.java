package doubts;


import day5.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.TreeMap;


class Pair {

    TreeNode node;
    int identifier;

    public Pair(TreeNode node, int identifier) {
        this.node = node;
        this.identifier = identifier;
    }
}

public class BottomView {


    public static void bottomView(TreeNode root) {

        if (root == null) {
            return;
        }

        Queue<Pair> queue = new LinkedList<>();

        Pair p = new Pair(root, 0);
        queue.add(p);
        Map<Integer, TreeNode> map = new TreeMap<>();

        while (!queue.isEmpty()) {

            Pair pair = queue.poll();

            TreeNode node = pair.node;
            int value = pair.identifier;


            map.put(value, node);

                if (node.left != null) {
                    Pair leftPair = new Pair(node.left, value - 1);
                    queue.add(leftPair);
                }

                if (node.right != null) {
                    Pair rightPair = new Pair(node.right, value + 1);
                    queue.add(rightPair);
                }
            }


            for (Map.Entry<Integer, TreeNode> entry : map.entrySet()) {
                System.out.print(entry.getValue().data + "  ");
            }
        }

        public static void main (String[]args){

            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);

            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);

            root.left.right.left = new TreeNode(8);
            root.left.right.right = new TreeNode(9);

            root.right.left = new TreeNode(6);
            root.right.right = new TreeNode(7);

            bottomView(root);
        }
    }
