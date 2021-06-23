package day2;

/**
 * @author amgarg
 */

 /**
 * 1. Assuming arrival and dept are sorted in asc. nature
 *  result = 1;
 * 2. currentArrivalTrainTime = Consider second train schedule of arrival wala array
 *    currentDeparturTrainTime = Consider second train schedule of dept wala array
 *
 * 3. if(currentArrivalTrainTime <=- currentDepartureTrainTime ) {
 *     increase the platform by 1;
 *     currentArrivalTrainTime = arrivaIndex + 1;
 * } else {
 *     decrease Plaform by 1
  *    currentDeparturTrainTime = deptIndex  + 1;
 * }
  *
  * if(result < platform) {
  *     result = plaform;
  * }
 */
public class MinimumNumberOfPlatforms {


    public static int minPlatforms(int [] arr, int dep[]) {

        int result = 1;

        int arrivalIndex = 1;
        int departureIndex = 0;
        int platformRequired = 1;



        while (arrivalIndex < arr.length && departureIndex < dep.length) {

            int currentArrivalTime = arr[arrivalIndex];
            int currentDepartureTime = dep[departureIndex];

            if(currentArrivalTime <= currentDepartureTime) {
                platformRequired++;
                arrivalIndex++;
            } else {
                platformRequired--;
                departureIndex++;
            }

            if(platformRequired > result) {
                result = platformRequired;
            }
        }

        return  result;
    }


     public static void main(String[] args) {

        int arr[] = {900, 915, 1100};
        int dep[] = {1000, 1105, 1200};

         System.out.println(minPlatforms(arr, dep));
     }
}
