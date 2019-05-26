/**
 *  R
 * 
 *  Time Complexity: O(n)
 *  Space Complexity: O(n)
 * 
 *  * What I learned:
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