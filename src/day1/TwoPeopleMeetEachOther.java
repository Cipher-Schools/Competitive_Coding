package day1;

public class TwoPeopleMeetEachOther {


    public static boolean isMeet(int d1, int d2, int v1, int v2) {
        if(d1 > d2 && v1 > v2) {
            System.out.println("They will never meet");
            return false;
        }

        if (d2 > d1 && v2 > v1) {
            System.out.println("They will never meet");
            return false;
        }


        //Assuming d1 will always be ahead in starting

        while(d1 >= d2) {  //d2 > d1

            if(d1 == d2) {

                System.out.println(d1);
                return  true;
            }
            d1 = d1 + v1;

            d2 = d2 + v2;
        }

        return false;

    }


    public static boolean isMeetUsingRelativeSpeed(int d1, int d2, int v1, int v2) {

        if(d1 > d2 && v1 > v2) {
            System.out.println("They will never meet");
            return false;
        }

        if (d2 > d1 && v2 > v1) {
            System.out.println("They will never meet");
            return false;
        }

        int D = d1 - d2;
        int V = v1 - v2;

        if(D % V == 0) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {

        int d1 = 6;
        int d2 = 4;

        int v1 = 6;
        int v2 = 8;



        System.out.println(isMeetUsingRelativeSpeed(d1, d2, v1, v2));



    }
}
