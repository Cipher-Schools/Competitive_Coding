package day1;


/**
 * If someone is ahead of other and have greater speed, in that case they will never meet
 *
 * Let the both the persons run or walk or jump with their respective speeds
 *
 * Till they either cross each other or meet each other
 *
 */

public class PeopleMeetEachOther {


    public static boolean isMeet(int  p1, int p2, int s1, int s2) {

        if(p1 > p2 && s1 > s2) {
            return false;
        }

        if(p2 > p1 && s2 > s1) {
            return  false;
        }



        //Asssuming p1 is ahead.
        while (p1 >= p2) {
            if(p1  == p2) {
                return true;
            }
            p1 = p1 + s1;
            p2 = p2 + s2;
        }
        return false;
    }


    public static boolean isMeetOptimized (int  p1, int p2, int s1, int s2) {
        if(p1 > p2 && s1 > s2) {
            return false;
        }

        if(p2 > p1 && s2 > s1) {
            return  false;
        }

        int distanceNeedsToBeCovered = Math.abs(p1 - p2);
        int speedNeedsToBeUsed = Math.abs(s1 - s2);

        if(distanceNeedsToBeCovered % speedNeedsToBeUsed == 0) {
            return  true;
        }
        return false;

    }

    public static void main(String[] args) {

        int p1 = 6;
        int p2 = 4;

        int s1 = 6;
        int s2 = 8;

        boolean ans = isMeetOptimized(p1, p2, s1, s2);

        if(ans == true) {
            System.out.println("They met");
        } else {
            System.out.println("They didn't");
        }
    }
}
