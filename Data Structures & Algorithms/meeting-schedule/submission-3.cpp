/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first<b.first){
            return true;
        }
        else if(a.first==b.first)return a.second<b.second;
        return false;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>>timings;
        for(int i=0;i<intervals.size();i++){
            timings.push_back({intervals[i].start,intervals[i].end});
        }
        sort(timings.begin(),timings.end(),cmp);
        int endTime=timings[0].second;
        for(int i=1;i<intervals.size();i++){
            if(timings[i].first>=endTime){
                endTime=timings[i].second;
            }
            else return false;
        }
        return true;
    }
};
