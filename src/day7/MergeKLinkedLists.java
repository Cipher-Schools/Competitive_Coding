package day7;

import day6.Node;
import day6.NodeUse;

/**
 * while (i < k) {
 * 1. Divide the set of LL into two halves
 * i = L1, k = LN-1
 * 2. Merge L1 = L1 + L2
 * 3. Merge rest of halves
 * 4. Merge L1 = L1 + rest of Halves
 * }
 */
public class MergeKLinkedLists {


    /**
     * TC - O(arr.length)
     * S.C - O(arr.length)
     * @param arr
     * @return
     */
    public static Node mergeKLists(Node arr[]) {


        int reamingLL = arr.length - 1;


        while (reamingLL != 0) {
            int i = 0;
            int k = reamingLL;
            while (i < k) {
                arr[i] = mergeTwoSortedLinkedLists(arr[i], arr[k]);
                i++;
                k--;
                if (i >= k) {
                    reamingLL = k;
                }
            }
        }

        return arr[0];
    }

    private static Node mergeTwoSortedLinkedLists(Node l1, Node l2) {

        Node sortedResult = null;

        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        if (l1.getData() <= l2.getData()) {
            sortedResult = l1;
            sortedResult.next = mergeTwoSortedLinkedLists(l1.next, l2);
        } else {
            sortedResult = l2;
            sortedResult.next = mergeTwoSortedLinkedLists(l1, l2.next);
        }
        return sortedResult;
    }

    public static void main(String[] args) {

        Node[] arr = new Node[3];

        Node node1 = new Node(1);
        node1.next = new Node(3);
        node1.next.next = new Node(5);
        node1.next.next.next = new Node(8);
        node1.next.next.next.next = new Node(15);
        arr[0] = node1;

        Node node2 = new Node(2);
        node2.next = new Node(6);
        node2.next.next = new Node(10);
        node2.next.next.next = new Node(12);
        arr[1] = node2;

        Node node3 = new Node(4);
        node3.next = new Node(9);
        node3.next.next = new Node(11);
        arr[2] = node3;

        Node head = mergeKLists(arr);

        NodeUse.printLinkedList(head);
    }
}
