package day6;


public class Node {

    public  int data;
    public Node next;
    public Node random;

    public Node(int data) {
        this.data = data;
    }


    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }
}
