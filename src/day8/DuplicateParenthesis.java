package day8;

import java.util.Stack;

/**
 * @author amgarg
 */
public class DuplicateParenthesis {


    /**
     * tc - O(n) where n is length of exp string
     * sc - O(n) where n is length of exp string
     * @param expString
     * @return
     */
    public static boolean containsDuplicateParenthesis(String expString) {

        Stack<Character> stack = new Stack<>();

        for(int i = 0; i < expString.length(); i++) {
            Character currentCharacter = expString.charAt(i);

            if(currentCharacter != ')') {
                stack.push(currentCharacter);
            } else {

                int removeElementsCount  = 0;
                Character top = stack.pop();

                while(top != '(') {
                    top = stack.pop();
                    removeElementsCount++;
                }

                if(removeElementsCount < 1) {
                    return true;
                }
            }

        }
        return false;
    }


    public static void main(String[] args) {
        String str = "(((1+(2)))+(3))";

        System.out.println(containsDuplicateParenthesis(str));
    }



}
