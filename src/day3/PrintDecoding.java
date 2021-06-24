package day3;


public class PrintDecoding {


    public static void printAllDecoding(String number, String output) { //


        if (number.length() == 0) {
            System.out.println(output);
            return;
        }

        String firstCharacter = number.substring(0, 1); //3

        int firstNumber = Integer.parseInt(firstCharacter); //3

        if (firstNumber != 0) {
            char character = (char) ('a' + firstNumber - 1); //c
            printAllDecoding(number.substring(1), output + character);
        }


        if (number.length() <= 1) {
            return;
        }

        int firstTwoNumber = Integer.parseInt(number.substring(0, 2));

        if (firstTwoNumber <= 26) {
            if(firstTwoNumber <= 0) {
                printAllDecoding(number.substring(2), output + "");
                return;
            }
            char character = (char) ('a' + firstTwoNumber - 1);
            printAllDecoding(number.substring(2), output + character);
        }
    }


    public static void main(String[] args) {
        printAllDecoding("12371", "");
    }

}
