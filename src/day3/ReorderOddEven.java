package day3;


public class ReorderOddEven {


    /**
     * T.C = O(n)
     * S.C  = O(1)
     * @param head
     * @return
     */
    public static Node rearrange(Node head) {

        if (head == null || head.next == null) {
            return head;
        }
        Node odd = head;
        Node even = head.next;
        Node evenHead = even;

        //Performing of rearrangement of links

        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }

        odd.next = evenHead;
        return head;

    }

    public static void printList(Node head) {
        Node current = head;

        while(current != null) {
            System.out.print(current.data + "  ->  ");
            current = current.next;
        }
    }


    public static void main(String[] args) {


        Node root = new Node(1);
        root.next = new Node(2);
        root.next.next = new Node(3);
        root.next.next.next = new Node(4);
        root.next.next.next.next = new Node(5);

        printList(root);

        Node result = rearrange(root);

        System.out.println();
        printList(result);

    }
}
