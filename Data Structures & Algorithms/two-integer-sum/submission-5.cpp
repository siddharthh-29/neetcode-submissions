class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>pairings;
        for(int i=0;i<nums.size();i++){
            pairings.push_back({nums[i],i});
        }
        sort(pairings.begin(),pairings.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(pairings[i].first+pairings[j].first==target){
                if(pairings[i].second<pairings[j].second)return {pairings[i].second,pairings[j].second};
                else return {pairings[j].second,pairings[i].second};
            }
            else if(pairings[i].first+pairings[j].first>target){
                j--;
            }
            else i++;
        }
        return {};
    }
};
