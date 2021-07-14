/**
 *  Return vector of products of all other numbers except the one at index
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 *    
 *    ** how to break down the problem: 
 *       (Did this w/o seeing any hints!! :) ) 
 *       
 *       ex. products of all integers except 1 
 *           = (products of all integers except 1 & 2) x 2
 *           = (products of all integers except 1 & 2 & 3) x 2 x 3
 *           ...
 * 
 *           -> product of all integers except the integer at each index
 *              = the product of all integers before each index
 *                * the product of all integers after each index
 *           => just GREEDILY store each product SO FAR
 * 
 *       => look at WHAT THE SOLUTION ACTUALLY CALCULATES
 *          and find REPEATED WORK to improve on
 *          (final answers mostly come from brainstorming ways to avoid doing that repeated work)
 * 
 *    2) space optimization
 *       : see if you can optimize the space,
 *         even if its still O(n)
 *         
 *         ex. maybe we can have a way w/o using an extra vector?
 *             -> use productBefore and productAfter variable instead
 * 
 *    3) clean up code
 *       : see if you can clean up the code for the FOR LOOP
 *         (not necessary but good practice to make more readable and logical code)
 *        
 *         ex.  a) product[0] = 1;
 *                 for (int i = 1; i < n; i++) {
 *                      product[i] = product[i - 1] * nums[i - 1];
 *                 }
 * 
 *              b) productBefore = 1;
 *                 for (int i = 0; i < n; i++) {
 *                      product[i] = productBefore;
 *                      productBefore *= nums[i];
 *                 }
 * 
 *              => 차이: a) based on (i - 1) so needs to loop from 1
 *                       b) based on productBefore variable so loops from 0 
 *                          and simply needs to update value each time
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  return vector of products of all other numbers except number at that index
*/ 
vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector) {

    // skip clear exceptions
    int size = intVector.size();
    if (size < 2) {
        throw invalid_argument("need at least 2 integers in vector");
    }

    // keep track of products of all ints before and after index
    int productBefore = 1;
    int productAfter = 1;
    
    // keep track of product of all ints except index
    vector<int> productOfAllIntsExceptAtIndex(size);
    
    // iterate over each element in intVector
    for (int i = 0; i < size; i++) {
        
        // get product of all ints before index
        productOfAllIntsExceptAtIndex[i] = productBefore;

        // update product so far to include current int
        productBefore *= intVector[i];
    }
    
    // iterate over each element in intVector (backwards)
    for (int i = size - 1; i >= 0; i--) {
        
        // get product of all ints after index
        productOfAllIntsExceptAtIndex[i] *= productAfter; 

        // update product so far to include current int
        productAfter *= intVector[i];
    }
    
    // return values
    return productOfAllIntsExceptAtIndex;
}