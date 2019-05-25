/**
 *  Implement a new class MaxStack with a method getMax() that returns the largest element in the stack
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    ** check emptyness before pop & top operations
 *       -> make sure stack is NOT EMPTY BEFORE pop / top operations
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