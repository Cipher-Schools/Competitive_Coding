package day9;

import java.util.Stack;

/**
 * @author amgarg
 */
public class CelebrityProblem {


    public static boolean findCelebrity(int [][] matrix) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < matrix.length; i++) {
            stack.push(i);
        }

        while (stack.size() >= 2) {
        int person1 = stack.pop();
        int person2 = stack.pop();

        if (matrix[person1][person2] == 1) {
            //person 1 knows person2
            stack.push(person2);
        } else {
            //person 1 does not knows person 2
            stack.push(person1);
        }
    }

        int remainingPerson = stack.pop();
        //check if this person is celebrity or not

        for(int i = 0; i < matrix.length; i++) {

            if(i != remainingPerson) {
                if(matrix[i][remainingPerson] == 0 || matrix[remainingPerson][i] == 1) {
                    return false;
                }
            }

        }

        return true;
    }

    public static void main(String[] args) {

        int [][] matrix =  {
                {0, 1, 0, 1},
                {0, 0, 0, 1},
                {0, 1, 0, 1},
                {1, 1, 1, 0}
        };

        System.out.println(findCelebrity(matrix));

    }
}
