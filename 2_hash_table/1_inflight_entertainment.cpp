/**
 *  Determine if there exists a pair of ints (in vector) which sum equals the given int
 *  + make sure that the same int is not used in a pair
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
 * 
 *    ** be careful when returning values w/ for loop
 *       -> could end up returning void if not constructed carefully
 *       => solution: always have a return statement after the loop
 *                    - construct it as return true when condition satisfied, and after loop return false
 *                      or the other way around
 * 
 *                    ex. for (...)
 *                          if (...)
 *                              return true 
 *                        return false // return statement after loop
 * 
 *    2) use map/set for constant lookup time
 *       -> always ask yourself, right from the start: "Can I save time by using an unordered map/set?"
 * 
 *    ** check pairs in single loop
 *       - instead of first storing all elements in map/set and then checking each element for its match in map/set (=> two sequential loops),
 *       - "check pairs while adding to map/set (=> in single loop)""
 *         -> take advantage that "finding pairs is bi-directional"
 *            (ex. (1, 3) -> can find pair from 1: findOther(1) = 3 
 *                                      or from 3: findOther(3) = 1
 *             => either way results in finding a single pair      )
 * 
 *       ** loop over elements once ("check match && store those w/ no match to check later in map/set")
 *          - if (match exists in collection) -> return true
 *          - else -> store for checking later (if there is a match, it will be called on later elements)
 * 
 *       => this prevents pairs with same element used twice (element, sameElement)
 *          (if duplicates (two elements w/ same value), 
 *           then one will be stored in collection 
 *           and the other will be outside, checking if there is duplicate inside collection)
 *          : ensures that the pair is duplicates and not the same element
 * 
 *          cf) if want to allow same elements to be used in pair, just add simple condition
 *              - if (findOther(element) == element || match exists in collection) -> true
 *              - else -> store for checking later (if there is a match, it will be called on later elements)
 */

#include <bits/stdc++.h> 
using namespace std;

/**
 *   determines whether sum of two different movieLengths equals flightLength or not
 *   - 1) first put all movies into multiset)
 *   - 2) checks if movies is half the flight length (= second movie has same time)
 *        -> have to make sure the first movie and second movie are different ones
 *   - 3) if two movies are to be different lengths, 
 *        -> check if there is movie that's sum equals flight length
 *   
 *   => while this does works, the code for making sure the same movie is not used is bit tedious ㅠㅜ
 *      (use two sequential loops + check for same length movies)
 */

/**
 *  function improved by checking for matches WHILE adding to sets (= one single loop)
 *  -> more clean code in preventing pairs of same element
*/
bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    
    // check for clearly empty cases
    if (flightLength < 2 || movieLengths.size() < 2) {
        return false;
    }
    
    // where movies that do not have a match YET are stored to check later
    unordered_set<int> secondMovies;
    
    // check whether each movie has a match
    for (auto firstMovieLength : movieLengths) {
        
        int secondMovieLength = flightLength - firstMovieLength;
        
        // check if there is a match in previous cases (secondMovies)
        if (secondMovies.count(secondMovieLength) > 0) {
            return true;
        }
        
        // if no match, store into secondMovies to check later
        secondMovies.insert(firstMovieLength);
    }
    // if all movies are checked and no match, 
    return false;
}