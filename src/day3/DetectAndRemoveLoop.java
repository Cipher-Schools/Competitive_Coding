package day3;


public class DetectAndRemoveLoop {


    //TODO
    public static void detectAndRemove(Node head) {

        Node slow, fast;

        slow = head;
        fast = head;

        fast = fast.next.next;
        slow = slow.next;

        while(true) {

            if(fast == null || fast.next == null) {
                //No loop
                return;
            } else if(fast == slow || fast.next == slow) {
                break;
            } else {
                fast = fast.next.next;
                slow = slow.next;
            }

        }

        System.out.println(slow.data);
        fast = head;

        //Infinite loop
        //TODO - Check Floyd's cycle detection proof
        while(fast.next != slow.next) {
            slow = slow.next;
            fast = fast.next;
        }

        System.out.println(fast.data);

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
