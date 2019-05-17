/**
 *  Merge two sorted arrays into one sorted array
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    1) take advantage of short-circuit evaluation
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
vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    if (myVector.empty() && alicesVector.empty()) {
        return myVector;
    }
    
    if (myVector.empty()) {
        return alicesVector;
    }
    
    if (alicesVector.empty()) {
        return myVector;
    }
    
    // combine the sorted vectors into one large sorted vector
    vector<int> merged;
    
    // compare the two vectors until at least one is empty
    auto i = myVector.begin();
    auto j = alicesVector.begin();
    
    auto end1 = myVector.end();
    auto end2 = alicesVector.end();
    
    while (i != end1 && j != end2) {
        
        // push smaller element into merged vector
        if (*i < *j) {
            merged.push_back(*i);
            i++;
        } else {
            merged.push_back(*j);
            j++;
        }
    }
    
    // push the remaining elements into the merged vector
    while (i != end1) {
        merged.push_back(*i);
        i++;
    }
    while (j != end2) {
        merged.push_back(*j);
        j++;
    }

    return merged;
}
