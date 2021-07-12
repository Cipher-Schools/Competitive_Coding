package day15;

import java.util.ArrayList;


class MapNode {
    int key;
    int value;
    MapNode next;

    public MapNode(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

public class CustomMap {

    private ArrayList<MapNode> bucketList;
    private int size;
    private int bucketlistSize;

    public CustomMap() {

        bucketList = new ArrayList<>();
        bucketlistSize = 11;

        for (int i = 0; i < bucketlistSize; i++) {
            bucketList.add(null);
        }
    }


    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }


    public void put(int key, int value) {
        int bucketIndex = getBucketIndex(key);
        MapNode head = bucketList.get(bucketIndex);
        MapNode temp = head;

        while (temp != null) {
            if (temp.key == key) {
                temp.value = value;
                return;
            }
            temp = temp.next;
        }
        MapNode newNode = new MapNode(key, value);
        newNode.next = head;
        bucketList.set(bucketIndex, newNode);
        size++;

        //load factor
        if ((1.0) * size / bucketlistSize > 0.7) {
            rehash();
        }
    }

    private void rehash() {
        ArrayList<MapNode> temp = bucketList;
        bucketList = new ArrayList<>();

        for (int i = 0; i < bucketlistSize * 2; i++) {
            bucketList.add(null);
        }

        bucketlistSize = bucketlistSize * 2;
        size = 0;

        for (MapNode head : temp) {
            while (head != null) {
                put(head.key, head.value);
                head = head.next;
            }
        }
    }


    public int get(int key) {
        int bucketIndex = getBucketIndex(key);
        MapNode head = bucketList.get(bucketIndex);
        MapNode temp = head;
        while (temp != null) {
            if (temp.key == key) {
                return temp.value;
            }
            temp = temp.next;
        }
        return Integer.MIN_VALUE;
    }


    private int getBucketIndex(Integer key) {

        int hashCode = Math.abs(key.hashCode());
        int compressed = hashCode % bucketlistSize;
        return compressed;
    }
}