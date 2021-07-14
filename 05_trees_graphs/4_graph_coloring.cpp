/**
 *  Color all the nodes in the graph using the colors 
 * 
 *  Time Complexity: O(N + M) -> N = nodes, M = edges
 *  Space Complexity: O(D) -> max of degree (= number of colors used)
 * 
 *  * What I learned:
 *    
 *    1) Graph Coloring
 *       - if D is max degree of graph, (D + 1) colors are necessary to create legal coloring scheme
 * 
 *    ** define class of graph
 *       - take a good look at how a graph class is structured!
 *       - use it as reference /example for future
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class GraphNode {
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor) {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const {
        return !color_.empty();
    }

    const string& getColor() const {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color) {
        color_ = color;
    }
};

/**
 *  create a valid coloring for the graph
*/ 
void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors) {
    
    if (graph.empty()) {
        throw invalid_argument("graph has no nodes");
    }
    
    if (colors.empty()) {
        throw invalid_argument("there are no colors");
    }
    
    // color each graph node
    for (GraphNode* graphNode : graph) {
        
        // check neighbors' colors
        unordered_set<GraphNode*> neighbors = graphNode -> getNeighbors();
        
        // throw exception if loop exists (node's neighbor is itself)
        if (neighbors.count(graphNode) > 0) {
            throw invalid_argument("legal coloring is impossible when loop exists in graph");
        }
        
        // create an illegal color list
        unordered_set<string> illegalColors;
        
        // insert neighbors' colors to illegal color list
        for (GraphNode* neighborGraph : neighbors) {
            
            // collect neigbors' colors
            if (neighborGraph -> hasColor()) {
                
                illegalColors.insert(neighborGraph -> getColor());
            }
        }
        
        // find available color to use
        for (auto color : colors) {
            
            if (illegalColors.count(color) == 0) {
                
                // set the color for the graph using available colors
                graphNode -> setColor(color);
                break;
            }
        }
    }
}