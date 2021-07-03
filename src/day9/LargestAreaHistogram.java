package day9;

import java.util.Stack;

/**
 * @author amgarg
 */
public class LargestAreaHistogram {
    public static int maxAreaInHistogram(int[] arr) {
        Stack<Integer> s = new Stack<>();

        int max_area = 0;

        int i = 0;
        while (i < arr.length) {
            int currentBuilding = arr[i];
            if (s.isEmpty() || currentBuilding >= arr[s.peek()]) {
                s.push(i);
                i++;
            } else {
                int previousBar = s.pop();
                int height = arr[previousBar];
                int width;
                if (s.isEmpty()) {
                    width = i;
                } else {
                    width = i - s.peek() - 1;
                }

                int area = height * width;
                max_area = Math.max(area, max_area);
            }
        }

        while (!s.isEmpty()) {
            int previousBar = s.pop();
            int height = arr[previousBar];
            int width;
            if (s.isEmpty()) {
                width = i;
            } else {
                width = i - s.peek() - 1;
            }
            int area = height * width;
            max_area = Math.max(area, max_area);
        }

        return max_area;
    }


    public static void main(String[] args) {

        int[] arr = {7, 6, 2, 4, 3, 5, 10};

        System.out.println(maxAreaInHistogram(arr));
    }
}
