/**
 *  Determine if the input code is valid
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    ** use unordered set to check if something is within a group
 *       : define members of group within set
 *         -> simply check if that key exists in set or not
 * 
 *    ** use unordered map to create matches
 *       : opener (key) -> closer (match)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  determine if the input code is valid
 */

bool isValid(const string &code) {

    // return true is code is empty
    if (code.length() == 0) {
        return true;
    }

    // predefine opener and closers
    unordered_set<char> openers {
        '(', '{', '['
    };
    unordered_set<char> closers {
        ')', '}', ']'
    };
    
    // predefine opener and closer pairs (opener -> closer)
    unordered_map<char, char> CloserMatchOfOpener {
        make_pair('(', ')'),
        make_pair('{', '}'),
        make_pair('[', ']')
    };

    // create stack to match openers and closers
    stack<char> s;

    // iterate over all the characters in the input string
    for (char letter : code) {

        // if openers
        if (openers.count(letter) > 0) {

            // push into stack
            s.push(letter);
        }
        // if closer
        else if (closers.count(letter) > 0) {

            // if stack is empty,
            if (s.empty()) {

                // no matching opener to closer
                return false;
            }

            //if letter (closer) does not match opener at top
            char openerToMatch = s.top();
            if (CloserMatchOfOpener[openerToMatch] != letter) {

                // they are not properly nested
                return false;
            }

            // if all is well
            s.pop();
        }
    }

    // if stack is not empty at the end of the string,
    if (!s.empty()) {

        // string is missing a closer
        return false;
    }

    // all is well
    return true;
}