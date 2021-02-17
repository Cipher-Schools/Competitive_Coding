package doubts;


import day3.Node;

public class SortLinkedList {


    public static Node mergeSort(Node head) {

        if(head == null || head.next == null) {
            return  head;
        }

        Node mid = getMid(head);

        Node next = mid.next;
        mid.next = null;


        Node left = mergeSort(head);
        Node right = mergeSort(next);

        Node mergedLinkedListHead = merge(left, right);

        return  mergedLinkedListHead;


    }

    private static Node merge(Node left, Node right) {

        if(left == null) {
            return right;
        } else if (right == null) {
            return left;
        }

        Node resultant = null;

        if(left.data <= right.data) {
            resultant = left;
            resultant.next = merge(left.next, right);
        } else {
            resultant = right;
            resultant.next = merge(left, right.next);
        }

        return resultant;
    }

    private static Node getMid(Node head) {

        if(head == null) {
            return head;
        }

        Node slow = head;
        Node fast = head;

        while(fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        return  slow;

    }

    public static void printList(Node head) {
        Node current = head;

        while(current != null) {
            System.out.print(current.data + "  ->  ");
            current = current.next;
        }
    }

    public static void main(String[] args) {


        Node head = new Node(6);
        head.next = new Node(3);
        head.next.next = new Node(5);
        head.next.next.next = new Node(1);


        printList(head);

        System.out.println();
        Node result = mergeSort(head);

        printList(result);

    }
}
