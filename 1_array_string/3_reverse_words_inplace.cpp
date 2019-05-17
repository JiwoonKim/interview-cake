/**
 *  Given a string, reverse the order of words in-place
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point:
 *     - could not figure how to swap words w/ different lengths
 * 
 *  ** Untangled Hints: consider simpler problem as sub-solution
 *     
 *     cf) even if it's inefficient, just do it
 *        - simply swapping first and last words
 *        -> requires scooting over all chars in-between: O(n^2) time
 * 
 *     ** use a simpler problem as sub-solution
 *        
 *        "Solve a simpler version of the problem to see if that gets us closer to a solution for the original problem"
 * 
 *        - reverse the characters instead of the words (solution to simpler problem)
 *        - see if that can help get closer to the original problem (it puts all the words in correct spot but w/ each wrod backwards!)
 *        - if it does, use it as a strategy and then go further on to solve the problem (now reverse each word)
 * 
 * 
 *  * What I Learned:
 * 
 *    ** use a simpler version of the problem to see if that gets us closer to a solution for the original problem
 *       - using a simpler version of the problem does not mean shortening the problem or using simpler examples
 *       - instead, it means to use the solution to a simpler version as a strategy to resolve a certain issue within the original problem
 *       => use a simpler version to reach a sub-solution to the problem
 *       
 *    2) parsing a string by words
 *       - use start pointer to denote start index of a word
 *       - use for loop to find end index of a word ( i to find end of word)
 *         - for loop iterates until i <= str.length (equals also!) to also check end of string
 *         - use condition (i == str.length() || str[i] == ' ')
 *           - initiate manipulation when fulfilled
 *         - then, (i - 1) indicates actual end index
 *      - update start pointer for new word
 * 
 */
#include <string>
using namespace std;

/**
 *  reverse all the characters in the message first. 
 *  This put all the words in the correct spots, but with the characters in each word backward. 
 *  To get the final answer, reverse the characters in each word.
 */

void reverseWords(string& str) {

    if (str.empty()) {
        return;
    }

    // reverse the entire string first
    reverseChars(str, 0, str.length() - 1);

    // reverse each word in the string
    int startIndex = 0;

    // iterate until string terminator (i <= n) to find end of words
    for (int i = 0, n = str.length(); i <= n; i++) {
        
        // if end of word, initiate manipulation
        if (i == n || str[i] == ' ') {

            // reverse chars in word
            int endIndex = i - 1;
            reverseChars(str, startIndex, endIndex);

            // update startIndex
            startIndex = i + 1;
        }
    }
}

/**
 *  helper function to reverse chars in string from start to end
*/
void reverseChars(string& str, int startIndex, int endIndex) {

    while (startIndex < endIndex) {

        // swap chars in startIndex and endIndex
        char temp = str[startIndex];
        str[startIndex] = str[endIndex];
        str[endIndex] = temp;

        // update indexes closer to middle
        startIndex++;
        endIndex--;
    }
}