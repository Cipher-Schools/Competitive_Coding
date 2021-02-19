package day7;


public class MinHeapUse {


    public static void main(String[] args) {

        MinHeap heap = new MinHeap();

        heap.insert(15);
        heap.insert(19);
        heap.insert(11);
        heap.insert(20);

        System.out.println(heap.getMin());


        heap.removeMin();

        System.out.println(heap.getMin());



    }
}
