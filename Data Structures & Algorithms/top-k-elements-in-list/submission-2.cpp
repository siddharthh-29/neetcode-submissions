class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>pairings;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(i==n-1 || nums[i]!=nums[i+1]) {
                pairings.push_back({cnt,nums[i]});
                cnt=1;
            }
            else {
                cnt++;
            }
        }
        vector<int>ans;
        sort(pairings.begin(),pairings.end());
        reverse(pairings.begin(),pairings.end());
        for(int i=0;i<k;i++){
            ans.push_back(pairings[i].second);
        }
        return ans;
    }
};
