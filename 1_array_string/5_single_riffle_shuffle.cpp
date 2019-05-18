/**
 *  Determine whether the shuffled deck is a single riffle of two other halves half1 and half2.
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    1) how handy short-circuit evaluation is
 *       
 *       -> ex. if (h1 != end1 && *s == *h1)
 *          : check first if half1 pointer is at the end (no remaining elements to check in half1)
 *            and if sure, then proceed to check further conditions
 * 
 *       -> makes my code cleaner and organized (as well as my thought process)
 *       -> helps to avoid missing edge cases!
 * 
 */

#include <vector>
using namespace std;

/**
 *  check if the shuffled deck is a single riffle of the halves
 */
 bool isSingleRiffle(const vector<int>& half1, 
                     const vector<int>& half2, 
                     const vector<int>& shuffledDeck) {
    
    // check for clearly wrong cases
    if (shuffledDeck.size() != half1.size() + half2.size()) {
        return false;
    }
    
    auto h1 = half1.begin();
    auto h2 = half2.begin();
    auto s = shuffledDeck.begin();
    
    auto end1 = half1.end();
    auto end2 = half2.end();
    auto end_s = shuffledDeck.end();
    
    // check if top in shuffled Deck matches ones in top of half1 or half2
    while (s < end_s) {
        
        // if top in shuffled Deck matches top of half1
        if (h1 != end1 && *s == *h1) {
            h1++;
        } 
        // or matches top of half2
        else if (h2 != end2 && *s == *h2) {
            h2++;
        } 
        // if does not match any, return false
        else {
            return false;
        }
        // increment point to top of shuffled Deck
        s++;
    }
    
    // if all matches, return true
    return true;
}