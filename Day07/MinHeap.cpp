#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int *harr;
    int count;
    int capacity;

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int leftChild(int index)
    {
        return (2 * index + 1);
    }

    int rightChild(int index)
    {
        return (2 * index + 2);
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->count = 0;
        this->harr = new int[this->capacity];
    }

    void insertIntoHeap(int key)
    {
        if (this->count == this->capacity)
            return;
        count++;
        int index = count - 1;
        this->harr[index] = key;

        while (index != 0 && harr[index] < harr[parent(index)])
        {
            swap(harr[index], harr[parent(index)]);
            index = parent(index);
        }
    }

    // O(1)
    int getMin() {
        if (count == 0) 
            return -1;
        return this->harr[0];
    }

    void deletionFromHeap() {
        if (count == 0)
            return;
        if (count == 1) 
            count --;
        else {
            // general case
            this->harr[0] = this->harr[this->count - 1];
            this->count--;
            minHeapify(0);
        }
    }

    void minHeapify(int index) {
        int l = leftChild(index);
        int r = rightChild(index);
        int smallest = index;

        if (l < count && this->harr[l] < this->harr[smallest]) {
            smallest = l;
        }

        if (r < count && this->harr[r] < this->harr[smallest]) {
            smallest = r;
        }

        if( smallest != index) {
            swap(this->harr[index], this->harr[smallest]);
            minHeapify(smallest);
        }
    }

};

int main()
{

}