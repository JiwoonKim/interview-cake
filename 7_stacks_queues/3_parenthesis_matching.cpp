/**
 *  Find the position of the matching closing parenthesis
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  find the position of the matching closing parenthesis
 */
size_t getClosingParen(const string& sentence, size_t openingParenIndex) {

    // throw errors for exception cases
    if (sentence.length() == 0) {
        throw invalid_argument("string is empty");
    }
    
    if (openingParenIndex >= sentence.length()) {
        throw invalid_argument("index of opening parentheis is beyond the scope of the string");
    }
    
    // create stack to check parenthesis matches
    int stackCount = 0;
    
    // iterate over string starting from the opening parenthesis index
    for (int i = openingParenIndex, n = sentence.length(); i < n; i++) {
        
        char letter = sentence[i];
        
        // if opening parenthesis, 
        if (letter == '(') {
            
            // add to stack count
            stackCount++;
            
        }
        // if closing parenthesis,
        else if (letter == ')') {
            
            // pop from stack count
            stackCount--;
            
            // check if match for thespecified opening parenthesis
            if (stackCount == 0) {
                return i;
            }
        }
        
    }
    
    // if no match was found, throw exception error    
    throw invalid_argument("no match in sentence");
}