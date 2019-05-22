/**
 *  Determine if the tree is superbalanced 
 *  (made-up property = difference in the depth of any two leaf nodes <= 1)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  - traverse through tree while keeping track of the depth as we go
 *  - when reached a leaf, check depth and for condition superbalanced by comparison
 * 
 *  * What I learned:
 *  
 *    ** BFS vs DFS
 *       -> while both worst-case time and space costs are the same,
 *          DFS + short-circuit could result in a quickier solution
 *          (use a traversal that will hit leaves as quickly as possible)
 * 
 *      -> since DFS generally hits leaves before BFS, take advantage of DFS + short-circuit
 * 
 *      => be able to EXPLAIN WHY we used BFS/DFS over the other!
 * 
 *    ** use DFS in an ITERATIVE form using a stack
 *       -> same as BFS but w/ stack instead!
 * 
 *    ** define class of binary tree
 *       - take a good look at how a binary tree class is structured!
 *       - use it as reference /example for future
 * 
 *    3) careful of pointers!
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode() {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value) {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value) {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

/**
 *  determine if the tree is superbalanced (DFS solution)
*/ 
bool isBalanced(const BinaryTreeNode* treeRoot) {
      
    // an empty tree is superbalanced since there are no leaves
    if (treeRoot == nullptr) {
        return true;
    }

    // keep track of min and max depth of leaf nodes
    int minDepth = numeric_limits<int>::max();
    int maxDepth = 0;
    
    // traverse the given binary tree by DFS
    stack<pair<const BinaryTreeNode*, int>> s;
    s.push(make_pair(treeRoot, 0));
    
    while (!s.empty()) {
        
        // pop the current node
        const BinaryTreeNode* curNode = s.top().first;
        int curLevel = s.top().second;
        s.pop();
        
        // if current node is leaf node,
        if (!curNode -> left_ && !curNode -> right_) {
            
            // update max and min depth
            minDepth = min(minDepth, curLevel);
            maxDepth = max(maxDepth, curLevel);
            
            // check if goes against superbalanced condition
            if (maxDepth - minDepth > 1) {
                return false;
            }
        }
        
        // if left node exists, push left node into stack
        if (curNode -> left_) {
            s.push(make_pair(curNode -> left_, curLevel + 1));
        }
        
        // if right node exists, push right node into stack
        if (curNode -> right_) {
            s.push(make_pair(curNode -> right_, curLevel + 1));
        }
    }
    
    // if leaf nodes so far have not gone against superbalanced condition,
    return true;
}