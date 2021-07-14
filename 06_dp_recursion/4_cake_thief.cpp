/**
 *  Calculate the maximum value that we can carry
 * 
 *  Time Complexity: O(N * C) -> N = number of cakes, C = given capacity (weight)
 *  Space Complexity: O(C)
 * 
 *  * What I learned:
 * 
 *    ** Unbounded Knapsack Problem
 * 
 *       ** build by finding the max profit for each weight capacity (until reach goal capacity)
 *          -> for each capacity, 
 *             check all the cakes: if they fit, calculate the profit (cake value + maxprofit of remaining space)
 *                                  -> update the max profit 
 * 
 *          => use Memoization and Dynamic Programming
 * 
 *       cf) do not check cakes in value/weight order
 *           -> this does not guarantee max profit
 *           -> have to check combinations
 * 
 * 
 *    ** Keep in mind that in some cases, it MIGHT NOT BE WORTH using optimal dp solution
 *       : bcuz its realy slow (depends on N of K value)
 * 
 *       -> if cared about time and had to move quickly,
 *          it MIGHT BE WORTH using a faster algorithm that gives us a GOOD ANSWER,
 *          even if it is NOT ALWAYS the OPTIMAL ANSWER
 * 
 *       -> in these cases, it might be worth to use the value/weight sorting method
 *       
 *       => SOMETIMES, an efficient & GOOD answer might be MORE PRACTICAL than an inefficient OPTIMAL answer
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class CakeType
{
public:
    const unsigned int weight_;
    const unsigned int value_;

    CakeType(unsigned int weight = 0, unsigned int value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};

/**
 *  calculate the maximum value that we can carry
 */
unsigned long long maxDuffelBagValue(const vector<CakeType>& cakeTypes, unsigned int weightCapacity) {
    
    // save max profit for each weightCapacity of bag
    vector<unsigned long long> profit(weightCapacity + 1, 0);
    
    // find max profit for each capacity (build up to weightCapacity)
    for (int i = 1; i <= weightCapacity; i++) {
        
        long long maxValue = 0;
        
        // check cakes fit into capacity
        for (auto cake : cakeTypes) {
            
            // throw excpetion if cake weights 0 but value is positive
            if (cakeType.weight_ == 0 && cakeType.value_ != 0) {
                throw range_error("Max value is infinity!");
            }
            
            // if cake fits,
            if (cake.weight_ <= i) {
                
                // calculate value (utilize memoization)
                long long totalValue = cake.value_ + profit[i - cake.weight_];
                    
                // update profit if max value
                maxValue = max(maxValue, totalValue);
            }
        }
        
        // store profit value for memoization
        profit[i] = maxValue;
    }
    
    // return the max profit in the given capacity
    return profit[weightCapacity];
}