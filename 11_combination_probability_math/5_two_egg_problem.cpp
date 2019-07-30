/**
 *  Given two eggs, find the highest floor an egg can be dropped from without breaking, 
 *  with as few drops as possible.
 *  (the building has a total of 100 floors)
 * 
 *  Time Complexity: O(1)
 *  Space Complexity: O(1)
 * 
 *  * Stuck Point: couldn't figure how to optimize further from 19 drops
 * 
 *    - SOLUTIONS I came up w/:
 * 
 *    (1) level up by 1
 *        : start from bottom and level floor by 1s
 *        -> at most, 99 drops using 1 egg
 * 
 *    (2) binary search
 *        : use first egg in binary approach to reduce range
 *          if egg breaks, use second egg to level up by 1 in that range
 *        -> at most, 50 drops using 2 eggs
 *           (1 binary drop + 24 level up drops)
 *        
 *        * problem: large difference btw the first egg drop numbers and second egg drop numbers in worst cases
 *          => need a solution to balance this out
 * 
 *    (3) skip 25 floors at a time
 *        : instead of binary searching (where the number of skips changes each time),
 *          skip floors uniformly by using first egg to check each +25 floors from bottom up
 *          if egg breaks, use second egg to level up by 1 in that range
 *        -> at most, 27 drops using 2 eggs
 *           (3 skip drops + 24 level up drops)
 * 
 *    (4) skip 10 floors at a time
 *        : use first egg to check each +10 floors
 *          if egg breaks, use second egg to level up by 1 in that range 
 *        -> at most, 19 drops using 2 eggs
 *           (10 drops + 9 level up drops)
 * 
 *  ** Untangled Hints: 
 *     1) look at what happens w/ that strategy each time the first egg does not break
 *        : how does the worst case total number of drops change?
 *          -> the worst case total number of drops INCREASES BY ONE EACH TIME the first egg doesn't break         
 *             
 *             ex) first egg: 10th floor break (1 drop) -> second egg: 9 level ups (9 drops) => max: 10 drops
 *                 first egg: 20th floor break (2 drops)-> second egg: 9 level ups (9 drops) => max: 11 drops
 *                 first egg: 30th floor break (3 drops)-> second egg: 9 level ups (9 drops) => max: 12 drops
 *                 ...
 *                 first egg: 100th floor break (10 drops)-> second egg: 9 level ups (9 drops) => max: 19 drops
 * 
 *          => since the number of drops of the first egg increases if it does not break,
 *             the TOTAL NUMBER of drops INCREASES each time the first egg doesn't break
 *     
 *     2) how to keep the total number of drops to remain constant regardless of where the first egg breaks?
 *        : since we can't change the +1 of number of drops of the first egg for each time it doesn't break,
 *          -> we should instead REDUCE -1 the number of drops of second egg for each time the first egg doesn't break
 *          => REDUCE THE NUMBER OF LEVEL UP DROPS of second egg -1 each time
 *             ; reduce the number of FLOORS the first egg SKIPS by 1 (second egg drop 개수 = number of floors to skip)
 * 
 *          => use TRIANGULAR SERIES to calculate the first set of floors to skip
 *             -> 대칭을 이루게끔: (1 + n floors) -> (2 + n-1 floors) + ... + (n + 1 floor)
 *             -> skip 해야 할 floor들을 다 합치면: 100 = n floors + n-1 floors + ... + 1 floor
 *             => n = 13.56 => 14 floors! 
 * 
 *     ** SOLUTION: skip 14, 13, ..., 1 floors at a time
 *      
 *        - first egg: 14th floor break (1 drop) -> second egg: 13 level ups (13 drops) => max: 14 drops
 *        - first egg: (+13 =) 27th floor break (2 drops)-> second egg: 12 level ups (12 drops) => max: 14 drops
 *        - first egg: (+12 =) 39th floor break (3 drops)-> second egg: 11 level ups (11 drops) => max: 14 drops
 *          ...
 *        - first egg: (+5 =) 95th floor break (10 drops)-> second egg: 4 level ups (4 drops) => max: 14 drops
 *        
 *        => wherever first egg breaks, the total number of drops of both eggs remains constant at 14 drops
 * 
 * 
 *  ** What I learned:
 * 
 *     * to optimize / find the problem of current solution
 *       -> write down the how the outcome is for each step in solution
 * 
 *          ex) first egg: 10th floor break (1 drop) -> second egg: 9 level ups (9 drops) => max: 10 drops
 *              first egg: 20th floor break (2 drops)-> second egg: 9 level ups (9 drops) => max: 11 drops
 *              first egg: 30th floor break (3 drops)-> second egg: 9 level ups (9 drops) => max: 12 drops
 *              ...
 *              first egg: 100th floor break (10 drops)-> second egg: 9 level ups (9 drops) => max: 19 drops
 * 
 *     ** MATH and LOGIC leaning problem solving
 *        ex. shuffling cards & rolling dice problems
 * 
 *     ** creating my own definition of function (type of arguments & return values까지 정해서 설계)
 *        and test cases
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  find the highest floor an egg can be dropped from without breaking, 
 *  with as few drops as possible
*/
int findHighestFloor(vector<int> eggStateAtFloors) {

    int cur_floor = 0;
    
    // calculate first number of floors to drop egg (use quadratic formula; 근의 공식)
    int skip_floor_num = ceil(-1 + sqrt((float) (1 + 8 * eggStateAtFloors.size())) / 2);

    // drop first egg until it breaks
    while (cur_floor <= eggStateAtFloors.size() && eggStateAtFloors[cur_floor + skip_floor_num]) {
        /** drop the egg at next floor
         * (starting from skip_floor_num floor)
        */ 
        cur_floor += skip_floor_num;

        // decrease number of floors to skip by 1
        skip_floor_num--;
    }
    
    // drop second egg to find highest floor
    while (eggStateAtFloors[cur_floor + 1]) {
        cur_floor += 1;
    }
    
    /** add 1 to final result 
     *  (since the eggStateAtFloors[0] = 1st floor)
    */
    return cur_floor + 1;
}


// custom test case
int main(void) {
    // define test case 1: highest floor at 99
    vector<int> eggStateAtFloors1 = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    };
    // define test case 2: highest floor at 35
    vector<int> eggStateAtFloors2 = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0
    };
    // use function to test results
    cout << findHighestFloor(eggStateAtFloors1);
    cout << findHighestFloor(eggStateAtFloors2);
}