/**
 *  Implement a new class MaxStack with a method getMax() that returns the largest element in the stack
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(m) -> m = number of operations performed on stack
 * 
 *  * What I learned:
 * 
 *    ** check emptyness before pop & top operations
 *       -> make sure stack is NOT EMPTY BEFORE pop / top operations
 * 
 *    ** Other solutions (comparison)
 *       
 *       (1) additional stack to store max values (the solution coded below)
 *           -> adds functionality to push & pop methods in order to save time for getMax method
 *           -> require additional space O(m)
 *           -> time cost in push & pop instead of getMax + space cost
 *           => optimized for fast getMax method
 * 
 *       (2) iterate over all elements in stack to find max value
 *           -> adds functionality to getMax method and does not add anything to push & pop methods
 *              -> useful if push & pop operations > getMax operations
 *           -> can also save space costs (no additional stack) but has tradeoff of time cost (O(n))
 *           => optimized for fast push & pop methods
 * 
 *       => Be able to COMPARE space & time complexity tradeoffs by considering WHAT IS IMPORTANT
 *          : sometimes the first step in algorithm design is deciding WHAT WE'RE OPTIMIZING FOR
 *            -> start by considering the EXPECTED CHARACTERISTICS OF THE INPUT
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  implement a new class MaxStack with a method getMax()
 *  that returns the largest element in the stack
 *  (use the built-in stack class)
 */

class MaxStack {
private:
    stack<int> stack_;
    stack<int> maxesStack_;
public:

    // push method
    void push(int item) {
        
        // push the item into stack
        stack_.push(item);
        
        // update max value
        if (maxesStack_.empty() || item >= maxesStack_.top()) {
            maxesStack_.push(item);
        } 
    }

    // pop method
    int pop() {
        
        // pop the item from the stack
        int popped = stack_.top();
        stack_.pop();
        
        // pop the max value if it is the popped item
        if (!maxesStack_.empty() && popped == maxesStack_.top()) {
            maxesStack_.pop();
        }
        return popped;
    }

    
    // method to return the largest element in the stack
    int getMax() const {
        
        // return largest element in the stack
        return maxesStack_.top();
    }
};