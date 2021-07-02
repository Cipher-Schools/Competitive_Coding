package day7;

/**
 *
 * 1. Break the LL into 2 parts
 *    a. find the mid of linkedList and create two seperate LL
 * 2. LL1 = firstHalf
 *    LL2 = secondHalf
 *
 * 3. Reverse the secondHalf
 * 4. Merge LL1 and LL2
 *    while(ll2 != null) {
 *        rest = ll1.next;
 *        ll1.next = ll2;
 *        ll1 = ll2;
 *        ll2 = rest;
 *    }
 */
public class RestructureLL {
}
