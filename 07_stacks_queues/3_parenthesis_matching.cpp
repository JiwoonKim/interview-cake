/**
 *  Find the position of the matching closing parenthesis
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(1)
 * 
 *  * What I learned:
 * 
 *    1) the trick to many "parsing" questions is to use a stack 
 *       : to track which brackets/phrases/etc are "open" as you go
 * 
 *    2) if there is only one type of opening & closing, can utilize simple COUNT instead of using a stack
 *       -> saves space
 * 
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