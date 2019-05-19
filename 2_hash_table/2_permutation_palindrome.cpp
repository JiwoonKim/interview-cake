/**
 *  Determine if a any permutation of the given string is a palindrome
 *  (permutation = ordering set, 
 *   palindrome = same read forward or backwards)
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    ** Using an unordered map is the most common way to improve from a brute force approach
 *       => it should always be your first thought!
 *  
 *    - Was able to approach problem in different ways and compare time & space complexities
 *      a. brute-force method: O(n! * n) time, O(n! * n) space
 *         - make all permuations and check each for palindrome
 *         
 *      b. count number of each alphabet(a-z) in string: O(n) time, O(1) space
 *         - count number of alphabets
 *         - if length of string is odd and only one alphabet has odd number of counts, true
 *         - else if length of string is even and all alphabets have even number of counts, true
 *         - else false
 *      
 *      bb. can also change solution b) by counting and checking in one pass
 * 
 *    ** Use Set instead of Map
 *       : instead of counting how many number of counts for each alphabet,
 *         just need to determine WHETHER alphabet has odd counts OR NOT
 *         -> keep track of alphabets that have odd numbers (do not need to store the actual count)
 *            by using SET to collect alphabets with odd counts (push & pop)
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  determines whether any permutation of string is palindrome
*/
bool hasPalindromePermutation(const string& str) {

    // check for clearly empty cases
    if (str.empty()) {
        return true;
    }

    // use set to keep track of nums w/ no pairs
    unordered_set<char> noPairChars;

    // iterate over string to check alphabet pairs
    for (auto alpha : str) {
        
        // if alphabet has potential pair partner,
        if (noPairChars.count(alpha) > 0) {
            // erase from alphabet from noPairChars
            noPairChars.erase(alpha);
        } else {
            // insert alphabet into noPairChars to pair later
            noPairChars.insert(alpha);
        }
    }

    /** check for number of no paired alphabets
     *  (if more than one unpaired alphabet, cannot be palindrome
     *   : even length of string -> no unpaired alphabets
     *     odd length of string -> only one unpaired alphabet)
    */ 
    if (noPairChars.size() <= 1) {
        return true;
    }
    return false;
}