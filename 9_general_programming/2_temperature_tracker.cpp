/**
 *  Implement functions to track the max, min, mean, and mode
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(1)
 * 
 *  ** What I learned:
 *  
 *     * OPTIMIZE
 *       - initially, had the idea of using map to track (temp, occurences) which is O(n) space
 *       - when PROMPTED w/ QUESTION if I could optimize space to O(1),
 *         I immediately knew I had to find a different way to track occurences
 *       - so I took advantage of the temp range (0, 110) and used that instead of hash map
 * 
 *       => This might not have been obvious to me if I wasn't asked the question
 *          "Can You Optimize space to O(1)"
 *          bcuz in actual interviews you may not be given the bottleneck explicitly
 *          but instead asked to find any ways to optimize (like open question)
 * 
 *     ** practice to FIND OPTIMIZATION POINTS
 *        EVEN AFTER THE PROBLEM HAS BEEN SOLVED
 *        (learn try to take the problem ONE STEP FURTHER by trying to find any further optimization points)
 * 
 * 
 *       cf) I also contemplated a bit on whether this is a better solution
 *           mainly bcuz checking 110 values seemed big
 *           but actually, I would only have to check the inserted temp's occurence only
 *           and only keep track of 110 values
 *           this, still feels big to maintain memory of 110 values
 * 
 *           => BUT REMEMBER THAT O(1000) < O(n) (more efficient) IN THEORY!
 *              (well, as long as n has possibility to become really big)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  class to track max, min, mean, and mode
*/
class TempTracker {
private:
    int occurences[111] = {0,};
    int max_temp = 0;
    int min_temp = 110;
    int sum = 0;
    int totalCount = 0;
    int mode = 0;
    
public:
    void insert(int temperature) {
        occurences[temperature]++;
        max_temp = max(max_temp, temperature);
        min_temp = min(min_temp, temperature);
        sum += temperature;
        totalCount++;
        if (occurences[temperature] > occurences[mode]) {
            mode = temperature;
        }
    }

    int getMax() const {
        return max_temp;
    }

    int getMin() const {
        return min_temp;
    }

    double getMean() const {
        if (totalCount > 0 && sum > 0) {
            return (double) sum / (double) totalCount;
        }
        return 0.0;
    }

    int getMode() const {
        return mode;
    }
};