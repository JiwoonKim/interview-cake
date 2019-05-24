/**
 *  Generate all permutations of the input string
 * 
 *  Time Complexity: O(n!)
 *  Space Complexity: O(n!)
 * 
 *  * What I learned:
 * 
 *    ** How to create String Permutations
 * 
 *       (1) get all POSSIBLE PERMUTATIONS for all chars EXCEPT LAST LETTER
 *       (2) PUT the LAST CHAR in ALL POSSIBLE POSITIONS for each of the above permutations
 *      
 *       ex. cats -> cat의 모든 permutation에다가 사이사이 s를 넣은 모든 경우 구하기
 *           cat -> ca의 모든 permutation에다가 사이사이 t를 넣은 모든 경우 구하기 => Tca, cTa, caT, Tac, aTc, acT
 *           ca -> c의 모든 permutation에다가 사이사이 a를 넣은 모든 경우 구하기 => Ca, aC
 *           a -> a의 모든 permutation은 a 문자 그대로! (BASE CASE)
 *         
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  generate all permutations of the input string
 */


// generate all permutations of the input string
unordered_set<string> getPermutations(const string& inputString) {
    
    // create set to store permutations
    unordered_set<string> permutations;
    
    // BASE CASE: string is one letter or empty
    if (strLength <= 1) {
        
        // return a set that only contains the input string
        permutations.insert(inputString);
        return permutations;
    }
    
    int strLength = inputString.length();

    /** RECURSIVE CASE: 
     *  get the permutations by using the permutations of the string except the last char
     *  -> put the last char in all the possible positions within the permutations of above
    */ 
    string stringExceptLastChar = inputString.substr(0, strLength - 1);
    char lastChar = inputString[strLength - 1];
    
    // retrieve all the permutations of the string except the last char
    unordered_set<string> permutationsExceptLastChar = getPermutations(stringExceptLastChar);
    
    // create new permutations by positioning the last char in each of the above permutations
    for (auto eachPermutation : permutationsExceptLastChar) {
        
        // add the last char in all possible positions
        for (int i = 0, n = eachPermutation.length(); i <= n; i++) {
            
            // create a new permuation (including last char in pos)
            string newPermutation = eachPermutation.substr(0, i) + lastChar + eachPermutation.substr(i);
        
            // insert new permutation into set
            permutations.insert(newPermutation);
        }
    }
    

    return permutations;
}

/** 
 *  tests
 */ 
const lest::test tests[] = {
    CASE("empty string") {
        const unordered_set<string> expected {""};
        auto actual = getPermutations("");
        EXPECT(actual == expected);
    },
    CASE("one character string") {
        const unordered_set<string> expected {"a"};
        auto actual = getPermutations("a");
        EXPECT(actual == expected);
    },
    CASE("two character string") {
        const unordered_set<string> expected {"ab", "ba"};
        auto actual = getPermutations("ab");
        EXPECT(actual == expected);
    },
    CASE("three character string") {
        const unordered_set<string> expected {"abc", "acb", "bac", "bca", "cab", "cba"};
        auto actual = getPermutations("abc");
        EXPECT(actual == expected);
    },
    CASE("four character string") {
        const unordered_set<string> expected {"stca", "scta", "scat", "tsca", "csta", "csat", "tcsa", "ctsa", "cast", "tcas", "ctas", "cats", "stac", "satc", "sact", "tsac", "astc", "asct", "tasc", "atsc", "acst", "tacs", "atcs", "acts"};
        auto actual = getPermutations("cats");
        EXPECT(actual == expected);
    },
};

int main(int argc, char** argv) {
    return lest::run(tests, argc, argv);
}