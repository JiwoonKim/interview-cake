/**
 *  Implement rand5() using rand7()
 *  (rand5() must return each integer 1-5 w/ equal probability)
 * 
 *  Time Complexity: O(infinite)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *    - was not sure how to get equal probability
 *    - however, I did think of solution to just return random # 1-5
 *      regardless of rand7() result
 *    - but still, was not able to figure out the 'equal probability' part
 * 
 *  ** Untangled Hints: don't be afraid to JUST COUNT
 *     - just write out all the possible RESULTS from rand7()
 *     - label each one w/ its final outcome for rand5()
 *     - then, count up how many ways there are to make each final outcome
 *       to check if it is uniformly random (counts would be the same)
 * 
 * 
 *  ** What I learned:
 * 
 *     ** RESULT'S PROBABILITY
 *        : focus on the final result's probabilty
 *          rather than the probabilty of each start
 * 
 *        ex) roll: 5 (probability of 5 = 1/7)
 *            roll: 7 -> roll: 5 (probabilty of 5 = still 1/7)
 * 
 *        -> instead of
 *           roll: 5 (probabilty of 5 = 1/7)
 *           roll: 7 -> roll: 5 (probabilty of 5 != 1/7 * 1/7) => NOT THE CASE!!
 * 
 *        => think of the end result's probability
 * 
 *     cf) fundamental theorem of arithmetic
 *         = every positive integer has only one prime factorization
 *           -> can be expressed as a product of prime numbers
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  implement rand5() using rand7()
*/
int rand5() {
    
    int result = 7;
    while (result > 5) {
        result = rand7();
    }
    return result;
}