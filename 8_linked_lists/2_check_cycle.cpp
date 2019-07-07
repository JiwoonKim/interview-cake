/**
 *  Check if the linked list contains a cycle
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    ** Two Runners approach to check cycle exists
 *       : keep two pointers to nodes (runners)
 *         - slowRunner: moves one node at a time
 *         - fastRunner: moves two nodes at a time
 *       => if linked list has a cycle, fastRunner will catch up with slowRunner
 *          if no cycle, fastRunner reaches the end of list
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  check if the linked list contains a cycle
 */
bool containsCycle(const LinkedListNode* firstNode) {
    
    // if linked list is empty, no cycle
    if (!firstNode) {
      return false;
    }
    
    // create two pointers to traverse through list in different speeds
    const LinkedListNode* fastRunner = firstNode;
    const LinkedListNode* slowRunner = firstNode;
    
    // traverse two runners through list
    while (true) {
        
        // if any runner reaches end of linked list
        if (!slowRunner -> next_ || !fastRunner -> next_ -> next_) {
            break;
        }
        
        // move fast runner and slow runner to next node
        slowRunner = slowRunner -> next_;
        fastRunner = fastRunner -> next_ -> next_;
        
        // if fast and slow runner meet at some point
        if (fastRunner == slowRunner) {
            // there is cycle
            return true;
        }
    }
     
    // there are no cycles
    return false;
}