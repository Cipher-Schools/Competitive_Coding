package day15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author amgarg
 */
public class CinemaAllocation {


    public static int maxNumberOfFamilies(int n, int[][] reservedSeats) {


        int result = 0;
        Map<Integer, List<Integer>> reservedSeatMap = new HashMap<>();

        for (int[] row : reservedSeats) {
            if (reservedSeatMap.containsKey(row[0])) {
                reservedSeatMap.get(row[0]).add(row[1]);
            } else {
                reservedSeatMap.put(row[0], new ArrayList<>(Arrays.asList(row[1])));
            }
        }

        result = (n - reservedSeatMap.size()) * 2;

        for (List<Integer> res : reservedSeatMap.values()) {
            boolean settled = false;


            if (!res.contains(2) && !res.contains(3) && !res.contains(4) && !res.contains(5)) {
                result++;
                settled = true;
            }

            if (!res.contains(6) && !res.contains(7) && !res.contains(8) && !res.contains(9)) {
                result++;
                settled = true;
            }


            if (!settled) {
                if (!res.contains(4) && !res.contains(5) && !res.contains(6) && !res.contains(7))
                    result++;
            }
        }

        return result;
    }



}
