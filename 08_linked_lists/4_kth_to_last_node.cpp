/**
 *  Return the kth to last node in the linked list
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    ** two approaches to the problem
 *       (1) use the length of the list
 *           - find the length of the linked list
 *           - move (length - k) times to find kth to last node
 *           -> two passes: one pass and then another pass
 * 
 *       (2) maintain a k-wide STICK in one walk down the list
 *           - use two pointers to maintain k-wide stick
 *           - move one pointer k nodes from head (right)
 *           - walk both pointers (right & left) together at same speed
 *             -> keeps a distance of k between right & left pointer
 *           - when right points to last node, left points to the kth to last node
 *           -> one pass together
 * 
 *       => at the end of the day, it's actually the same amount of moves
 *          : both O(n) time and O(1) space
 * 
 *    ** using k-wide STICK
 *       : although same time & complexity, I think this technique is worth remembering
 *         -> quite intuitive and may come in handy for other questions!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  return the kth to last node in the linked list
 */
LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head) {
    
    // exception case
    if (k < 0) {
        throw invalid_argument("impossible to find negative or 0th to last node");
    }
    
    // store size of linked list (number of nodes)
    size_t listLength = 0;
    
    // iterate over linked list to find size
    LinkedListNode* current = head;
    
    while (current) {
        
        // count node
        listLength++;
        
        // move pointer to next node
        current = current -> next_;
    } 
    
    // exception case
    if (listLength < k) {
        throw invalid_argument("kth to last node is out of bounds");
    }
    
    // calculate the number of passes to make to reach kth node number
    size_t numberOfPassesToMake = listLength - k;
    
    // iterate over linked list to find node with kth node number
    current = head;
    size_t numberOfPassesMade = 0;
    
    while (numberOfPassesMade != numberOfPassesToMake) {
        
        // move pointer to next node
        current = current -> next_;
        
        // increment count of passes made
        numberOfPassesMade++;
    }

    // return kth to last node
    return current;
}