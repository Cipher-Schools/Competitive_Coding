package day3;


public class DesignLinkedList {


    public static Node reverseLinkedList(Node head) {

        if(head == null || head.next == null) {
            return head;
        }


        Node rest = reverseLinkedList(head.next);

        head.next.next = head;

        head.next = null;

        return rest;
    }


    public static void printList(Node head) {
        Node current = head;

        while(current != null) {
            System.out.print(current.data + "  ->  ");
            current = current.next;
        }
     }


    public static void main(String[] args) {

        Node head = new Node(4);

        Node node1 = new Node(5);

        head.next = node1;

        head.next.next = new Node(6);

        head.next.next.next = new Node(7);

        printList(head);
       Node newHead = reverseLinkedList(head);

       System.out.println();
       printList(newHead);

    }
}
