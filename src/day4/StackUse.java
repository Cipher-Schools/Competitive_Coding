package day4;


import java.util.Stack;

public class StackUse {


    public static void main(String[] args) {

        StackUsingLinkedList s = new StackUsingLinkedList();

        s.push(4);
        s.push(5);
        s.push(3);

        System.out.println(s.size());



        System.out.println(s.size());


        System.out.println(s.getMin());

        s.pop();

        System.out.println(s.getMin());




    }

}
