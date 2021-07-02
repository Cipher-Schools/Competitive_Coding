package day7;


import day6.Node;

public class CloneLinkedListWithRandomPointers {

    /**
     * T.C - O(n) where n is the number of nodes
     * S.C - O(1)
     * @param head
     * @return
     */
    public static Node createClone(Node head) {

        Node original = head;
        if(head == null) {
            return head;
        }

        /**
         * Create clone of nodes and attach them into main LL
         */
        while (original != null && original.next != null) {
            Node cloneNode = new Node(original.getData());
            Node next = original.getNext();
            original.next = cloneNode;
            cloneNode.next = next;
            original = original.next.next;
        }

        original.next = new Node(original.getData());

        original = head;

        /**
         * Point random pointers of clonedNodes to clonedNodes using originalNodes Random Pointer
         */
        while (original != null && original.next != null) {

            if (original.random != null) {
                original.next.random = original.random.next;
            }
            original = original.next.next;
        }
        original = head;
        Node copy = head.next;
        Node newHead = head.next;

        /**
         * Seperate cloned nodes from main LL
         */
        while(original.next != null && copy.next != null) {
            original.next = original.next.getNext();
            copy.next = copy.next.next;
            original = original.next;
            copy = copy.next;
        }

        original.next = null;

        return  newHead;
    }
}
