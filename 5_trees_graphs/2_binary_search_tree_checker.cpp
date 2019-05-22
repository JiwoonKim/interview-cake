/**
 *  Determine if the tree is a valid binary search tree
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 *  -> O(log n) if binary search tree is balanced
 * 
 *  * What I learned:
 * 
 *    ** Binary Search Tree
 *       : binary tree that suffices (left Subtree < Node < right Subtree) condition
 * 
 *       ** check if BST or not
 *          -> simply checking if smaller or larger than immediate parent is NOT ENOUGH
 *          -> bcuz grandchild or great descendent somewhere could violate BST condition
 *          => use UPPER BOUND and LOWER BOUND to check if node is in correct spot
 * 
 *    ** Space Complexity of DFS / BFS
 *       - DFS: uses memory proportional to the DEPTH of the tree
 *       - BFS: uses memory proportional to the BREADTH of the tree
 *              -> can double each time it gets one level deeper
 * 
 *       * if the binary tree is BALANCED,
 *         - DFS: depth = log2(n + 1) => O(log n) space
 *         - BFS: breadth = half of n => O(n) space
 *  
 *       ** DFS: O(log n) ~ O(n) space
 *       ** BFS: O(n) space (even when balanced)    
 *       
 *       => DFS is likely to be more space-efficient than BFS
 * 
 *    3) define custom data structure (class or struct)
 * 
 *    4) can return MULTIPLE bool values using &&
 *       -> 참고) recursive version code below
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  defined custom data stucture class to put in stack for DFS
 *  (consists of node ptr, min and max for range it can be in
 *   -> range: min < ptr -> value_ < max )
*/ 
class NodeRange {
public:
    const BinaryTreeNode* ptr;
    int min;
    int max;
    
    // constructor
    NodeRange(const BinaryTreeNode* ptr, int min, int max) :
        ptr(ptr),
        min(min),
        max(max)
    {
    }
};

/**
 *  determine if the tree is a valid binary search tree
 *  (use DFS to traverse each node and check whether it is in the proper range or not
 *   -> 1. check current node is in range (if invalid, not binary search tree)
 *   -> 2. then, calculate ranges for left and right child nodes and push them to stack to check later)
*/ 
bool isBinarySearchTree(const BinaryTreeNode* root) {
    
    // exit if tree is empty
    if (root == nullptr) {
        throw invalid_argument("tree is empty");
    }
    
    // traverse the nodes by DFS
    stack<NodeRange> s;
    int min = numeric_limits<int>::min();
    int max = numeric_limits<int>::max();
    NodeRange rootNode = NodeRange(root, min, max);
    s.push(rootNode);

    while (!s.empty()) {
        
        // get current node
        const BinaryTreeNode* curPtr = s.top().ptr;
        int curMin = s.top().min;
        int curMax = s.top().max;
        s.pop();
        
        // check node is in proper range
        int curValue = curPtr -> value_;
        if (curMin >= curValue || curValue >= curMax) {
            // if not in proper range,
            return false;
        }
        
        // calculate min and max range for childs and push them to stack
        int mid = curValue;
        if (curPtr -> left_) {
            NodeRange next = NodeRange(curPtr -> left_, curMin, mid);
            s.push(next);
        }
        
        if (curPtr -> right_) {
            NodeRange next = NodeRange(curPtr -> right_, mid, curMax);
            s.push(next);
        }
    }
    // if all is well, 
    return true;
}

/**
 *  recursive version of same solution (DFS)
*/ 
bool isBinarySearchTree(const BinaryTreeNode* node, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max()) {
    
    // exit if tree is empty
    if (node == nullptr) {
        throw invalid_argument("node is empty");
    }
    
    // check node is in proper range
    int curValue = node -> value_;
    if (min >= curValue || curValue >= max) {
        // if not in proper range,
        return false;
    }
        
    // calculate min and max range for childs and push them to stack
    int mid = curValue;
    
    bool isRightBST = true;
    bool isLeftBST = true;
    if (node -> left_) {
        isLeftBST = isBinarySearchTree(node -> left_, min, mid);
    }
        
    if (node -> right_) {
        isRightBST = isBinarySearchTree(node -> right_, mid, max);
    }

    // if all is well, 
    return (isRightBST && isLeftBST);
}