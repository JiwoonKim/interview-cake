/**
 *  Merge two sorted arrays into one sorted array
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    1) take advantage of short-circuit evaluation
 *      
 *       ** Short-circuit evaluation: when two or more boolean expressions connected with AND are evaluated,
 *                                    and the first expression is false, 
 *                                    program does not even check the next expression
 * 
 *          -> Useful to check for END CASES / EDGE CASES (ex. empty, null, out of indexes)
 * 
 *             ex. if (my != myEnd && (alices == alicesEnd || *my < *alices))
 *                 : check for edge case 1) where pointer equals end of vector (= no remaining elements to check)
 *                   if that passes, check the next conditions
 * 
 *          => beautifully ties up the complicated edge cases together in code and,
 *             ensures that edge cases are checked before doing something that may mess up the system or memory
 * 
 */
#include <vector>
using namespace std;

/**
 *  Merge two sorted arrays into one sorted array
 *  using merge function from merge sort
 *  (compare each element from the beginning and add smaller element to new array
 *   if there is remaining elements in one array, add all of them to back of new array)
*/
vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector) {

    // combine the sorted vectors into one large sorted vector
    vector<int> merged;

    // check for clearly wrong cases
    if (myVector.empty() && alicesVector.empty()) {
        return merged;
    }
    
    // compare the two vectors until at least one is empty
    auto my = myVector.begin();
    auto alices = alicesVector.begin();
    
    auto myEnd = myVector.end();
    auto alicesEnd = alicesVector.end();
    
    // iterate over all elements in myVector and alicesVector
    for (int i = 0, n = myVector.size() + alicesVector.size(); i < n; i++) {

        // push element from myVector to merged (use SHORT-CIRCUIT EVALUATION)
        if (my != myEnd && (alices == alicesEnd || *my < *alices)) {
            merged.push_back(*my);
            my++;
        }
        // push element from alicesVector to merged
        else {
            merged.push_back(*alices);
            alices++;
        }
    }

    // return merged vector
    return merged;
}
