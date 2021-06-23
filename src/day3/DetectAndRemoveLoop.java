package day3;


public class DetectAndRemoveLoop {


    public static void detectAndRemove(Node head) {

        Node fast = head;
        Node slow = head;
        boolean isLoopAvailable = false;
        while (slow != null && fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (slow == fast) {
                System.out.print("Loop Exists");
                isLoopAvailable = true;
                break;
            }
        }

        if (isLoopAvailable) {
            slow = head;
            Node prevNode = null;
            while (slow != fast) {
                prevNode = fast;
                fast = fast.next;
                slow = slow.next;
            }
            System.out.print("Loop Found Node : " + slow.data);
            prevNode.next = null; //Remove the Loop
        }

    }


    public static void main(String[] args) {


        Node head = new Node(1);

        Node node1 = new Node(2);

        Node node2 = new Node(3);

        Node node3 = new Node(4);

        Node node4 = new Node(5);

        head.next = node1;
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2;

        detectAndRemove(head);
    }
}
