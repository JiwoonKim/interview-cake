/**
 *  Find the 2nd largest item in the binary search tree
 * 
 *  Time Complexity: O(n)
 *  -> if BST is balanced, O(log n)
 *  
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *     (1) got wrong with the cases of where the second largest item could be
 *         -> didn't catch the case where rightmost item (largest item) could have left child or left subtree
 *     (2) even after catching the case (after code failed), got stuck in ORGANIZING THE CASES
 *         -> knew that the largest would be the rightmost,
 *            but divided the cases from the start where root node has right node or not...
 *            -> messed up there...bcuz complicated cases I couldn't organize
 * 
 *  ** Untangled Hints: 
 *     (1) breaking down into CASES
 *     (2) stick to the SIMPLIFY, SOLVE, and ADAPT strategy
 *         -> stick to that SIMPLIFIED VERSION (first largest = rightmost)
 *            and WORK FROM THERE (DON'T OVER COMPLICATE IT!!!)
 *         
 *         1) rightmost node has left subtree -> rightmost of that subtree is answer!
 *         2) rightmost node does not have left subtree -> parent of that subtree is that answer!
 * 
 * 
 *  * What I learned:
 * 
 *    ** stick to the SIMPLIFY, SOLVE, and ADAPT strategy
 *       ; don't over complicate the problem
 * 
 *       ** take advantage of using ~NOT to clean up complicated if-else conditions
 * 
 *          ex. instead of if (current -> right_)
 *                             if (current -> right_ -> right_)
 *                                  move
 *                             else if (current -> right_ left_) ...
 *              simplify with if (current -> right && !current -> right -> right) ...
 * 
 *          => condition 뒤집어서 실행하여 코드 정리가 가능한지 살펴보기!
 * 
 *    ** Traversing Binary Search Tree 
 *       -> node can have left and right child
 *       => check if should go left or right by giving conditions of the CASES
 *       
 *       ** when finding rightmost or leftmost node,
 *          KEEP MOVING to the right/left and use conditions to break or go other way depending on the situation/cases 
 *          (밑에 코드 참고)
 * 
 *    ** CONST POINTERS
 *       : can modify the pointer itself (the address value; what object the pointer is pointing to),
 *         but cannot modify the dereferenced value
 * 
 *       ex. const int* ptr = &num1;
 *           -> ptr = &num2; // 가능
 *           -> *ptr = 5;    // 불가능
 * 
 *      => know well since const pointers are commonly used for trees/graphs
 *         (to traverse the tree)
 * 
 *    ** Don't try to return pointers as return values
 *       -> seriously, it gets really complicated and you don't have to do that...
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  helper function to find the largest value in the given tree (subtree)
*/ 
int findLargestValue(const BinaryTreeNode* rootNode) {
    
    const BinaryTreeNode* current = rootNode;
    
    while (current -> right_) {
        
        current = current -> right_;
    }
    return current -> value_;
}

/**
 *  find the second largest item in the binary search tree
*/ 
int findSecondLargest(const BinaryTreeNode* rootNode) {

    // skip invalid cases
    if (rootNode == nullptr || (!rootNode->left_ && !rootNode->right_)) {
        throw invalid_argument("Tree must have at least 2 nodes");
    }
    
    // track a pointer to traverse tree
    const BinaryTreeNode* current = rootNode;
    
    // traverse to the RIGHT until breakpoints
    while (true) {
        
        const BinaryTreeNode* rightChild = current -> right_;
        const BinaryTreeNode* leftChild = current -> left_;
        
        /** CASE 1: rightmost node does not have childs at all
         *  => the parent of the rightmost is the 2nd largest
        */ 
        if (rightChild && (!rightChild -> left_ && !rightChild -> right_)) {
            
            /** STOP traversal 
             *  (current = parent of largest => 2nd largest)
            */ 
            break;
        }
        /** CASE 2: rightmost node has left child
         *          (current = largest)
         *  => the rightmost node of the left child is the 2nd largest
        */ 
        else if (!rightChild && leftChild) {
            
            /** find the largest in the left subtree
             *  -> RETURN that value
            */ 
            return findLargestValue(leftChild);
        }
        
        
        // traverse to the right
        current = current -> right_;
    }
    

    // return value of second largest node
    return current -> value_;
}