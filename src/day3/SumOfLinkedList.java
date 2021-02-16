package day3;


public class SumOfLinkedList {


    /*
    T.C = O(max(l1, l2))
     */
    public static Node sum(Node head1, Node head2) {


        //get the length of both the linked list

        Node sum_result = null;
        if (length(head1) > length(head2)) {

            int diff = length(head1) - length(head2);
             sum_result = sumHelper(head1, head2, diff);
        } else {
            int diff = length(head2) - length(head1);
             sum_result = sumHelper(head2, head1, diff);
        }


        Node temp = new Node(1); // 1 > null

        if(sum_result.data > 9) {
            sum_result.data = sum_result.data % 10;
            temp.next = sum_result; //1 > 9 > 8
            sum_result = temp;
        }
        return sum_result;
    }

    private static int length(Node head1) {

        int length = 0;
        Node current = head1;

        while(current != null) {
            length++;
            current = current.next;
        }
        return  length;
    }


    /**
     * This function is assuming that size of l1 and l2 are equal
     * @param head1
     * @param head2
     * @param diff
     * @return
     */
    public static Node sumHelper(Node head1, Node head2, int diff) {

        if(head1 == null) {
            return null;
        }

        Node my_result = null;
        if(diff == 0) {
         my_result = new Node(head1.data + head2.data);
        } else {
            my_result = new Node(head1.data);
        }


        Node recursiveResult = null;
        if(diff == 0) {
          recursiveResult  = sumHelper(head1.next, head2.next, diff);
        } else {
            recursiveResult  = sumHelper(head1.next, head2,diff - 1);
        }


        if(recursiveResult != null && recursiveResult.data > 9) {
            recursiveResult.data = recursiveResult.data % 10;
            my_result.data = my_result.data + 1;
        }

        my_result.next = recursiveResult;
        return my_result;
    }

    public static void printList(Node head) {
        Node current = head;

        while(current != null) {
            System.out.print(current.data + "  ->  ");
            current = current.next;
        }
    }

    public static void main(String[] args) {

        Node head1 = new Node(9);
        head1.next = new Node(9);

        printList(head1);

        System.out.println();
        Node head2 = new Node(9);
        head2.next = new Node(9);
        head2.next.next = new Node(9);

        printList(head2);
        System.out.println();
        Node result = sum(head1, head2);

        printList(result);


    }

}
