package day1;

import java.util.Arrays;

/**
 *  Sort the arrival time in ascending order
 *  Sort the departure time in ascending order
 *  n is size of array
 *
 *  platform = 1
 *  total platform;
 *
 *  start with index 1 of arrival array with pointer name i
 *  j = index 0 of departure array
 *
 *  run a loop  i < n && j < n {
 *      if(arr[i] <= dep[j]) {
 *          platform++;
 *          i++;
 *      } else if(arr[i] > dep[j] {
 *          platform--;
 *          j++;
 *      }
 *
 *      if(platform > total platform) {
 *          total platform = platform;
 *      }
 *
 *      return total_platform;
 *  }
 */
public class MinimumPlatforms {




    public static void main(String[] args) {

    }
}
