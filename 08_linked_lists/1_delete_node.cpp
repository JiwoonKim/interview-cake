/**
 *  Delete the input node from the linked list
 *  -> only input is pointer to node to delete
 *     (cannot use link prev node to next next node bcuz cannot access prev node in any way)
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *     (1) could not figure how to delete node (link prev node to next next node) when there is no way to access prev node
 *     (2) got wrong when dealing with edge cases: 
 *         - did not think about case when node to delete is the last node
 *           : prev node would still point to that last node which should be deleted
 *     (3) did not think about potential side-effects and cautionary notes to this solution
 * 
 *  ** Untangled Hints: 
 *     (1) "other than rerouting the previous node's pointer, 
 *         is there another way to skip from the previous pointer's value to the next pointer's value?"
 *     (2) be careful of edge cases and throw exceptions to cases that cannot be handled w/ the solution
 *     (3) make sure to tell the interviewer that in a real system, 
 *         we need to carefully check for the side effects in the rest of the code base
 * 
 *  * What I learned:
 * 
 *    ** IN-PLACE MODIFICATIONS
 *       : modifying values is also a way to delete node
 *       -> useful when have NO ACCESS TO PREV NODE, modify node to delete's value to next node's value
 *       - and then skip over next node's value
 *         : link node to delete (which holds next node's value) to next next node
 *    
 *    ** acknowledge that there are IMPERFECT SOLUTIONS
 *       : cases where you cannot solve due to input constraints
 *       -> the goal is to be able to understand those limits and ask if that is okay
 *       -> further, suggest ways to go around them
 *       => show understanding and THROW ERRORS IN THOSE CASES!!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

/**
 *  delete the input node from the linked list
 */
void deleteNode(LinkedListNode* nodeToDelete) {
    
    LinkedListNode* nextNode = nodeToDelete -> next_;
    
    // if node to delete is last node,
    if (!nextNode) {

        // throw exception error
        throw invalid_argument("can't delete the last node with this technique!");
    }
    
    /** replace node to delete's value w/ next node's value
     *  (scoot next value to current node)
    */ 
    nodeToDelete -> intValue_ = nextNode -> intValue_;
    
    // link current node to next next node
    nodeToDelete -> next_ = nextNode -> next_;
    
    // delete next node
    delete nextNode;
}