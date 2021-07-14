/**
 *  Implement a queue using two stacks
 * 
 *  Time Complexity: O(m) -> m = number of push operations
 *  Space Complexity: O(m)
 * 
 *  * Stuck Point:
 *     - found solution to reverse stack by moving all items to other stack each time for push & pop operation
 *       -> items move back and forth from one stack to other EVERYTIME for operation
 *     (1) but could not figure how to improve from that solution
 *     (2) got wrong w/ calculating the time complexity: is actually O(m^2) in above solution
 *       : bcuz for each push / pop operation, have to move entire items
 *         -> O(m) for each operation -> O(m^2) in total
 * 
 *  ** Untangled Hints: 
 *     (1) hint: "What if we didn't move things back to stack1 after putting them on stack2?"
 *         => focus on the bottleneck of the problem: 
 *            - moving back and forth for each operation
 * 
 *     (2) count the time cost PER ITEM instead of per operation (enqueue or dequeue)
 * 
 *  * What I learned:
 * 
 *    ** how to implement queue using two stacks
 * 
 *    ** error types
 *       (1) runtime_error
 *       (2) invalid_argument
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  implement a queue using two stacks
 */

class QueueTwoStacks
{
private:
    stack<int> inStack_;
    stack<int> outStack_;

public:

    // enqueue method
    void enqueue(int item) {
        
        // push onto inStack
        inStack_.push(item);
    }

    // dequeue method
    int dequeue() {
        
        // if outStack is empty,
        if (outStack_.empty()) {
            
            // empty the current inStack and fill outStack in reverse order
            while (!inStack_.empty()) {

                int item = inStack_.top();
                inStack_.pop();
                outStack_.push(item);
            }
        }
        
        // throw error if queue is empty
        if (outStack_.empty()) {
            throw runtime_error("Can't dequeue from empty queue!");
        }
        
        // pop out front value (top from outStack)
        int front = outStack_.top();
        outStack_.pop();
        
        return front;
    }
};