package day14;

import java.util.ArrayList;

/**
 * @author amgarg
 */
public class MinHeap {

    ArrayList<Integer> data;

    MinHeap() {
        data = new ArrayList<>();
        data.add(null);
    }


    /**
     * TC - O(log n) where n is the number of nodes we have in our heap.
     * @param element
     */
    public void addElement(int element) {
        data.add(element);

        int currentIndex =  data.size() - 1;
        int parentIndex = currentIndex / 2;


        while (currentIndex != 1) {
            if(data.get(currentIndex) >= data.get(parentIndex))  {
                return;
            }
            int currentData = data.get(currentIndex);
            int parentData = data.get(parentIndex);

            data.set(currentIndex, parentData);
            data.set(parentIndex, currentData);

            currentIndex = parentIndex;
            parentIndex = currentIndex / 2;
        }
    }


    /**
     * T.C - O(log n)
     * @return
     */
    public int removeMin() {
        int min = data.get(1);
        int last = data.get(data.size() - 1);

        data.set(1, last);
        data.remove(data.size() - 1);

        int currentIndex = 1;
        int leftIndex = currentIndex * 2;
        int rightIndex = currentIndex * 2 + 1;


        while (leftIndex < data.size() - 1) {

            int minimumIndex = currentIndex;
            int currentData = data.get(currentIndex);

            int leftData = data.get(leftIndex);
            int rightData = data.get(rightIndex);
            if (leftData < currentData) {
                minimumIndex = leftIndex;
            }

            if(rightIndex < data.size()) {
                if (rightData < data.get(minimumIndex)) {
                    minimumIndex = rightIndex;
                }
            }

            if(minimumIndex == currentIndex) {
                break;
            }

            data.set(currentIndex, data.get(minimumIndex));
            data.set(minimumIndex, currentData);

            currentIndex = minimumIndex;

            leftIndex = currentIndex * 2;
            rightIndex = currentIndex * 2 + 1;
        }
        return min;
    }


    public int getMin() {
        return data.get(1);
    }
}
