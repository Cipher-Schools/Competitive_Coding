package day6;

/**
 * @author amgarg
 */
public class ReverseLinkedList {


    public static Node reverseLinkedList(Node head) {


        if(head == null || head.next == null) {
            return head;
        }
        Node rest = null;
        Node presentNode = head;
        Node pastNode = null;

        while(presentNode != null) {
            rest = presentNode.next;
            presentNode.next = pastNode;
            pastNode = presentNode;
            presentNode = rest;
        }
        head = pastNode;
        return head;
    }

    public static Node reverseLinkedListUsingRecursion(Node head) {

        if(head == null || head.next == null) {
            return head;
        }
        Node rest = reverseLinkedListUsingRecursion(head.next);

        head.next.next = head;
        head.next = null;

        return rest;

    }

    public static void main(String[] args) {

       Node head =
               NodeUse.createRandomLinkedList(6);

       NodeUse.printLinkedList(head);

        System.out.println();
        System.out.println();

       Node newHead = reverseLinkedList(head);

       NodeUse.printLinkedList(newHead);

        System.out.println();
        System.out.println();

        newHead = reverseLinkedListUsingRecursion(newHead);

        NodeUse.printLinkedList(newHead);



    }


}
