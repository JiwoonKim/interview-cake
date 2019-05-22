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
 * 
 *      -> since DFS generally hits leaves before BFS, 
 *         take advantage of DFS + short-circuit
 * 
 *      => be able to EXPLAIN WHY we used BFS/DFS over the other!
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
bool isBalancedByDFS(const BinaryTreeNode* treeRoot) {
      
    // an empty tree is superbalanced since there are no leaves
    if (treeRoot == nullptr) {
        return true;
    }

}

/**
 *  determine if the tree is superbalanced (BFS solution)
*/ 
bool isBalancedByBFS(const BinaryTreeNode* treeRoot) {
      
    // an empty tree is superbalanced since there are no leaves
    if (treeRoot == nullptr) {
        return true;
    }

    // keep track of min and max depth of leaf nodes
    int minDepth = numeric_limits<int>::max();
    int maxDepth = 0;

    // traverse the given binary tree by BFS
    queue< pair<const BinaryTreeNode*, int> > q;
    q.push(make_pair(treeRoot, 0));
    
    while (!q.empty()) {
        
        // pop the current node
        const BinaryTreeNode* curNode = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        // if node is leaf node,
        if (!curNode -> left_ && !curNode -> right_) {
            
            // update min and max depths of leaf nodes
            minDepth = min(minDepth, curLevel);
            maxDepth = max(maxDepth, curLevel);
            
            // check if tree goes against superbalanced condition
            if (maxDepth - minDepth > 1) {
                return false;
            }
        }
        
        // if left node exists, push left node into queue
        if (curNode -> left_) {
            q.push(make_pair(curNode -> left_, curLevel + 1));
        }
        
        // if right node exists, push right node into queue
        if (curNode -> right_) {
            q.push(make_pair(curNode -> right_, curLevel + 1));
        }
    }
    // if leaf nodes so far have not gone against superbalanced condition,
    return true;
}