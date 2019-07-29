/**
 *  Check if an integer is present in the sorted vector.
 * 
 *  Time Complexity: O(log n)
 *  Space Complexity: O(1)
 * 
 *  ** What I learned:
 * 
 *     ** BINARY SEARCH code
 *        - (code is always a little bit confusing ㅠㅜ)
 *        - remember ITERATIVE version and RECURSIVE VERSION
 *        - especially SEARCHING CONDITION for recursive version & iterative version (are the same)
 *          : (if end >= start)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  check if an integer is present in the sorted vector
 *  (ITERATIVE VERSION of binary search)
*/
bool contains(const vector<int>& v, int n) {
    
    int start = 0;
    int end = v.size() - 1;

    while (start <= end) {

        int mid = (start + end) / 2;
        if (v[mid] == n) {
            return true;
        } else if (v[mid] > n) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}

/**
 *  check if an integer is present in the sorted vector
 *  (RECURSIVE VERSION of binary search)
*/
bool contains(const vector<int>& v, int n) {
    
    return binarySearch(v, n, 0, v.size() - 1);
}

/**
 *  helper function: binary search
 *  (for RECURSIVE SOLUTION)
*/
bool binarySearch(const vector<int> & v, int n, int start, int end) {
    
    // check condition for searching
    if (end >= start) {
        
        int mid = (start + end) / 2;
        // check if mid value is target
        if (v[mid] == n) {
            return true;
        } 
        // search over left half
        else if (v[mid] > n) {
            return binarySearch(v, n, start, mid - 1);
        } 
        // search over right half
        else {
            return binarySearch(v, n, mid + 1, end);
        }
    }
    return false;
}