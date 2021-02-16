package day3;



public class CloneLinkedList {

    /**
     * T.C = O(Length of linked list)
     * S.C = O(1)
     * @param head
     * @return
     */
    public static Node createClone(Node head) {

        Node original = head;

        while(original != null && original.next != null) {
            Node copy = new Node(original.data);
            Node next = original.next;
            original.next = copy;
            copy.next = next;
            original = original.next.next;
        }
        original.next = new Node(original.data);

        original = head;

        while(original != null && original.next != null) {

            if(original.random != null) {
                original.next.random = original.random.next;
            }
            original = original.next.next;
        }

        original = head;
        Node copy = head.next;
        Node copyHead = head.next;


        while(original.next != null && copy.next != null) {
            original.next = original.next.next;
            copy.next = copy.next.next;
            original = original.next;
            copy = copy.next;
        }

        original.next = null;

        return copyHead;

    }

    public static void printList(Node head) {
        Node current = head;

        while(current != null) {
            System.out.println(current.data  + " Random pointer of this node is " + current.random.data);
            current = current.next;
        }
    }

    public static void main(String[] args) {


        Node head = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);

        head.next = node2;
        head.random = node3;

        node2.next = node3;
        node2.random = node3;

        node3.random = head;

        Node newClonedHead = createClone(head);

        printList(newClonedHead);

    }
}
