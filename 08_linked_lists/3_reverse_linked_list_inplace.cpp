/**
 *  Reverse the linked list in place
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    ** different approaches depending on constraints
 *       (1) if can modify original linked list input
 *           -> reverse in-place: O(n) time and O(1) space
 *       (2) if must keep original linked list input (cannot modify)
 *           -> use stack to reverse linked list: O(n) time & space
 * 
 *       => important to ask WHETHER YOU CAN MODIFY INPUT OR NOT
 *          
 *    2) clean up code
 *      - original: 
 *        if (!headOfList || !headOfList -> next_) { return headOfList;} // for exception cases
 *        while (true) { ... if (current == nullptr) { break;} }         // break condition specified inside loop
 *      - clean-up version:
 *        while (current) { ... }
 *        -> this checks exceptions cases & creates condition for loop (instead of break condition)
 *        => much more cleaner!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  reverse the linked list in place
 */
LinkedListNode* reverse(LinkedListNode* headOfList) {
    
    // keep pointers to hold current and previous nodes
    LinkedListNode* current = headOfList;
    LinkedListNode* before = nullptr;
    
    // reverse the links of each nodes
    while (current) {
        
        // hold on to the next node temporarily
        LinkedListNode* tempHoldNext = current -> next_;
        
        /** reverse the order for current node
         *  (current node points to prev node)
        */ 
        current -> next_ = before;
        
        /** update before and current 
         *  ()
        */ 
        before = current;
        current = tempHoldNext;
    }

    return before;
}