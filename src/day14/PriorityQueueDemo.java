package day14;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author amgarg
 */
public class PriorityQueueDemo {


    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
           return Integer.compare(o2, o1);

        }
    });


    PriorityQueue<Integer> minHeap = new PriorityQueue<>(new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            return Integer.compare(o1, o2);

        }
    });

    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();



        pq.add(5);
        pq.offer(1);
        pq.add(3);

        System.out.println(pq.peek());


        MinHeap heap = new MinHeap();

        heap.addElement(5);
        heap.addElement(1);
        heap.addElement(3);

        System.out.println(heap.getMin());


        System.out.println(heap.removeMin());

        System.out.println(heap.removeMin());

        System.out.println(heap.getMin());


    }
}
