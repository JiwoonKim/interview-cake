/**
 *  Find unique integer within vector of duplicate integers.
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *     - could not figure how to optimize further from solution using unordered set (O(n) time & O(n) space)
 * 
 *  ** Untangled Hints: can use BIT MANIPULATION (bit manipulation patterns 숙지하기)
 *     
 *     ** CANCEL OUT matching numbers by using XOR
 *        : when same integers are XOR-ed, they just become 0
 *          -> so pairs cancel each out and the one remaining integer is the unique one
 *             ( 0 ^ any number = any number)
 * 
 *  ** What I learned:
 * 
 *     ** BIT MANIPULATION PATTERNS
 * 
 *        (1) CANCEL OUT matching numbers using XOR
 * 
 *        (2) MULTIPLY / DIVIDE BY 2 (use LEFT SHIFT / RIGHT SHIFT)
 * 
 *        => think if you can use BIT MANIPULATION 
 *           to optimize with problem dealing with INTEGERS
 *  
 *     * OPTIMIZE
 *       - initially, had the idea of using set to track pairs by inserting and erasing
 *       - only when ASKED TO OPTIMIZE TO O(1) space did I start to look for other solutions
 * 
 *       => need to learn how to grasp which side I should focus on optimizing
 *          : space or time ?
 * 
 *     ** practice to FIND OPTIMIZATION POINTS
 *        EVEN AFTER THE PROBLEM HAS BEEN SOLVED
 *        (learn try to take the problem ONE STEP FURTHER by trying to find any further optimization points)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  find the one unique ID in the vector
*/
int findUniqueDeliveryId(const vector<int>& deliveryIds) {

    int xor_result = 0;

    /** XOR every deliveryId 
     *  (to cancel out matching integers)
    */
    for (auto deliveryId : deliveryIds) {
        xor_result ^= deliveryId;
    }
    
    // the XOR-ed result is the unique deliveryId
    return xor_result;
}