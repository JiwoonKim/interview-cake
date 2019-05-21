/**
 *  Find the rotation point in the array
 * 
 *  Time Complexity: O(log n)
 *  ->  O(l * log n) if consider string comparison O(l), 
 *      where l is max length of strings
 * 
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 *    
 *    ** rotated array conditions (
 * 
 *       ex. sorted in incrementing order
 *           - if rotated: a[first] > a[last]
 *             => check for a[first] < a[last] to return 0 offset for rotation
 *      
 *          - rotation point: a[rotationPoint - 1] > a[rotationPoint]
 *            => be careful of indexing out of boundary
 *               ; could use a[before] > a[before + 1] and return (before + 1) instead
 * 
 *          - compare mid and start point's elements 
 *            : if a[mid] < a[start]
 *              -> left part of mid is rotated (where rotation point exists)
 *              else
 *              -> right part of mid is rotated 
 * 
 *       => use OPPOSITE OF SORTING CONDITION TO CHECK FOR ANOMALITIES (= ROTATION)
 *          
 *          ex. sorted in incrementing order but rotated (위에 예제 참고)
 *              -> use decrementing condition to check for which side it is rotated
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  find the rotation point in the array
*/ 
size_t findRotationPoint(const vector<string>& words) {
    
    // skip clear exceptions
    if (words.size() < 2) {
        throw invalid_argument("need at least two words in vector");
    }
    
    // track points startIndex, endIndex, 
    int startIndex = 0;
    int endIndex = words.size() - 1;

    // if not rotated, return 0
    if (words[startIndex] < words[endIndex]) {
        return 0;
    }
    
    // binary search for rotation point (iterative)
    while (startIndex < endIndex) {
        
        /** calculate middle index between start and end
         *  (if only two items, middle index = smaller index)
        */ 
        int midIndex = (startIndex + endIndex) / 2;
        
        /** if the midIndex is right before the rotation point
         *  (compare midIndex to midIndex + 1 to avoid indexing out of boundary
         *   -> midIndex + 1 is never out of boudary due to calculation above)
        */ 
        if (words[midIndex] > words[midIndex + 1]) {
            // 
            return (midIndex + 1);
        } 
        /** if the midIndex's word is smaller than the first word,
         *  (= goes against the sorted order(incrementing order))
        */ 
        else if (words[midIndex] < words[startIndex]) {
            // rotation point is on the left
            endIndex = midIndex - 1;
        }
        else {
            // rotation point is on the right
            startIndex = midIndex + 1;
        }
        
    }
    // if only one index left, return the index
    return startIndex + 1;
}