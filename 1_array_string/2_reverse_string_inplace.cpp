/**
 *  Reverses the string in-place
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  What I learned:
 *  1. use two pointers (left & right) for in-place reverse
 *     - use condition (left < right)
 *     - don't forget to left++ & right--
 *  2. check empty case
 * 
 */

#include <string>
using namespace std;

/**
 *  swaps chars in index1 and index2 within string str
 */
void swap(char& c1, char& c2) {
    int temp = c1;
    c1 = c2;
    c2 = temp;
}

/**
 *  reverse the string in-place 
 *  by swapping outward letters until the middle
 */
void reverse(string& str) {

    if (str.empty()) {
        return;
    }
    
    int leftIndex = 0;
    int rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {

        // swap characters
        swap(str[leftIndex], str[rightIndex]);

        // move towards the middle
        leftIndex++;
        rightIndex--;
    }

}