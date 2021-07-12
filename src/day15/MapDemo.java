package day15;

import java.util.HashMap;

/**
 * @author amgarg
 */
public class MapDemo {


    public static void main(String[] args) {


        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(1, 3);
        map.put(1, 4);


        CustomMap customMap = new CustomMap();

        map.put(1, 5);
        map.put(4, 9);

        System.out.println(map.get(4));



    }
}
