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
 * 
 *     (2) looking for a needle in a haystack
 * 
 * 
 *  * What I learned:
 * 
 *    ** make sure array is sorted to use binary search
 * 
 *    ** binary search: cut the problem in half a DIFFERENT WAY
 *       : IN
 * 
 *    ** calculate space complexity differently depending on whether input can be altered or not
 *       
 *       ex. if can be altered -> O(1) space since can use swapping
 *           if cannot be altered -> O(n) space since need to copy array and then sort
 *  
 *     ** AVOID DESTROYING THE INPUT 
 *        : it might cause problems elsewhere in the code
 *        => try to maintain efficient time & space w/o destroying the input
 * 
 * 
 *    << COMPARISON other solutions >>
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
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  find a number that appears more than once
*/ 
unsigned int findRepeat(const vector<unsigned int>& theVector) {


    // whoops-- no duplicate
    throw invalid_argument("no duplicate!");
}