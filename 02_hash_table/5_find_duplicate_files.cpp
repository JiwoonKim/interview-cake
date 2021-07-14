/**
 *  Find duplicate files in a file system
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    ** how to implement a FILE SYSTEM in C++
 *       (use libraries: )
 * 
 *    ** FINGER PRINTING
 * 
 *    ** use classes to make code MODULAR
 * 
 *      
 *    ** Good example of MESSY interview problesm
 *       : instead of optimal solution, 
 *         there's a big knot of optimizations and trade-offs
 * 
 *       => focus on clearly explaining to your interviewer what the trade-offs are for each decisions you make.
 *          ; the actual choices you make probably don't matter that much,
 *            as long as you show a strong ability to understand and compare your options
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  find files within directory (use iterative method to avoid stack overflow)
 *  -> each file check if hash value (footprint) exists in hash map
 *     -> if exists, check if file content matches
 *        -> if matches, figure out which of the two is the duplicate file
 *  -> else, add to hash map
 * 
 *  - heuritics: 
 *    1) create footprint for files by hashing by size, file content, etc.
 *    2) check which is duplicate by comparing time stamps
 */