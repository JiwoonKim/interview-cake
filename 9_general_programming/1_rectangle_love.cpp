/**
 *  Calculate the overlap between the two rectangles
 * 
 *  Time Complexity: O(
 *  Space Complexity: O(
 * 
 *  * solution
 * 
 *    - break the problem into subproblems
 *      : intersection = horizontal overlap && vertical overlap
 *       
 *    - use helper function to find overlap in each X, Y dimension
 *      : draw out possible cases of overlapping & not overlapping
 *      
 *      => SAME as merging ranges problem (ex. 1-1. merge meeting times)
 * 
 *  ** What I learned:
 * 
 *     * RECT class = START POINT + WIDTH + LENGTH
 *       - instead of defining all 4 coordinates
 *       - defined using 1 coord on bottom left
 *         + width + length
 *       => less complicated and saves more space
 * 
 *     * define custom data structure for RANGE
 *       - MAKE IT EASY TO CONVERT BACK AND FORTH to RECT objects
 * 
 *       => define custom data structure considering ADAPTABILITY between classes
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * calculate the overlap between the two rectangles
*/ 
Rectangle findRectangularOverlap(const Rectangle& rect1, const Rectangle& rect2) { 

}
