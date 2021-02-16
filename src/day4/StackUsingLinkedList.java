package day4;


import day3.Node;

public class StackUsingLinkedList {

    private Node head = null;

    public  void push(int element) {
        if(head == null) {
            Node stackElement = new Node(element);
            head = stackElement;
        } else {
            Node stackElement = new Node(element);
            stackElement.next = head;
            head = stackElement;
        }
    }

    public int size() {

        int length = 0;
        Node temp = head;

        while(temp != null) {
            length++;
            temp = temp.next;
        }
        return  length;
    }


    public boolean isEmpty() {

        if(this.size() == 0) {
            return true;
        }
        return false;
    }

    public int top() {
        if(isEmpty()) {
            System.out.println("Some offensive message");
            return Integer.MAX_VALUE;
        }
        return  head.data;
    }

    public int pop() {
        if(isEmpty()) {
            System.out.println("Some offensive message");
            return Integer.MAX_VALUE;
        }
        int poppedElement = head.data;
        head = head.next;
        return poppedElement;
    }




}
