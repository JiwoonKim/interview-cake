/**
 *  Merge meeting ranges
 * 
 *  Time Complexity: O(n log n)
 *  Space Complexity: O(1)
 * 
 *   * Stuck Point:
 *     (1) could not figure how to compare the ranges: even if brute force, how to compare?
 *     (2) after finding that we can use sort, got wrong in comparing cases and updating merged meetings
 * 
 *  ** Untangled Hints: 
 *     (1) use a simple example to understand what the problem is
 *         : if needed, even draw the problem
 *         -> shows how to approach the problem
 *     (2) only need to compare WHETHER the ranges OVERLAP OR NOT
 *         : ranges either overlap or not
 *           -> overlap cases: a. (1, 3), (2, 3)
 *                             b. (2, 3), (1, 3): same but need to compare differently (other direction from a)
 *                             c. (1, 5), (2 ,3)
 *                             d. (1, 5), (5, 7)
 *           => can simplify overlapping cases by using SORT
 *              : this way, can eliminate unnecessary comparing
 * 
 *  * What I learned:
 *    
 *    ** use a simple example to understand what the problem is
 *      
 *    ** how to MERGE RANGES
 *       - first, SORT the ranges by start points in increasing order
 *         -> this way, can get rid of work of comparing a start point to another start point
 *       - then, check if (merged end point < new range's start point) to see if OVERLAPS or not
 *         -> if overlaps, update the max end point between the two (cases: overlap, touch, include whole) 
 *         -> else, insert new range since they are separate ranges (no overlap)
 * 
 *       => use SORT + OVERLAP condition checking
 * 
 *    3) be careful that you should UPDATE the values not include new ranges each time
 * 
 */

#include <bits/stdc++.h>
using namespace std;

/**
 *  helper function to sort meetings 
 *  by start time and end time in increasing order
 */
bool cmp(const Meeting& u, const Meeting& v) {
   if (u.getStartTime() == v.getStartTime()) {
      return u.getEndTime() < v.getEndTime();
   }
   return u.getStartTime() < v.getStartTime();
}
/**
 *  merge meeting ranges
 */
vector<Meeting> mergeRanges(const vector<Meeting>& meetings) {
    // 
    if (meetings.size() <= 1) {
        return meetings;
    }
    
    // sort meeting by start time and then end time
    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), cmp);
    
    // create vector to store merged meetings
    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings.front());
    
    // iterate over all meetings and merge them
    for (const Meeting& meeting : sortedMeetings) {
        
        // get the last merged eeting time
        Meeting& lastMergedMeeting = mergedMeetings.back();
    
        //check if the two meetings overlap
        if (meeting.getStartTime() <= lastMergedMeeting.getEndTime()) {
            
            // extend last merged meeting time (if necessary)
            int lateEndTime = max(lastMergedMeeting.getEndTime(), meeting.getEndTime());
            lastMergedMeeting.setEndTime(lateEndTime);
        }
        else {
            // add new meeting to vector since they do not overlap
            mergedMeetings.push_back(meeting);
        }
    }
  
  // return merged vector
  return mergedMeetings;
}