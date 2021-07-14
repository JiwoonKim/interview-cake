/**
 *  Shuffle the vector of ints in-place
 *  (the shuffle must be uniform
 *   -> each item in the original vector must have the same probability of ending up in each spot in the final vector)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    ** "in-place" == SWAP
 * 
 *    ** UNIFORM: need to know PROBABILITY!!
 * 
 *       ex. 
 *           a) simply swapping each element w/ a random other element
 *              -> this does not give a uniform random distribution
 *                 bcuz some items can be swapped more times than others!
 *          
 *           b) swap those items that have not been swapped before
 *              => Fisher-Yates shuffle (a.k.a. Knuth shuffle)
 * 
 *       cf) most interviewers won't expect you to know the Fisher-Yates shuffle algorithm.
 *           instead, they'll be looking for problem-solving skills to DERIVE the algorithm,
 *           perhaps w/ a couple of hints along the way.
 *           they may also be looking for an understanding of why the naive solution (a) is non-uniform
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  shuffle the vector of ints in-place
*/ 
void shuffle(vector<int>& v) {

    // check for exceptions
    if (v.size() < 2) {
        throw invalid_argument("need at least two items to shuffle");
    }
    
    // shuffle each item in vector
    for (int i = 0, n = v.size(); i < n; i++) {
        
        /** generate random index to swap with
         *  (make sure to range between i to last item
         *   so that items are swapped uniformly
         *   ; no item is likely to be swapped more than others)
        */
        int randomIndex = getRandom(i, n - 1);
        
        // swap item in index i with random item
        if (i != randomIndex) {
            swap(v[i], v[randomIndex]);
        }
    }
}

/**
 *  helper function to get random number between floor and ceiling
 *  (floor <= int <= ceiling)
*/ 
size_t getRandom(size_t floor, size_t ceiling) {
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}