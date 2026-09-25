class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            int dis=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        int cnt=0;
        vector<vector<int>>ans;
        while(cnt<k){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
            cnt++;
        }
        return ans;
    }
};
