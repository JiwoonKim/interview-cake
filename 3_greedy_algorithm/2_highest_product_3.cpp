/**
 *  Calculate the max profit value of buying and selling stock prices
 *  (the buying price must come before the selling price)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    - carefully curate ADDITIONAL VALUES to track in order to update BEST ANSWER SO FAR
 *      -> 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  calculate the highest product of three numbers
*/ 
int highestProductOf3(const vector<int>& nums) {

    // skip clear exceptions
    if (nums.size() < 3) {
        throw invalid_argument("Needs at least 3 integers in vector");
    }

    // track of highest and lowest numbers
    int highest = max(nums[0], nums[1]);
    int lowest = min(nums[0], nums[1]);
    
    /** track highest and lowest product of 2 integers 
     *  (maxProduct2 = top1 * top2 || neg1 * neg2)
     *  (minProduct2 -> necessary if all integers are negative)
    */ 
    int maxProduct2 = nums[0] * nums[1];
    int minProduct2 = nums[0] * nums[1];
    
    // track max product of 3 integers
    int maxProduct3 = nums[0] * nums[1] * nums[2];
    
    // iterate over numbers in Nums vector
    for (int i = 2, n = nums.size(); i < n; i++) {
        
        int num = nums[i];
        
        // update highest product of 3 integers
        maxProduct3 = max(maxProduct3, max(maxProduct2 * num, minProduct2 * num));
        
        // update highest and lowest product of 2 integers
        maxProduct2 = max(maxProduct2, max(num * highest, num * lowest));
        minProduct2 = min(minProduct2, min(num * highest, num * lowest));
        
        // update highest and lowest numbers
        highest = max(highest, num);
        lowest = min(lowest, num);
    }
    // return value
    return maxProduct3;
}