public class NonReapeatingC {

    static class Node {
        char data;
        Node prev;
        Node next;

        // Constructor to create a new node
        // next and prev is by default initialized as null
        Node(char d) {
            data = d;
        }
    }

    // Class for Doubly Linked List
    public static class DLL {
        Node head; // head of list
        Node last;

        /* Doubly Linked list Node */

        void delete(Node toDel) {
            // first header node
            if (toDel.prev == null) {
                head = toDel.next;
                if (toDel.next != null) {

                    toDel.next.prev = null;
                }
                toDel.next = null;

            }
            // last node
            else if (toDel.next == null) {
                toDel.prev.next = null;
                // change last node
                last = toDel.prev;
                toDel.prev = null;
            }
            // inbetween nodes
            else {
                toDel.prev.next = toDel.next;
                toDel.next.prev = toDel.prev;
            }
            if (head == null) {
                last = null;
            }
        }

        // Add a node at the end of the list and return the added node
        Node append(char new_data) {
            /*
             * 1. allocate node 2. put in the data
             */
            Node new_node = new Node(new_data);

            /*
             * 2. This new node is going to be the last node, so make next of it
             * as NULL
             */
            new_node.next = null;

            /*
             * 3. If the Linked List is empty, then make the new node as head
             */
            if (head == null) {
                new_node.prev = null;
                head = new_node;
                // assign last node
                last = new_node;
                return new_node;
            } else {
                last.next = new_node;
                new_node.prev = last;
            }
            // assign last node
            last = new_node;
            return new_node;
        }

    }

    private static void findFirstNonRepeating(String str) {
        int sz = str.length();
        final int MAX_CHAR = 256;
        Node[] charMap = new Node[MAX_CHAR];
        boolean[] repeated = new boolean[MAX_CHAR];

        DLL dll = new DLL();

        for (int i = 0; i < sz; i++) {
            char val = str.charAt(i);


                if (charMap[val] == null) {
                    dll.append(val);
                    charMap[val] = dll.last;

                } else {
                    dll.delete(charMap[val]);
                }

            if (dll.head != null) {
                System.out.print("First non-repeating character so far is ");
                System.out.println(dll.head.data);

            }

        }

    }

    public static void main(String args[]) {
        String stream = "abbba";
        findFirstNonRepeating(stream);
    }

}
