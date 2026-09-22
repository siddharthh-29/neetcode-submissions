class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>final;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    final.push_back({nums[i],nums[l],nums[r]});
                    while(l<nums.size()-1 && nums[l]==nums[l+1])l++;
                    l++;
                    while(r>0 && nums[r-1]==nums[r])r--;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    while(r>0 && nums[r-1]==nums[r])r--;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    while(l<nums.size()-1 && nums[l]==nums[l+1])l++;
                    l++;
                }
            }
        }
        return final;
    }
};
