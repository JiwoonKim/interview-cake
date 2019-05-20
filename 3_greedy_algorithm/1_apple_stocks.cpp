/**
 *  Calculate the max profit value of buying and selling stock prices
 *  (the buying price must come before the selling price)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    ** Greedy Approach
 *       - builds up a solution by choosing the BEST OPTION SO FAR at every step
 *       - does not guarantee optimal solution
 *         -> best bet is to try it out and see if it works
 *      
 *       => trying out a greedy approach should be one of the first ways to try to break down a question
 *          
 *          -> ask yourself: 
 * 
 *             "SUPPOSE we could come up with the answer in one pass through the input, 
 *              by simply updating the BEST ANSWER SO FAR as we went. 
 *              What ADDITIONAL VALUES would we need to keep updated as we looked at each item in our input, 
 *              in order to be able to UPDATE the best answers so far in constant time?""
 * 
 *    ** Throwing Exceptions (for exceptional cases)
 *       : `throw invalid_argument("")`
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  calculate the max profit
 */
int getMaxProfit(const vector<int>& stockPrices) {

    // check clear exceptional cases
    if (stockPrices.size() < 2) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }

    // track minimum price and maximum profit
    int minPrice = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];
    
    /** iterate over stock prices for comparison
     *  (makes sure buying price(minPrice) comes before selling price(i))
    */
    for (int i = 1, n = stockPrices.size(); i < n; i++) {

        int currentPrice = stockPrices[i];
        
        // update max profit value
        int potentialProfit = currentPrice - minPrice;
        maxProfit = max(maxProfit, potentialProfit);
        
        // update min stock price
        minPrice = min(minPrice, stockPrices[i]);
        
    }
    
    // return max profit value
    return maxProfit;
}