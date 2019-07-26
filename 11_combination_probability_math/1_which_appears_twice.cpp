/**
 *  Find the number that appears twice
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  ** What I learned:
 * 
 *     ** Avoid using extra memory space 
 *        by USING MATH !
 * 
 *     * Triangular Series
 *       : (1 + 2 + ... + n-1 + n) = n * (n + 1) / 2
 * 
 *     * accumulate function
 *       : used to accumulate values in vector into init value
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  find the number that appears twice
*/
unsigned int findRepeat(const vector<unsigned int>& numbers) {
    
    unsigned int n = numbers.size() - 1;
    unsigned int sum = accumulate(numbers.begin(), numbers.end(), 0u);
    
    unsigned int triangularSum = (n * (n + 1)) / 2;
    return sum - triangularSum;
}