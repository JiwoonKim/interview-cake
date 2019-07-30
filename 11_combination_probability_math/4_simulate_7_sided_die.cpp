/**
 *  Implement rand7() using rand5()
 *  (rand7() must return each integer 1-7 w/ equal probability)
 * 
 *  Time Complexity: O(infinite)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *    - figured out that need to at least roll die twice
 *    - but, could not figure how to expand 1-5 to 1-7 w/ equal probability of each
 * 
 *  ** Untangled Hints: distribute the results along slots
 *     1) start w/ 25 possible outcome SLOTS (roll die twice: 5* 5)
 *     2) distribute 1 - 7 as EQUALLY AS POSSIBLE
 *        : int result[25] = {
 *              1, 2, 3, 4, 5,
 *              6, 7, 1, 2, 3,
 *              4, 5, 6, 7, 1,
 *              2, 3, 4, 5, 6,
 *              7, 1, 2, 3, 4
 *          };
 *     3) THROW OUT extraneous results and REROLL!
 *        (for each 1 - 7 to have EQUAL PROBABILITY)
 * 
 * 
 *  ** What I learned:
 * 
 *     ** EXPAND POSSIBLE OUTCOMES & THROW AWAY EXTRANEOUS RESULTS
 *        - expand possible outcomes by increasing the rolls
 *        - throw away the extraneous bits which make the probability inequal
 *          (reroll when outcome is in those extraneous bits)
 * 
 *        cf) PRIME FACTORIZATION (used to prove)
 *            : no matter how many times 5-sided die is rolled, probability always (5*5*5*...)
 *              -> never divisible by 7 (proved by prime factorization)
 * 
 *            => instead, just expand the possible outcomes and cut off remaining bits
 * 
 *     ** RE-ROLLING method
 *        - roll until out come is in desired range
 *          => ensure equal probability
 * 
 *     ** define each roll w/ their own dimension 
 *        - so that there is an equal chance of choosing any row, column
 *          and there are NEVER TWO WAYS to choose the same cell
 * 
 *          ex) results[5][5] -> row for first roll,
 *                               col for second roll
 * 
 *          cf) multiplication of first roll and second roll could have 
 *              problems of choosing the same call multiple time (!= equal probability)
 *          
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  implement rand7() using rand5()
*/
int rand7() {

    // define possible outcomes w/ equal probability
    const int results[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 1, 2, 3},
        {4, 5, 6, 7, 1},
        {2, 3, 4, 5, 6},
        {7, 0, 0, 0, 0},
    };

    // roll dice until out come is 1-7 integer
    int row = 4;
    int col = 4;
    while (results[row][col] == 0) {
        row = rand5() - 1;
        col = rand5() - 1;
    }
    return results[row][col];
}

/**
 *  same solution
 *  but w/o using memory to define results
 *  and instead, using math
*/
int rand7() {
    while (true) {
        // do our die rolls
        int roll1 = rand5();
        int roll2 = rand5();

        int outcomeNumber = (roll1 - 1) * 5 + (roll2 - 1) + 1;

        // if we hit an extraneous
        // outcome we just re-roll
        if (outcomeNumber > 21) {
            continue;
        }

        // our outcome was fine. return it!
        return outcomeNumber % 7 + 1;
    }
}