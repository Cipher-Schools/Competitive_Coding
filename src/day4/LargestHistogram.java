package day4;


/**
 * 1. Create a stack
 *
 * 2. Iterate over the array {
     Take the current index

 int max area = 0;
 *
 *   If stack is empty -> push the current index in stack
 *    else if stack is not empty
 *       a. If building is greater than building which is at top of stack -> push it in stack
 *       b.If building is smaller or no building ->
 *           b.1 take the top of the stack and pop it
 *               height = from get height of building
 *               if stack is empty, width = currentIndex
 *               else, width = currentIndex - s.top() - 1;
 *               area = height * width
 *
 *               if(area > maxarea) {
 *                   area = maxarea;
 *               }
 * }
 *
 *
 */
public class LargestHistogram {

    public static int maxAreaInHistogram(int [] arr) {
        StackUsingLinkedList s = new StackUsingLinkedList();

        int max_area = 0;

        int i = 0;
        while(i < arr.length) {
            int currentBuilding = arr[i];
            if(s.isEmpty() || currentBuilding >= arr[s.top()]) {
                s.push(i);
                i++;
            } else {
                int previousBar = s.pop();
                int height = arr[previousBar];
                int width;
                if(s.isEmpty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                int area = height * width;
                max_area = Math.max(area, max_area);
            }
        }

        while(!s.isEmpty()) {
            int previousBar = s.pop();
            int height = arr[previousBar];
            int width;
            if(s.isEmpty()) {
                width = i;
            } else {
                width = i - s.top() - 1;
            }
            int area = height * width;
            max_area = Math.max(area, max_area);
        }

        return  max_area;
    }


    public static void main(String[] args) {

        int [] arr = {6, 0, 5, 4, 5, 1, 6};

        System.out.println(maxAreaInHistogram(arr));
    }
}
