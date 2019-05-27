/**
 *  Find Duplicates in array (space mode)
 *  -> optimize space mode w/o altering the input array
 * 
 *  Time Complexity: O(nlogn)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *     - could not figure how to get efficient solution if input array cannot be altered
 *       (how to get O(1) space w/o swapping the contents of the array??)
 *       -> so far, got to solution (c) illustrated below
 * 
 *  ** Untangled Hints:
 * 
 *     (1) breakdown to subproblem
 *         -> finding an element (if element i, FIND if duplicate exists in array)
 *         -> most efficient way: binary search
 *                                but array needs to be sorted...ã… ã…œ
 *     
 *     (2) cut problem in half a DIFFERENT WAY
 *         -> cut the SET OF POSSIBILITIES for a repeated number along with size
 *         
 *         ** ANALOGY: pigeonholes (n), pigeons (n+1) 
 *                     = possible numbers (n), elements (n+1)
 *         
 *           (1) cut down the pigeonholes range in half and count the number of pigeons that actually fit into those holes
 *           (2) compare the number of pigeonholes vs number of actual pigeons that fit into those holes
 *               - if pigeons > pigeonholes, duplicates exists in current range so recurse/iterate to (1) using the cut-down range
 *               - else, duplicates exist in other half range so recurse/iterate to (1) using the other half range
 * 
 *         ** it's possible to use this method bcuz of the PIGEONHOLE PRINCIPLE
 * 
 *      => combine binary search + pigeonhole principle
 *          
 *         TIP: try to think of pigeonholes and pigeon analogy
 *              "what fits into what"
 * 
 * 
 *  * What I learned:
 * 
 *    ** make sure array is sorted to use binary search
 * 
 *    ** cut the problem in half a DIFFERENT WAY
 *       : cut the size and possibilities (of the content) at the same time,
 *         and take advantage of the pigeonhole principle
 * 
 *    ** Pigeonhole Principle
 *       : if n items are put into m containers, with n > m, 
 *         then at least one container must container more than one item
 *       ; we have more items than we have possibilities, so we must have at least one repeat
 *      
 *        ex. n numbers possible in (n + 1) elements, 
 *            n pigeonholes and (n + 1) pigeons,   
 *            left and right type of gloves in group of three gloves (=> at least two left gloves or right gloves)
 * 
 *    ** calculate space complexity differently depending on whether input can be altered or not
 *       
 *       ex. if can be altered -> O(1) space since can use swapping
 *           if cannot be altered -> O(n) space since need to copy array and then sort
 *  
 *       => AVOID DESTROYING THE INPUT 
 *          -> it might cause problems elsewhere in the code
 *          -> try to maintain efficient time & space w/o destroying the input
 * 
 * 
 *    << COMPARISON of other solutions >>
 * 
 *        a. iterate over each element and store/check in hash map
 *           (keep track of which items we've already seen)
 *           -> O(n) time, O(n) space
 * 
 *        b. for each element, check other elements in array each time
 *           -> O(n^2) time, O(1) space
 * 
 *        c. sort the vector and check each element for repetition of same elements
 *           -> O(nlogn) time, O(1) or O(n)
 *           -> but destroying input could also pose potential problems elsewhere, so try to avoid
 *
 *        d. combine binary search + pigeonhole principle
 *           (1) cut down the pigeonholes range in half and count the number of pigeons that actually fit into those holes
 *           (2) compare the number of pigeonholes vs number of actual pigeons that fit into those holes
 *               - if pigeons > pigeonholes, duplicates exists in current range so recurse/iterate to (1) using the cut-down range
 *               - else, duplicates exist in other half range so recurse/iterate to (1) using the other half range
 *           -> O(nlogn) time, O(1) space
 * 
 *        e. cycle detection (Floyd's turtoise and hare) -> check 8-5. find duplicate (beast mode)
 *           -> O(n) time, O(1) space 
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  find a number that appears more than once
 *  (advanced version of binary search
 *   -> cut down size and possibilities together each time
 *   => cut down number of pigeons and pigeonholes, and use pigeonhole principle to find duplicates)
*/ 
unsigned int findRepeat(const vector<unsigned int>& theVector) {

    // throw error for clear exceptions
    if (theVector.size() < 2) {
        throw invalid_argument("need at least two elements in vector to check for duplicates");
    }

    int start = 1;
    int end = theVector.size() - 1;
    
    while (start < end) {
        
        /** cut range of possible numbers in half
         *  (cut the number of pigeonholes into a specific range)
         *  : (start ~ mid)
        */ 
        int mid = (start + end) / 2;
        
        /** iterate over all elements in vector
         *  to count how many elements actually fit into the cut-down pigeonholes range
         *  (count the number of pigeons that go into those pigeonholes)
        */ 
        int numberOfFitElements = 0;
        
        for (auto item : theVector) {
            
            if (start <= item && item <= mid) {
                numberOfFitElements++;
            }
        }
        
        // calculate the number of pigeonholes
        int numberOfElementInRange = mid - start + 1;
        
        /** compare the pigeonholes and pigeons
         *  to check if the pigeonhole principle holds for the range
         *  (number of pigeons fit in the range > number of pigeonholes)
         *  -> if it holds, duplicate is in that range
         *  -> else, duplicate is in other half of range
        */ 
        if (numberOfFitElements > numberOfElementInRange) {
            
            /** duplicate is in current range,
             *  so update the range to current range (like binary search)
            */ 
            end = mid;
        } 
        else {
            /**
             *  duplicate is in other half of range,
             *  so update the range to the other half range (like binary search)
            */ 
            start = mid + 1;
        }
    }
    
    /** if there is only one element in range (start == end),
     *  that remaining number is the duplicate!
     */ 
    return start;
}
/** Calculating Complexities
 *  - cutting down pigeonholes and pigeon possibilities each time: O(log n)
 *      - for each cut-down range (pigeonholes), count the actual pigeons that fit: O(n)
 *      - then, compare the number of pigeonholes vs number of actual pigeons that fit into those holes
 *  => O(n * log n)
*/ 