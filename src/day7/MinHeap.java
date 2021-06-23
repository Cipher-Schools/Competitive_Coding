package day7;


import java.util.ArrayList;

public class MinHeap {


    private ArrayList<Integer> data;

    public MinHeap() {
        data = new ArrayList<>();
        data.add(null);
    }


    public boolean isEmpty() {
        if(data.size() == 1) {
            return true;
        }
        return false;
    }

    public int size () {
        return data.size() - 1;
    }


    public void insert(int element) {
        data.add(element);
        int currentIndex = data.size() - 1;
        int parentIndex = currentIndex / 2;

        while(currentIndex != 1) {
            if (data.get(currentIndex) >= data.get(parentIndex)) {
                //Everything fine
                break;
            } else {
                int currentData = data.get(currentIndex);
                int parentData = data.get(parentIndex);
                data.set(currentIndex, parentData);
                data.set(parentIndex, currentData);
                currentIndex = parentIndex;
                parentIndex = currentIndex / 2;
            }
        }
    }

    public int getMin() {
        return data.get(1);
    }


    //Heapify Operation -> O(log n)
    public int removeMin() {
        int min = data.get(1);

        int last = data.get(data.size() - 1);

        data.set(1, last);
        data.remove(data.size() - 1);


        int currentIndex = 1;
        int leftChildIndex = 2 * currentIndex;
        int rightChildIndex = leftChildIndex + 1;

        while(leftChildIndex < data.size() - 1) {
            int minIndex = currentIndex;
            int currentData = data.get(currentIndex);
            int leftData = data.get(leftChildIndex);
            int rightData = data.get(rightChildIndex);

            if (leftData < currentData) {
                minIndex = leftChildIndex;
                min = data.get(leftChildIndex);
            }

            if (rightChildIndex < data.size()) {
                if (rightData < data.get(minIndex)) {
                    minIndex = rightChildIndex;
                    min = data.get(minIndex);
                }
            }

            if (minIndex == currentIndex) {
                // no need to perform anything
                break;
            }

            data.set(currentIndex, data.get(minIndex));
            data.set(minIndex, currentData);
            currentIndex = minIndex;
            leftChildIndex = 2 * currentIndex;
            rightChildIndex = leftChildIndex + 1;
        }
        return min;
    }



}
