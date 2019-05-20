/**
 *  Sort an unsorted array of scores in less than O(nlogn) time 
 * 
 *  Time Complexity: O(n) 
 *  Space Complexity: O(n)
 * 
 *  (if highestPossibleScore (k) is not treated as constant,
 *   O(n + k) time & O(n + k) space )
 * 
 *  * What I learned:
 * 
 *    ** Counting
 *       : count number of each items
 * 
 *       - common pattern in time-saving algorithms
 *         -> often gets you O(n) runtime, but at the expense of adding O(n) space
 *       
 *       - implementation:
 *         - define an unordered map or vector (=> counts)
 *           : keys/indices -> items from input, 
 *             values -> number of time the item appears
 *         - populate counts: O(n)
 * 
 *       => useful:
 *          - generate a sorted vector in O(n) time
 *          - find item that appears the most times
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  sort unsorted array in O(n) time using COUNTING method
*/
vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore) {
    vector<int> sortedScores;
    
    // use hash table to improve access time to scores
    vector<int> scoreCounts(highestPossibleScore + 1, 0);
    
    // include all scores into hash table
    for (auto score : unorderedScores) {
        scoreCounts[score]++;
    }
    
    // iterate possible scores from highest scores to lowest score
    for (int i = highestPossibleScore; i >= 0; i--) {
        
        // if score exists, push into sortedScores
        while (scoreCounts[i]--) {
    
            sortedScores.push_back(i);
        }
    }

    return sortedScores;
}
