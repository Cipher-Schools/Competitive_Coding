package day2;


/**
 * 1. Calculate leftMax for every Building.
 * 2. Calculate rightMax for every Building.
 * <p>
 * WaterUnits =  0;
 * 3. Iterate over buildingArray
 * leftMax = getLeftMax for this building from leftMax array
 * rightMax = getRightMax for this building from rightMax array
 * <p>
 * waterUnits = waterUnits + Math.min(leftMax, rightMax) - currentBuildingHeight;
 * <p>
 * return waterUnits;
 */
public class TrappingRainWater {

    public static int getWaterUnits(int[] buildinArray) {
        int[] left = new int[buildinArray.length];
        int[] right = new int[buildinArray.length];
        int n = buildinArray.length;

        left[0] = buildinArray[0];

        int waterUnits = 0;
        for (int leftIndex = 1; leftIndex < left.length; leftIndex++) {
            left[leftIndex] = Math.max(left[leftIndex - 1], buildinArray[leftIndex]);
        }

        right[buildinArray.length - 1] = buildinArray[buildinArray.length - 1];
        for (int rightIndex = buildinArray.length - 2; rightIndex >= 0; rightIndex--) {
            right[rightIndex] = Math.max(right[rightIndex + 1], buildinArray[rightIndex]);
        }

        for (int currentIndex = 0; currentIndex < buildinArray.length; currentIndex++) {
            waterUnits = waterUnits + (Math.min(left[currentIndex], right[currentIndex]) - buildinArray[currentIndex]);
        }
        return waterUnits;
    }

    public static void main(String[] args) {
        int a [] = {5, 0, 5, 3, 2, 1, 4};

        System.out.println(getWaterUnits(a));
    }

}
