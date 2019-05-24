/**
 *  Compute the Fibonacci number 
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 *    
 *    1) edge cases for Fibonacci number
 *       - n < 0, throw error (no such thing as negative fibonacci number)
 *       - n = 0, fib(0) = 0
 *       - n = 1, fib(1) = 1
 *       - n > 1, fib(n) = fib(n-1) + fib(n-2)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  compute the nth Fibonacci number
 *  (iteratively and in constant space)
 */
int fib(int n) {
    
    // throw error for EDGE CASES
    if (n < 0) {
        throw invalid_argument("no such thing as negative fibonacci number");
    }
    
    // base case: f(0) = 0, f(1) = 1
    if (n <= 1) {
        return n;
    }
    
    int n_1 = 1;
    int n_2 = 0;
    int current = n_1 + n_2;
    
    // iterative case: fib(n) = fib(n-1) + fib(n-2)
    for (int i = 2; i <= n; i++) {
        
        // calculate fib(i)
        current = n_1 + n_2;
        
        // update n_1 and n_2
        n_2 = n_1;
        n_1 = current;
    }

    return current;
}