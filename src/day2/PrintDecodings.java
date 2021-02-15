package day2;


public class PrintDecodings {

    public static void printAlllDecoing(String number, String output) {

        if(number.length() == 0) {
            System.out.println(output);
            return;
        }

        String firstCharacter = number.substring(0,1);


        int firstNumber = Integer.parseInt(firstCharacter);

        if(firstNumber != 0) {
            char character = (char)('a' + firstNumber - 1);
            printAlllDecoing(number.substring(1), output + character);
        }

        if(number.length() <= 1) {
            return;
        }

        String firstTwoCharacters = number.substring(0,2);


        int firstTwoNumber = Integer.parseInt(firstTwoCharacters);


        if(firstTwoNumber <= 26) {
            char character = (char)('a' + firstTwoNumber - 1);
            printAlllDecoing(number.substring(2), output + character);
        }


    }

    public static void main(String[] args) {

        printAlllDecoing("20", "");
    }

}
