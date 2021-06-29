package day6;


/**
 * 1. Create an array of 256 characters
 * 2. Iterate over the string {
 *   a. c = get the currentCharacter
 *   b. check this character is in our array
 *     if(notAvailable)
 *      createNode for this character and append in our DLL
 *     else
 *      delete this node from our DLL
 *
 *     print the head of DLL
 *     }
 */
public class FindFirstUniqueCharacter {



    public static void printFirstUniqueCharacter(String str) {

        int size = str.length();
        DLLNode [] charMap = new DLLNode[256];
        boolean [] repeated = new boolean[256];

        DLLOperations dll = new DLLOperations();

        for(int i = 0; i < size; i++) {
            char c = str.charAt(i);

            if(!repeated[c]) {
               if(charMap[c] == null) {
                   dll.append(c);
                   charMap[c] = dll.last;
               } else {
                   dll.delete(charMap[c]);
                   repeated[c] = true;
               }
            }

            if(dll.head != null) {
                System.out.println("First Unique Character ");
                System.out.println(dll.head.data);
            }
        }

    }


}
