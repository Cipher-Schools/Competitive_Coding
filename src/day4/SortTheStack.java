package day4;


public class SortTheStack {


    public static void addInStack(StackUsingLinkedList s, int element) {

        if (s.isEmpty() || element > s.top()) {
            s.push(element);
            return;
        }
        int temp = s.pop();
        addInStack(s, element);
        s.push(temp);

    }

    public static void sort(StackUsingLinkedList s) {

        if (s.isEmpty()) {
            return;
        }

        int element = s.pop();
        sort(s);
        addInStack(s, element);
    }

    private static void printStack(StackUsingLinkedList s) {
        while (!s.isEmpty()) {
            System.out.println(s.pop());
        }
    }

    public static void main(String[] args) {

        StackUsingLinkedList s = new StackUsingLinkedList();
        s.push(40);
        s.push(10);
        s.push(-5);
        s.push(30);

        sort(s);

        printStack(s);


    }
}
