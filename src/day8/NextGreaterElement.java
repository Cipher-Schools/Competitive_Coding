package day8;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

/**
 * @author amgarg
 */
public class NextGreaterElement {

    public static ArrayList<Integer> nextGreater(ArrayList<Integer> a) {
        Stack<Integer> s = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < a.size(); i++) {
            result.add(-1);
        }
        s.push(0);
        for (int i = 1; i < a.size(); i++) {
            while (!s.isEmpty() && a.get(i) > a.get(s.peek())) {
                result.set(s.peek(), a.get(i));
                s.pop();
            }
            s.push(i);
        }
        while (!s.isEmpty()) {
            result.set(s.peek(), -1);
            s.pop();
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();

        ArrayList<Integer> input = new ArrayList<>();

        for (int i = 0; i < size; i++) {
            int n = sc.nextInt();
            input.add(n);
        }
        ArrayList<Integer> result = nextGreater(input);
        for (Integer i : result) {
            System.out.print(i + " ");
        }
    }

}
