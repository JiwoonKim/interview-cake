/**
 *  Find the shortest route in the network between the two users
 * 
 *  Time Complexity: O(N + M)
 *  Space Complexity: O(N)
 * 
 *  * What I learned:
 * 
 *    ** Backtracking to retrieve path
 *       - if record each entire path for each node -> O(n^2) space complexity
 *       - instead, record only BEFORE node and recover path using a BACKTRACKING function
 * 
 *    ** Define/clarify Properties of graph BEFORE diving into algorithm
 *       - is it directed or undirected ?
 *       - is it weighted or unweighted ?   
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  helper function to recover path taken (backtracking)
*/ 
vector<string> recoverPath(const unordered_map<string, string>& paths,
                           const string& startNode, const string& endNode) {
    
    vector<string> recoveredPath;
    
    // start from end node 
    string current = endNode;
    
    // recover the path by retrieving the before nodes of each node
    while (!current.empty()) {
        recoveredPath.push_back(current);
        current = paths.find(current)->second;
    }
    
    // reverse the recovered path so that it is start -> end
    reverse(recoveredPath.begin(), recoveredPath.end());
    
    return recoveredPath;
}

/**
 *  find the shortest route in the network between the two users
*/ 
vector<string> getPath(const unordered_map<string, vector<string>>& graph,
                       const string& startNode, const string& endNode)
{
    // throw error if start of end does not exist in network
    if (graph.count(startNode) == 0) {
        throw invalid_argument("Start node is not in graph");
    }
    if (graph.count(endNode) == 0) {
        throw invalid_argument("End node is not in graph");
    }
    
    /** create a unordered map to check visited nodes
     *  and also track the path (node before)
    */ 
    unordered_map<string, string> visited;
    
    // create queue for BFS
    queue<string> q;
    
    // check and push startNode to queue
    visited.emplace(startNode, "");
    q.push(startNode);
    
    
    // BFS to find the shortest route
    while (!q.empty()) {
        
        // get current node
        string current = q.front();
        q.pop();
        
        // check if arrived at destination
        if (current == endNode) {
            return recoverPath(visited, startNode, endNode);
        }
        
        // iterate over connected nodes
        vector<string> connectedNodes = graph.find(current)->second;
        
        for (string connectedNode : connectedNodes) {
            
            // if unvisited node,
            if (visited.count(connectedNode) == 0) {
                
                // check node and record path (node before)
                visited.emplace(connectedNode, current);
                
                // push connected node to queue
                q.push(connectedNode);
            }
        }
    }

    // if there is no path, return empty path
    return  vector<string>();
}